/*
** add.c for add.c in /home/daguen_s/rendu/piscine_cpp_d02m/ex04
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Thu Jan  9 08:43:01 2014 daguen_s
** Last update Thu Jan  9 08:51:39 2014 daguen_s
*/

#include "castmania.h"

int normal_add(int a, int b)
{
  return (a+b);
}

int absolute_add(int a, int b)
{
  a = a < 0 ? -a : a;
  b = b < 0 ? -b : b;
  return (a+b);
}

void exec_add(t_add *operation)
{
  if(operation->add_type == NORMAL)
    operation->add_op.res = normal_add(operation->add_op.a, operation->add_op.b);
  else if(operation->add_type == ABSOLUTE)
    operation->add_op.res = absolute_add(operation->add_op.a, operation->add_op.b);
}
