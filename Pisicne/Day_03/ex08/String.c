/*
** String.c for string in /home/daguen_s/rendu/piscine_cpp_d03/ex00
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Fri Jan 10 05:59:54 2014 daguen_s
** Last update Fri Jan 10 10:02:43 2014 daguen_s
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "String.h"

static void assign_s (String *this, String const * str);
static void assign_c (String *this, char const * s );
static void append_s(String* this, String const* ap);
static void append_c(String* this, char const* ap);
static char at(String* this, size_t pos);
static void clear(String* this);
static int size(String* this);
static int compare_s(String *this, const String* str);
static int compare_c(String *this, char const* str);
static size_t copy(String* this, char* s, size_t n, size_t pos);
static const char *c_str (String * this);

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
  this->append_s = &append_s;
  this->append_c = &append_c;
  this->at = &at;
  this->clear = &clear;
  this->size = &size;
  this->compare_s = &compare_s;
  this->compare_c = &compare_c;
  this->copy = &copy;
  this->c_str = &c_str;
}

void StringDestroy(String* this)
{
  if (this != NULL && this->str != NULL)
    {
      if (this->str != NULL)
	free(this->str);
      this->str = NULL;
    }
}

static void assign_s (String *this, String const * str)
{
  if (this != NULL && str != NULL)
    {
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

static void append_s(String* this, String const* ap)
{
  char *new_str;
  int lenght = 1;

  if (this != NULL && ap != NULL)
    {
      if (ap->str != NULL)
	{
	  if (this->str != NULL)
	    lenght += strlen(this->str);
	  lenght += strlen(ap->str);
	  new_str = malloc(lenght * sizeof(char));
	  new_str[0] = '\0';
	  if (this->str != NULL)
	    strcat(new_str, this->str);
	  strcat(new_str, ap->str);
	  free(this->str);
	  this->str = new_str;
	}
    }
}

static void append_c(String* this, char const* ap)
{
  char *new_str;
  int lenght = 1;

  if (this != NULL)
    {
      if (ap != NULL)
	{
	  if (this->str != NULL)
	    lenght += strlen(this->str);
	  lenght += strlen(ap);
	  new_str = malloc(lenght * sizeof(char));
	  new_str[0] = '\0';
	  if (this->str != NULL)
	    strcat(new_str, this->str);
	  strcat(new_str, ap);
	  free(this->str);
	  this->str = new_str;
	}
    }
}

static char at(String* this, size_t pos)
{
  if (this == NULL || this->str == NULL)
    return -1;
  if (strlen(this->str) < pos)
    return -1;
  return this->str[pos];
}

static void clear(String* this)
{
  if (this != NULL)
    if (this->str != NULL)
      this->str[0] = '\0';
}

static int size(String* this)
{
  if (this != NULL)
    {
      if (this->str != NULL)
	return strlen(this->str);
      else
	return -1;
    }
  else
    return -1;
}

static int compare_s(String *this, const String* str)
{
  if (this != NULL && str != NULL)
    {
      if (this->str != NULL && str->str != NULL)
	return (strcmp(this->str, str->str));
    }
  return 0;
}

static int compare_c(String *this, char const* str)
{
  if (this != NULL && str != NULL)
    {
      if (this->str != NULL)
	return (strcmp(this->str, str));
    }
  return 0;
}

static size_t copy(String* this, char* s, size_t n, size_t pos)
{
  size_t i;
  size_t j;

  if (this != NULL && this->str != NULL && s != NULL)
    {
      i = pos;
      j = 0;
      while (i < strlen(this->str) && j < n)
	s[j++] = this->str[i++];
      return j;
    }
  return 0;
}

static char const* c_str (String * this)
{
  if (this != NULL)
    return (this->str);
  else
    return NULL;
}
