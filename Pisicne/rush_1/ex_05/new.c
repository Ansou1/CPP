/*
** new.c for new.c in /home/daguen_s/rendu/piscine_cpp_rush1/ex_01
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Sat Jan 11 07:06:15 2014 daguen_s
** Last update Sat Jan 11 15:31:02 2014 daguen_s
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "raise.h"
#include "new.h"
#include "object.h"
#include "int.h"

void       *new(Class *class, ...)
{
  va_list ap;
  Class*classbk;

  if (class != NULL)
    {
      classbk = class;
      va_start(ap, class);
      return (va_new(classbk, &ap));
    }
  else
    raise("Invalid Class\n");
}

void *va_new(Class *class, va_list *ap)
{
  Object *test;

  if (!class->__size__)
    raise("__size__ of class not define\n");
  if ((test = malloc(class->__size__)) == NULL)
    raise("Out of memory\n");
  memcpy(test, class, sizeof(*class));
  if (!class->__init__)
    raise("Can find pointeur to init data\n");
  class->__init__(test, ap);
  va_end(*ap);
  if (!test)
    raise("Class can't be create\n");
  return (test);
}

void	delete(Object *ptr)
{
  if (ptr != NULL)
    {
      if (((Class*)ptr)->__del__)
	{
	  ((Class*)ptr)->__del__(ptr);
	  free(ptr);
	}
    }
  else
    raise("We can't delete this object\n");
}
