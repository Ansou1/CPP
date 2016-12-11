#include <stdio.h>
#include "raise.h"
#include "vertex.h"
#include <stdlib.h>
#include <string.h>

typedef struct
{
  Class			base;
  int			x;
  int			y;
  int			z;
  char			*str;
} VertexClass;

static void		Vertex_ctor(Object* self, va_list *ap)
{
  ((VertexClass *)self)->x = va_arg(*ap, int);
  ((VertexClass *)self)->y = va_arg(*ap, int);
  ((VertexClass *)self)->z = va_arg(*ap, int);
  ((VertexClass *)self)->str = NULL;
}

static void		Vertex_dtor(Object* self)
{
  free(((VertexClass *)self)->str);
}

static char const	*putVertex(Object * self)
{
  char			*res;

  if (self != NULL)
    {
      if (!(((VertexClass *)self)->base.__name__))
	raise("Can't get Name of Object\n");
      if ((res = malloc(sizeof(*res) * (100 + strlen(((VertexClass *)self)->base.__name__)))) == NULL)
	raise("Out of memory.\n");
      sprintf(res, "<%s (%d, %d, %d)>", ((VertexClass *)self)->base.__name__, ((VertexClass *)self)->x, ((VertexClass *)self)->y, ((VertexClass *)self)->z);
      if (((VertexClass *)self)->str)
	free(((VertexClass *)self)->str);
      ((VertexClass*)self)->str = res;
      return (res);
    }
  else
    raise("Can't find Object data\n");
  return (NULL);
}

static			VertexClass _description = {
  { sizeof(VertexClass), "Vertex", &Vertex_ctor, &Vertex_dtor , &putVertex},
  0, 0, 0, NULL
};

Class* Vertex = (Class*) &_description;
