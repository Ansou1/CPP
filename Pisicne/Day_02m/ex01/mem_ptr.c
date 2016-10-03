/*
** mem_ptr.c for mem_ptr in /home/daguen_s/rendu/piscine_cpp_d02m/ex01
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Thu Jan  9 06:31:16 2014 daguen_s
** Last update Thu Jan  9 06:44:00 2014 daguen_s
*/

#include <stdlib.h>
#include <string.h>

#include "mem_ptr.h"

void add_str(char *str1, char *str2, char **res)
{
  *res = malloc((strlen(str1) + strlen(str2) + 1) * sizeof(char));
  *res[0] = '\0';
  strcat(*res, str1);
  strcat(*res, str2);
}

void add_str_struct(t_str_op *str_op)
{
  add_str(str_op->str1, str_op->str2, &(str_op->res));
}
