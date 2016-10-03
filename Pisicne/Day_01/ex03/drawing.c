/*
** drawing.c for drawing in /home/daguen_s/rendu/piscine_cpp_d01/ex03
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Wed Jan  8 15:02:30 2014 daguen_s
** Last update Wed Jan  8 15:22:28 2014 daguen_s
*/

#include "drawing.h"

void draw_square(uint32_t **img, t_point *orig, size_t size, uint32_t color)
{
  size_t i;
  size_t j;

  i = 0;
  while (i < size)
    {
      j = 0;
      while (j < size)
	{
	  img[orig->x + i][orig->y + j] = color;
	  j++;
	}
      i++;
    }
}
