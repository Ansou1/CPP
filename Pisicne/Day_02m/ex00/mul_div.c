/*
** mul_div.c for mul_div.c in /home/daguen_s/rendu/piscine_cpp_d02m/ex00
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Thu Jan  9 06:14:40 2014 daguen_s
** Last update Thu Jan  9 06:25:16 2014 daguen_s
*/

#include <stdio.h>

void add_mul_4param(int first, int second, int *add, int *mul)
{
  *add = first + second;
  *mul = first * second;
}

void add_mul_2param(int *first, int *second)
{
  int	val1;
  int	val2;

  val1 = *first;
  val2 = *second;
  *first = val1 + val2;
  *second = val1 * val2;
}
