/*
** point.c for point.c in /home/daguen_s/rendu/piscine_cpp_rush1/ex_02
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Sat Jan 11 11:27:34 2014 daguen_s
** Last update Sun Jan 12 06:35:57 2014 daguen_s
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "point.h"
#include "raise.h"

typedef struct
{
  Class			base;
  int			x;
  int			y;
  char			*str;
} PointClass;

static void		Point_ctor(Object* self, va_list *ap)
{
  ((PointClass *)self)->x = va_arg(*ap, int);;
  ((PointClass *)self)->y = va_arg(*ap, int);;
  ((PointClass *)self)->str = NULL;
}

static void		Point_dtor(Object* self)
{
  free(((PointClass *)self)->str);
}

static char const	*Point_to_string_t(Object *self)
{
  char			*res;

  if (self)
    {
      if (!(((PointClass *)self)->base.__name__))
	raise("Can't get Name of Object\n");
      if ((res = malloc(sizeof(*res) * (100 + strlen(((PointClass *)self)->base.__name__)))) == NULL)
	raise("Out of memory.\n");
      sprintf(res,"<%s (%d, %d)>", ((PointClass *)self)->base.__name__, ((PointClass *)self)->x, ((PointClass *)self)->y);
      if (((PointClass *)self)->str)
	free(((PointClass *)self)->str);
      ((PointClass *)self)->str = res;
      return (res);
    }
  else
    raise("Can't find Object data\n");
  return (NULL);
}

static PointClass	_description = {
  { sizeof(PointClass), "Point", &Point_ctor, &Point_dtor, &Point_to_string_t },0, 0, NULL
};

Class* Point = (Class*) &_description;
