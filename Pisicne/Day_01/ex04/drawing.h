#ifndef _DRAWING_H_
# define _DRAWING_H_

#include <stdlib.h>
#include <stdint.h>

typedef struct	s_point
{
  unsigned int	x;
  unsigned int	y;
}		t_point;

void draw_square(uint32_t **img, t_point *orig, size_t size, uint32_t color);


#endif /* _DRAWING_H_ */
