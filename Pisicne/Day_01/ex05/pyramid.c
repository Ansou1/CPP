/*
** pyramid.c for pyramid in /home/daguen_s/rendu/piscine_cpp_d01/ex05
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Wed Jan  8 16:22:39 2014 daguen_s
** Last update Thu Jan  9 06:07:07 2014 daguen_s
*/

#include <stdio.h>
#include <stdlib.h>

int pyramid_path(int size, int **map)
{
  int i = size -1;
  int j = 0;

  while (i > -1)
    {
      j = 0;
      while (j < size -1)
	{
	  map[i - 1][j] += (map[i][j] > map[i][j + 1]) ? map[i][j+1] : map[i][j];
	  j++;
	}
      size--;
      i--;
    }
  return (map[0][0]);
}
