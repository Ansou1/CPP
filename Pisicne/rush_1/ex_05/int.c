#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "int.h"
#include "new.h"
#include "raise.h"

typedef struct
{
  Class		base;
  int		nbr;
  char		*str;
  Object	*add;
  Object	*sub;
  Object	*mul;
  Object	*div;
  bool		eq;
  bool		gt;
  bool		lt;
} IntClass;

static void	Int_ctor(Object* self, va_list *ap)
{
  int	nbr;

  nbr = va_arg(*ap, int);
  ((IntClass *)self)->nbr = nbr;
  ((IntClass *)self)->str = NULL;
}

static void	Int_dtor(Object* self)
{
  free(((IntClass *)self)->str);
}

static char const	*Int_to_string(Object *self)
{
  char                  *res;

  if (self)
    {
      if (!(((IntClass *)self)->base.__name__))
        raise("Can't get Name of Object\n");
      if ((res = malloc(sizeof(*res) * (100 + strlen(((IntClass *)self)->base.__name__)))) == NULL)
        raise("Out of memory.\n");
      sprintf(res,"%d", ((IntClass *)self)->nbr);
      if (((IntClass *)self)->str)
        free(((IntClass *)self)->str);
      ((IntClass *)self)->str = res;
      return (res);
    }
  else
    raise("Can't find Object data\n");
  return (NULL);
}


static Object *Int_binary_operator_add(const Object *self, const Object *other)
{
  int nbr;

  if (self && other)
    {
      if (!(((IntClass *)self)->base.__name__) && !(((IntClass *)other)->base.__name__))
        raise("Can't get Name of Object\n");
      if (strcmp(((IntClass *)self)->base.__name__,((IntClass *)other)->base.__name__) != 0)
      	raise("Error conflicting type of the operator : Not same type. Check your operators.\n");
      nbr = ((IntClass *)self)->nbr + ((IntClass *)other)->nbr;
      return (new(Int, nbr));
    }
  else
    raise("Bad Object\n");
  return (NULL);
}

static Object *Int_binary_operator_sub(const Object *self, const Object *other)
{
  int nbr;

  if (self && other)
    {
      if (!(((IntClass *)self)->base.__name__) && !(((IntClass *)other)->base.__name__))
        raise("Can't get Name of Object\n");
      if (strcmp(((IntClass *)self)->base.__name__,((IntClass *)other)->base.__name__) != 0)
      	raise("Error conflicting type of the operator : Not same type. Check your operators.\n");
      nbr = ((IntClass *)self)->nbr + ((IntClass *)other)->nbr;
      return (new(Int, nbr));
    }
  else
    raise("Bad Object\n");
  return (NULL);
}

static Object *Int_binary_operator_mul(const Object *self, const Object *other)
{
  int nbr;

  if (self && other)
    {
      if (!(((IntClass *)self)->base.__name__) && !(((IntClass *)other)->base.__name__))
        raise("Can't get Name of Object\n");
      if (strcmp(((IntClass *)self)->base.__name__,((IntClass *)other)->base.__name__) != 0)
      	raise("Error conflicting type of the operator : Not same type. Check your operators.\n");
      nbr = ((IntClass *)self)->nbr * ((IntClass *)other)->nbr;
      return (new(Int, nbr));
    }
  else
    raise("Bad Object\n");
  return (NULL);
}

static Object *Int_binary_operator_div(const Object *self, const Object *other)
{
  int nbr;

  if (self && other)
    {
      if (!(((IntClass *)self)->base.__name__) && !(((IntClass *)other)->base.__name__))
        raise("Can't get Name of Object\n");
      if (strcmp(((IntClass *)self)->base.__name__,((IntClass *)other)->base.__name__) != 0)
      	raise("Error conflicting type of the operator : Not same type. Check your operators.\n");
       if (((IntClass *)other)->nbr == 0 || ((IntClass *)self)->nbr == 0)
	raise("One Object egal to 0\n");
      nbr = ((IntClass *)self)->nbr / ((IntClass *)other)->nbr;
      return (new(Int, nbr));
    }
  else
    raise("Bad Object\n");
  return (NULL);
}

static bool Int_binary_comparator_eq(const Object *self, const Object *other)
{
  if (self && other)
    {
      if (!(((IntClass *)self)->base.__name__) && !(((IntClass *)other)->base.__name__))
        raise("Can't get Name of Object\n");
      if (strcmp(((IntClass *)self)->base.__name__,((IntClass *)other)->base.__name__) != 0)
      	raise("Error conflicting type of the operator : Not same type. Check your operators.\n");
     return (((IntClass *)self)->nbr == ((IntClass *)other)->nbr);
    }
  else
    raise("Bad Object\n");
  return (0);
}

static bool Int_binary_comparator_gt(const Object *self, const Object *other)
{
  if (self && other)
    {
      if (!(((IntClass *)self)->base.__name__) && !(((IntClass *)other)->base.__name__))
        raise("Can't get Name of Object\n");
      if (strcmp(((IntClass *)self)->base.__name__,((IntClass *)other)->base.__name__) != 0)
      	raise("Error conflicting type of the operator : Not same type. Check your operators.\n");
      return (((IntClass *)self)->nbr > ((IntClass *)other)->nbr);
    }
  else
    raise("Bad Object\n");
  return (0);
}

static bool Int_binary_comparator_lt(const Object *self, const Object *other)
{
  if (self && other)
    {
      if (!(((IntClass *)self)->base.__name__) && !(((IntClass *)other)->base.__name__))
        raise("Can't get Name of Object\n");
      if (strcmp(((IntClass *)self)->base.__name__,((IntClass *)other)->base.__name__) != 0)
      	raise("Error conflicting type of the operator : Not same type. Check your operators.\n");
      return (((IntClass *)self)->nbr < ((IntClass *)other)->nbr);
    }
  else
    raise("Bad Object\n");
  return (0);
}


static	IntClass	_description = {
  {sizeof(IntClass), "Int", &Int_ctor, &Int_dtor, &Int_to_string,&Int_binary_operator_add,&Int_binary_operator_sub,&Int_binary_operator_mul,&Int_binary_operator_div,&Int_binary_comparator_eq,&Int_binary_comparator_gt,&Int_binary_comparator_lt}
  ,0,NULL,0,0,0,0,0,0,0};

Class* Int = (Class*) &_description;
