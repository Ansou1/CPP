/*
** String.c for string in /home/daguen_s/rendu/piscine_cpp_d03/ex00
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Fri Jan 10 05:59:54 2014 daguen_s
** Last update Fri Jan 10 06:31:56 2014 daguen_s
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "String.h"

void StringInit(String* this, char const * s)
{
  while (this == NULL)
    this = malloc(sizeof(String));
  if (s == NULL)
    this->str = NULL;
  else
    this->str = strdup(s);
}

void StringDestroy(String* this)
{
  if (this != NULL && this->str != NULL)
    {
      free(this->str);
      this->str = NULL;
    }
}
