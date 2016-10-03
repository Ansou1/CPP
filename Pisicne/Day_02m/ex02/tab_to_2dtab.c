/*
** tab_to_2dtab.c for tab_to_2dtab.c in /home/daguen_s/rendu/piscine_cpp_d02m/ex02
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Thu Jan  9 06:46:03 2014 daguen_s
** Last update Thu Jan  9 07:05:16 2014 daguen_s
*/

#include <stdlib.h>

void tab_to_2dtab(int *tab, int length, int width, int ***res)
{
  int **my_tab;
  int i = 0;
  int j = 0;
  int k = 0;

  my_tab = malloc(width * sizeof(int *));
    while (i < length)
      {
	my_tab[i] = malloc(sizeof(int) * width);
	i++;
      }
  i = 0;
  while (i < length)
    {
      j = 0;
      while (j < width)
        {
          my_tab[i][j++] = tab[k++];
        }
      i++;
    }
  *res = my_tab;
}
