#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "char.h"
#include "new.h"
#include "raise.h"

typedef struct
{
  Class		base;
  char		nbr;
  char		*str;
  Object	*add;
  Object	*sub;
  Object	*mul;
  Object	*div;
  bool		eq;
  bool		gt;
  bool		lt;
} CharClass;

static void	Char_ctor(Object* self, va_list *ap)
{
  char	nbr;

  nbr = va_arg(*ap, int);
  ((CharClass *)self)->nbr = nbr;
  ((CharClass *)self)->str = NULL;
}

static void	Char_dtor(Object* self)
{
  free(((CharClass *)self)->str);
}

static char const	*Char_to_string(Object *self)
{
  char                  *res;

  if (self)
    {
      if (!(((CharClass *)self)->base.__name__))
        raise("Can't get Name of Object\n");
      if ((res = malloc(sizeof(*res) * (100 + strlen(((CharClass *)self)->base.__name__)))) == NULL)
        raise("Out of memory.\n");
      sprintf(res,"%c", ((CharClass *)self)->nbr);
      if (((CharClass *)self)->str)
        free(((CharClass *)self)->str);
      ((CharClass *)self)->str = res;
      return (res);
    }
  else
    raise("Can't find Object data\n");
  return (NULL);
}


static Object *Char_binary_operator_add(const Object *self, const Object *other)
{
  char nbr;

  if (self && other)
    {
      if (!(((CharClass *)self)->base.__name__) && !(((CharClass *)other)->base.__name__))
        raise("Can't get Name of Object\n");
      if (strcmp(((CharClass *)self)->base.__name__,((CharClass *)other)->base.__name__) != 0)
      	raise("Error conflicting type of the operator : Not same type. Check your operators.\n");
      nbr = ((CharClass *)self)->nbr + ((CharClass *)other)->nbr;
      return (new(Char, nbr));
    }
  else
    raise("Bad Object\n");
  return (NULL);
}

static Object *Char_binary_operator_sub(const Object *self, const Object *other)
{
  char nbr;

  if (self && other)
    {
      if (!(((CharClass *)self)->base.__name__) && !(((CharClass *)other)->base.__name__))
        raise("Can't get Name of Object\n");
      if (strcmp(((CharClass *)self)->base.__name__,((CharClass *)other)->base.__name__) != 0)
      	raise("Error conflicting type of the operator : Not same type. Check your operators.\n");
      nbr = ((CharClass *)self)->nbr - ((CharClass *)other)->nbr;
      return (new(Char, nbr));
    }
  else
    raise("Bad Object\n");
  return (NULL);
}

static Object *Char_binary_operator_mul(const Object *self, const Object *other)
{
  char nbr;

  if (self && other)
    {
      if (!(((CharClass *)self)->base.__name__) && !(((CharClass *)other)->base.__name__))
        raise("Can't get Name of Object\n");
      if (strcmp(((CharClass *)self)->base.__name__,((CharClass *)other)->base.__name__) != 0)
      	raise("Error conflicting type of the operator : Not same type. Check your operators.\n");
      nbr = ((CharClass *)self)->nbr * ((CharClass *)other)->nbr;
      return (new(Char, nbr));
    }
  else
    raise("Bad Object\n");
  return (NULL);
}

static Object *Char_binary_operator_div(const Object *self, const Object *other)
{
  char nbr;

  if (self && other)
    {
      if (!(((CharClass *)self)->base.__name__) && !(((CharClass *)other)->base.__name__))
        raise("Can't get Name of Object\n");
      if (strcmp(((CharClass *)self)->base.__name__,((CharClass *)other)->base.__name__) != 0)
      	raise("Error conflicting type of the operator : Not same type. Check your operators.\n");
      if (((CharClass *)other)->nbr == 0 || ((CharClass *)self)->nbr == 0)
	raise("One Object egal to 0\n");
      nbr = ((CharClass *)self)->nbr / ((CharClass *)other)->nbr;
      return (new(Char, nbr));
    }
  else
    raise("Bad Object\n");
  return (NULL);
}

static bool Char_binary_comparator_eq(const Object *self, const Object *other)
{
  if (self && other)
    {
      if (!(((CharClass *)self)->base.__name__) && !(((CharClass *)other)->base.__name__))
        raise("Can't get Name of Object\n");
      if (strcmp(((CharClass *)self)->base.__name__,((CharClass *)other)->base.__name__) != 0)
      	raise("Error conflicting type of the operator : Not same type. Check your operators.\n");
      return (((CharClass *)self)->nbr == ((CharClass *)other)->nbr);
    }
  else
    raise("Bad Object\n");
  return (0);
}

static bool Char_binary_comparator_gt(const Object *self, const Object *other)
{
  if (self && other)
    {
      if (!(((CharClass *)self)->base.__name__) && !(((CharClass *)other)->base.__name__))
        raise("Can't get Name of Object\n");
      if (strcmp(((CharClass *)self)->base.__name__,((CharClass *)other)->base.__name__) != 0)
      	raise("Error conflicting type of the operator : Not same type. Check your operators.\n");
      return (((CharClass *)self)->nbr > ((CharClass *)other)->nbr);
    }
    else
    raise("Bad Object\n");
  return (0);
}

static bool Char_binary_comparator_lt(const Object *self, const Object *other)
{
  if (self && other)
    {
      if (!(((CharClass *)self)->base.__name__) && !(((CharClass *)other)->base.__name__))
        raise("Can't get Name of Object\n");
      if (strcmp(((CharClass *)self)->base.__name__,((CharClass *)other)->base.__name__) != 0)
      	raise("Error conflicting type of the operator : Not same type. Check your operators.\n");
      return (((CharClass *)self)->nbr < ((CharClass *)other)->nbr);
    }
  else
    raise("Bad Object\n");
  return (0);
}


static	CharClass	_description = {
  {sizeof(CharClass), "Char", &Char_ctor, &Char_dtor, &Char_to_string,&Char_binary_operator_add,&Char_binary_operator_sub,&Char_binary_operator_mul,&Char_binary_operator_div,&Char_binary_comparator_eq,&Char_binary_comparator_gt,&Char_binary_comparator_lt}
  ,0,NULL,0,0,0,0,0,0,0};

Class* Char = (Class*) &_description;
