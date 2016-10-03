/*
** func_ptr.c for func_ptr.c in /home/daguen_s/rendu/piscine_cpp_d02m/ex03
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Thu Jan  9 07:15:50 2014 daguen_s
** Last update Thu Jan  9 08:03:31 2014 daguen_s
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func_ptr.h"
#include "func_ptr_enum.h"

void print_normal(char *str)
{
  printf("%s\n", str);
}

void print_reverse(char *str)
{
  char	*new_str;
  int	len;
  int	i;

  new_str = strdup(str);
  len = strlen(new_str);
  if(new_str)
    {
      i = 0;
      while (i < len / 2)
	{
	  new_str[i] = str[len - i - 1];
	  new_str[len - i - 1] = str[i];
	  i++;
	}
    }
  print_normal(new_str);
  free(new_str);
}

void print_upper(char *str)
{
  char	*new_str;
  int	len;
  int	i;

  new_str = strdup(str);
  len = strlen(new_str);
  if(new_str)
    {
      i = 0;
      while (i < len)
	{
	  new_str[i] = toupper(new_str[i]);
	  i++;
	}
    }
  print_normal(new_str);
  free(new_str);
}

void print_42(char *str)
{
  str = str;
  print_normal("42");
}

void do_action(t_action action, char *str)
{
  void (*tab[4])(char *);

  tab[PRINT_NORMAL] = print_normal;
  tab[PRINT_REVERSE] = print_reverse;
  tab[PRINT_UPPER] = print_upper;
  tab[PRINT_42] = print_42;
  (*tab[action])(str);
}
