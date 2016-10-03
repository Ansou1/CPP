/*
** white_rabbit.c for white_rabbit in /home/daguen_s/rendu/piscine_cpp_d01/ex00
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Wed Jan  8 10:52:05 2014 daguen_s
** Last update Wed Jan  8 12:48:09 2014 daguen_s
*/

#include <stdio.h>
#include <stdlib.h>

int	follow_the_white_rabbit(void)
{
  int result;
  int nbr;

  result = 0;
  do
    {
      nbr = (random() % 37) + 1;
      if (nbr == 4 || nbr == 5 || nbr == 6 || (nbr >= 17 && nbr <= 21) ||  nbr == 28)
	printf("gauche\n");
      if (nbr == 13 || nbr == 34 || nbr == 35 || nbr == 36)
	printf("droite\n");
      if ((nbr % 8 == 0) || nbr == 26)
	printf("derriere\n");
      if (nbr == 10 || nbr == 15 || nbr == 23)
	printf("devant\n");
      result = result + nbr;
    } while (result <= 397 && nbr != 1 && nbr != 37);
  printf("LAPIN !!!\n");
  return result;
}

