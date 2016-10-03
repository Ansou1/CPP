/*
** menger.c for menger in /home/daguen_s/rendu/piscine_cpp_d01/ex01
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Wed Jan  8 13:20:52 2014 daguen_s
** Last update Wed Jan  8 13:32:25 2014 daguen_s
*/

#include <stdio.h>
#include <stdlib.h>

void	menger(int square_size, int level, int x, int y)
{
  int	new_square_size;

  if (level > 0)
    {
      new_square_size = square_size / 3;
      printf("%03d %03d %03d\n", new_square_size , new_square_size + x, new_square_size + y);
      menger(new_square_size, level - 1, x, y);
      menger(new_square_size, level - 1, x, y + new_square_size);
      menger(new_square_size, level - 1, x, y + 2 * new_square_size);
      menger(new_square_size, level - 1, x + new_square_size, y);
      menger(new_square_size, level - 1, x + new_square_size, y + 2 * new_square_size);
      menger(new_square_size, level - 1, x + 2 * new_square_size, y);
      menger(new_square_size, level - 1, x + 2 * new_square_size, y + new_square_size);
      menger(new_square_size, level - 1, x + 2 * new_square_size, y + 2 * new_square_size);
    }
}
