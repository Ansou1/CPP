/*
** ptr_tricks.c for ptr_tricks.c in /home/daguen_s/rendu/piscine_cpp_d02m/ex05
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Thu Jan  9 10:41:17 2014 daguen_s
** Last update Thu Jan  9 11:22:05 2014 daguen_s
*/

#include "ptr_tricks.h"

int get_array_nb_elem(int *ptr1, int *ptr2)
{
  return ptr2 - ptr1;
}

t_whatever *get_struct_ptr(int *member_ptr)
{
  t_whatever	tmp;

  return ((void *)member_ptr - (((void *) &tmp.member - (void *) &tmp)));
}
