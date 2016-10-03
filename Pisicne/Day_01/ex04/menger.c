/*
** menger.c for menger in /home/daguen_s/rendu/piscine_cpp_d01/ex01
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Wed Jan  8 13:20:52 2014 daguen_s
** Last update Wed Jan  8 16:06:37 2014 daguen_s
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "drawing.h"

uint32_t	add_color_square(int level)
{
  uint32_t	color;
  unsigned char	*data;

  data = (unsigned char *)&color;
  data[0] = 0;
  data[1] = 0xFF / (level);
  data[2] = data[1];
  data[3] = data[1];
  color = (data[3]<<0) | (data[2]<<8) | (data[1]<<16) | (data[0]<<24);
  return color;
}

void	menger(unsigned int **img, int square_size, int level, int x, int y)
{
  int	new_square_size;
  t_point	point;

  if (level > 0)
    {
      new_square_size = square_size / 3;
      point.x = new_square_size + x;
      point.y = new_square_size + y;
      draw_square(img, &point, new_square_size, add_color_square(level));
      menger(img, new_square_size, level - 1, x, y);
      menger(img, new_square_size, level - 1, x, y + new_square_size);
      menger(img, new_square_size, level - 1, x, y + 2 * new_square_size);
      menger(img, new_square_size, level - 1, x + new_square_size, y);
      menger(img, new_square_size, level - 1, x + new_square_size, y + 2 * new_square_size);
      menger(img, new_square_size, level - 1, x + 2 * new_square_size, y);
      menger(img, new_square_size, level - 1, x + 2 * new_square_size, y + new_square_size);
      menger(img, new_square_size, level - 1, x + 2 * new_square_size, y + 2 * new_square_size);
    }
}
