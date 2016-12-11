#include <stdlib.h>
#include <stdarg.h>

#include "object.h"
#include "iterator.h"
#include "bool.h"
#include "new.h"
#include "raise.h"
#include "array.h"
#include "new.h"
#include "int.h"

typedef struct
{
    Container base;
    Class* _type;
    size_t _size;
    Object** _tab;
} ArrayClass;

typedef struct
{
    Iterator base;
    ArrayClass* _array;
    size_t _idx;
} ArrayIteratorClass;

bool ArrayIterator_eq(ArrayIteratorClass* self, ArrayIteratorClass* other)
{
  if (self != NULL && other != NULL)
    return (self->_idx == other->_idx) ? true : false;
  else
    raise("Bad Object\n");
  return false;
}

bool ArrayIterator_gt(ArrayIteratorClass* self, ArrayIteratorClass* other)
{
  if (self != NULL && other != NULL)
    return (self->_idx > other->_idx) ? true : false;
  else
    raise("Bad Object\n");
  return false;
}

bool ArrayIterator_lt(ArrayIteratorClass* self, ArrayIteratorClass* other)
{
  if (self != NULL && other != NULL)
    return (self->_idx < other->_idx) ? true : false;
  else
    raise("Bad Object\n");
  return false;
}

void ArrayIterator_incr(ArrayIteratorClass* self)
{
  if (self != NULL)
    {
      if (self->_idx < self->_array->_size)
	self->_idx++;
    }
  else
    raise("Bad Object\n");
}

Object* ArrayIterator_getval(ArrayIteratorClass* self)
{
  if (self != NULL)
    {
      if (self->_array)
	return (self->_array->_tab[self->_idx]);
      else
	raise("Bad Object\n");
    }
  else
    raise("Bad Object\n");
}

void ArrayIterator_setval(ArrayIteratorClass* self, ...)
{
  va_list ap;

  if (self != NULL)
    {
      va_start(ap, self);
      self->_array->_tab[self->_idx] = va_new(self->_array->_type, &ap);
    }
  else
    raise("Bad Object\n");
}


void ArrayIterator_ctor(ArrayIteratorClass* self, va_list* args)
{
  self->_array = va_arg(*args, ArrayClass *);
  self->_idx = 0;
  self->base.__getval__ = (getval_t)&ArrayIterator_getval;
  self->base.__setval__ = (setval_t)&ArrayIterator_setval;
  self->base.__incr__ = (incr_t)&ArrayIterator_incr;
}

static ArrayIteratorClass ArrayIteratorDescr = {
    {
        {
            sizeof(ArrayIteratorClass), "ArrayIterator",
            (ctor_t) &ArrayIterator_ctor,
            NULL, /* dtor */
            NULL, /* str */
            NULL, NULL, NULL, NULL, /* add, sub, mul, div */
            (binary_comparator_t) &ArrayIterator_eq,
            (binary_comparator_t) &ArrayIterator_gt,
            (binary_comparator_t) &ArrayIterator_lt,
        },
        (incr_t) &ArrayIterator_incr,
        (getval_t) &ArrayIterator_getval,
        (setval_t) &ArrayIterator_setval,
    },
    NULL,
    0
};

static Class* ArrayIterator = (Class*) &ArrayIteratorDescr;

void Array_dtor(ArrayClass* self)
{
  size_t size;
  size_t i;

  i = 0;
  if (self)
    {
      size = self->_size;
      while (i < size)
	{
	  delete(self->_tab[i]);
	  i = i + 1;
	}
      free(self->_tab);
      self->_type = NULL;
    }
  else
    raise("Bad Object\n");
}

size_t Array_len(ArrayClass* self)
{
  if (self)
    {
      if (self->_size)
	return (self->_size);
      else
	raise("size_t empty\n");
    }
  raise("Bad Object\n");
}

Iterator* Array_begin(ArrayClass* self)
{
  if (self)
    return (new(ArrayIterator, self));
  else
    raise("Bad Object\n");
}

Iterator* Array_end(ArrayClass* self)
{
  ArrayIteratorClass *a;

  if (self)
    {
      a = new(ArrayIterator, self);
      a->_idx = a->_array->_size;
      return ((Iterator *)a);
    }
  raise("Bad Object\n");
  return (NULL);
}

Object* Array_getitem(ArrayClass* self, ...)
{
  size_t index;
  va_list ap;
  size_t i;
  size_t sizeArray;

  if (self)
    {
      va_start(ap, self);
      index = va_arg(ap, size_t);
      i = 0;
      sizeArray = Array_len(self);
      if (index > sizeArray)
	raise("Invalid Index of call : Array_getitem() function\n");
      while (self->_tab[i] && i != index)
	i = i + 1;
      return (self->_tab[i]);
    }
  else
    raise("Bad Object\n");
}


void Array_setitem(ArrayClass* self, ...)
{
  size_t index;
  va_list ap;
  size_t i;
  size_t sizeArray;

  if (self)
    {
      va_start(ap, self);
      index = va_arg(ap, size_t);
      i = 0;
      sizeArray = Array_len(self);
      if (index > sizeArray)
	raise("Invalid Index of call : Array_setitem() function\n");
      while (self->_tab[i] && i != index)
	i++;
      self->_tab[i] = va_new(self->_type, &ap);
    }
  else
    raise("Bad Object\n");
}

void Array_ctor(ArrayClass* self, va_list* args)
{
  size_t	SizeArray;
  void		*type;
  size_t	i;
  Object	**tab;
  va_list	ap;

  if (args)
    {
      SizeArray = va_arg(*args, size_t);
      type = va_arg(*args, Class *);
      i = 0;
      if ((tab = malloc(sizeof(self->_tab) * SizeArray)) == NULL)
	raise("Out of memory\n");
      while (i < SizeArray)
	{
	  va_copy(ap, *args);
	  tab[i] = va_new(type,&ap);
	  i++;
	}
      self->_tab = tab;
      self->_size = SizeArray;
      self->_type = type;
      va_end(*args);
      self->base.__getitem__ = (getitem_t)&Array_getitem;
      self->base.__setitem__ = (setitem_t)&Array_setitem;
      self->base.__len__ = (len_t)&Array_len;
      self->base.__begin__ = (iter_t)&Array_begin;
      self->base.__end__ = (iter_t)&Array_end;
    }
  else
    raise("Can find args data\n");
}

static ArrayClass _descr = {
    { /* Container */
        { /* Class */
            sizeof(ArrayClass), "Array",
            (ctor_t) &Array_ctor, (dtor_t) &Array_dtor,
            NULL, /*str */
            NULL, NULL, NULL, NULL, /* add, sub, mul, div */
            NULL, NULL, NULL, /* eq, gt, lt */
        },
        (len_t) &Array_len,
        (iter_t) &Array_begin,
        (iter_t) &Array_end,
        (getitem_t) &Array_getitem,
        (setitem_t) &Array_setitem,
    },
    NULL, 0, NULL
};

Class* Array = (Class*) &_descr;
