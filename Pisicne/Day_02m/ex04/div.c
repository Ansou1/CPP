/*
** div.c for div.c in /home/daguen_s/rendu/piscine_cpp_d02m/ex04
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Thu Jan  9 08:06:27 2014 daguen_s
** Last update Thu Jan  9 10:35:52 2014 daguen_s
*/

#include "castmania.h"

int integer_div(int a, int b)
{
  if (b == 0)
    return 0;
  return (a/b);
}

float decimale_div(int a, int b)
{
  if (b == 0)
    return 0;
  return (a/(float)b);
}

void exec_div(t_div *operation)
{
  if(operation->div_type == INTEGER)
    ((t_integer_op *) operation->div_op)->res = integer_div(((t_integer_op *) operation->div_op)->a, ((t_integer_op *) operation->div_op)->b);
  else if(operation->div_type == DECIMALE)
    ((t_decimale_op *) operation->div_op)->res = decimale_div(((t_decimale_op *) operation->div_op)->a, ((t_decimale_op *) operation->div_op)->b);
}
