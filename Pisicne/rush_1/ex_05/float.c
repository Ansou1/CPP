#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "float.h"
#include "new.h"
#include "raise.h"

typedef struct
{
  Class		base;
  float		nbr;
  char		*str;
  Object	*add;
  Object	*sub;
  Object	*mul;
  Object	*div;
  bool		eq;
  bool		gt;
  bool		lt;
} FloatClass;

static void	Float_ctor(Object* self, va_list *ap)
{
  double	nbr;

  nbr = va_arg(*ap, double);
  ((FloatClass *)self)->nbr = (float)nbr;
  ((FloatClass *)self)->str = NULL;
}

static void	Float_dtor(Object* self)
{
  free(((FloatClass *)self)->str);
}

static char const	*Float_to_string(Object *self)
{
  char                  *res;

  if (self)
    {
      if (!(((FloatClass *)self)->base.__name__))
        raise("Can't get Name of Object\n");
      if ((res = malloc(sizeof(*res) * (100 + strlen(((FloatClass *)self)->base.__name__)))) == NULL)
        raise("Out of memory.\n");
      sprintf(res,"%f", ((FloatClass *)self)->nbr);
      if (((FloatClass *)self)->str)
        free(((FloatClass *)self)->str);
      ((FloatClass *)self)->str = res;
      return (res);
    }
  else
    raise("Can't find Object data\n");
  return (NULL);
}


static Object *Float_binary_operator_add(const Object *self, const Object *other)
{
  float nbr;

  if (self && other)
    {
      if (!(((FloatClass *)self)->base.__name__) && !(((FloatClass *)other)->base.__name__))
        raise("Can't get Name of Object\n");
      if (strcmp(((FloatClass *)self)->base.__name__,((FloatClass *)other)->base.__name__) != 0)
      	raise("Error conflicting type of the operator : Not same type. Check your operators.\n");
      nbr = ((FloatClass *)self)->nbr + ((FloatClass *)other)->nbr;
      return (new(Float, nbr));
    }
  else
    raise("Bad Object\n");
  return (NULL);
}

static Object *Float_binary_operator_sub(const Object *self, const Object *other)
{
  float nbr;

  if (self && other)
    {
      if (!(((FloatClass *)self)->base.__name__) && !(((FloatClass *)other)->base.__name__))
        raise("Can't get Name of Object\n");
      if (strcmp(((FloatClass *)self)->base.__name__,((FloatClass *)other)->base.__name__) != 0)
      	raise("Error conflicting type of the operator : Not same type. Check your operators.\n");
      nbr = ((FloatClass *)self)->nbr + ((FloatClass *)other)->nbr;
      return (new(Float, nbr));
    }
  else
    raise("Bad Object\n");
  return (NULL);
}

static Object *Float_binary_operator_mul(const Object *self, const Object *other)
{
  float nbr;

  if (self && other)
    {
      if (!(((FloatClass *)self)->base.__name__) && !(((FloatClass *)other)->base.__name__))
        raise("Can't get Name of Object\n");
      if (strcmp(((FloatClass *)self)->base.__name__,((FloatClass *)other)->base.__name__) != 0)
      	raise("Error conflicting type of the operator : Not same type. Check your operators.\n");
      nbr = ((FloatClass *)self)->nbr * ((FloatClass *)other)->nbr;
      return (new(Float, nbr));
    }
  else
    raise("Bad Object\n");
  return (NULL);
}

static Object *Float_binary_operator_div(const Object *self, const Object *other)
{
  float nbr;

  if (self && other)
    {
      if (!(((FloatClass *)self)->base.__name__) && !(((FloatClass *)other)->base.__name__))
        raise("Can't get Name of Object\n");
      if (strcmp(((FloatClass *)self)->base.__name__,((FloatClass *)other)->base.__name__) != 0)
      	raise("Error conflicting type of the operator : Not same type. Check your operators.\n");
      if (((FloatClass *)other)->nbr == 0 || ((FloatClass *)self)->nbr == 0)
	raise("One Object egal to 0\n");
      nbr = ((FloatClass *)self)->nbr / ((FloatClass *)other)->nbr;
      return (new(Float, nbr));
    }
  else
    raise("Bad Object\n");
  return (NULL);
}

static bool Float_binary_comparator_eq(const Object *self, const Object *other)
{
  if (self && other)
    {
      if (!(((FloatClass *)self)->base.__name__) && !(((FloatClass *)other)->base.__name__))
        raise("Can't get Name of Object\n");
      if (strcmp(((FloatClass *)self)->base.__name__,((FloatClass *)other)->base.__name__) != 0)
      	raise("Error conflicting type of the operator : Not same type. Check your operators.\n");
      return (((FloatClass *)self)->nbr == ((FloatClass *)other)->nbr);
    }
  else
    raise("Bad Object\n");
  return (0);
}

static bool Float_binary_comparator_gt(const Object *self, const Object *other)
{
  if (self && other)
    {
      if (!(((FloatClass *)self)->base.__name__) && !(((FloatClass *)other)->base.__name__))
        raise("Can't get Name of Object\n");
      if (strcmp(((FloatClass *)self)->base.__name__,((FloatClass *)other)->base.__name__) != 0)
      	raise("Error conflicting type of the operator : Not same type. Check your operators.\n");
    return (((FloatClass *)self)->nbr > ((FloatClass *)other)->nbr);
    }
  else
    raise("Bad Object\n");
  return (0);
}

static bool Float_binary_comparator_lt(const Object *self, const Object *other)
{
  if (self && other)
    {
      if (!(((FloatClass *)self)->base.__name__) && !(((FloatClass *)other)->base.__name__))
        raise("Can't get Name of Object\n");
      if (strcmp(((FloatClass *)self)->base.__name__,((FloatClass *)other)->base.__name__) != 0)
      	raise("Error conflicting type of the operator : Not same type. Check your operators.\n");
      return (((FloatClass *)self)->nbr < ((FloatClass *)other)->nbr);
    }
  else
    raise("Bad Object\n");
  return (0);
}


static	FloatClass	_description = {
  {sizeof(FloatClass), "Float", &Float_ctor, &Float_dtor, &Float_to_string,&Float_binary_operator_add,&Float_binary_operator_sub,&Float_binary_operator_mul,&Float_binary_operator_div,&Float_binary_comparator_eq,&Float_binary_comparator_gt,&Float_binary_comparator_lt}
  ,0,NULL,0,0,0,0,0,0,0};

Class* Float = (Class*) &_description;
