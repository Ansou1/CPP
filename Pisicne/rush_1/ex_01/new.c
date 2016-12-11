/*
** new.c for new.c in /home/daguen_s/rendu/piscine_cpp_rush1/ex_01
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Sat Jan 11 07:06:15 2014 daguen_s
** Last update Sat Jan 11 08:02:27 2014 daguen_s
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "raise.h"
#include "new.h"
#include "object.h"
#include "point.h"

void *new(Class *class)
{
  Object       *test;

  test = NULL;
  if (class != NULL)
    {
      if (!class->__size__)
	raise("__size__ of class not define\n");
      if ((test = malloc(class->__size__)) == NULL)
	raise("Out of memory\n");
      if (!class->__init__)
	raise("Can find pointeur to init data\n");
      class->__init__(test);
      memcpy(test, class, sizeof(*class));
      return (test);
    }
  else
    raise("Invalid Class\n");
  return (NULL);
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
