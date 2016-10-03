/*
** main.c for main in /home/daguen_s/rendu/piscine_cpp_d01/ex01
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Wed Jan  8 11:08:33 2014 daguen_s
** Last update Wed Jan  8 13:30:42 2014 daguen_s
*/

#include <stdio.h>
#include <stdlib.h>

void	menger(int, int, int, int);

int	my_atoi(char *str)
{
  int	nbr;

  if (*str == '-')
    return (-my_atoi(str + 1));
  if (*str == '+')
    return (my_atoi(str + 1));
  nbr = 0;
  while (*str >= '0' && *str <= '9')
    nbr = nbr * 10 + (*(str++) - '0');
  return (nbr);
}

int	main(int ac, char **av)
{
  int	square_size;
  int	level;

  if (ac == 3)
    {
      square_size = my_atoi(av[1]);
      level = my_atoi(av[2]);
      if (square_size % 3 != 0 || level > square_size || level < 0)
	return 0;
      else
	menger(square_size, level, 0, 0);
    }
  return 0;
}

