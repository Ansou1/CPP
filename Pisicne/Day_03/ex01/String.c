/*
** String.c for string in /home/daguen_s/rendu/piscine_cpp_d03/ex00
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Fri Jan 10 05:59:54 2014 daguen_s
** Last update Fri Jan 10 07:34:27 2014 daguen_s
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "String.h"

static void assign_s (String *this, String const * str);
static void assign_c (String *this, char const * s );

void StringInit(String* this, char const * s)
{
  while (this == NULL)
    this = malloc(sizeof(String));
  if (s == NULL)
    this->str = NULL;
  else
    this->str = strdup(s);
  this->assign_s = &assign_s;
  this->assign_c = &assign_c;
}

void StringDestroy(String* this)
{
  if (this != NULL && this->str != NULL)
    {
      free(this->str);
      this->str = NULL;
    }
}

static void assign_s (String *this, String const * str)
{
  if (this != NULL && str != NULL)
    {
      if (this->str != NULL)
	free(this->str);
      if (str->str != NULL)
	this->str = strdup(str->str);
      else
	this->str = NULL;
    }
}

static void assign_c (String *this, char const * s )
{
  if (this != NULL)
    {
      if (s != NULL)
	this->str = strdup(s);
      else
	this->str = NULL;
    }
}
