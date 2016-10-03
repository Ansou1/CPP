/*
** String.c for string in /home/daguen_s/rendu/piscine_cpp_d03/ex00
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Fri Jan 10 05:59:54 2014 daguen_s
** Last update Sat Jan 11 05:59:59 2014 daguen_s
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
static int empty (String* this);
static int find_s (String* this, const String *str, size_t pos);
static int find_c (String* this, char const* str, size_t pos);
static void insert_c(String * this, size_t pos, char const* str);
static void insert_s(String * this, size_t pos, String const* str);
static int to_int(String * this);
static String* split_s(String* this, char separator);
static char** split_c(String* this, char separator);

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
  this->empty = &empty;
  this->find_s = &find_s;
  this->find_c = &find_c;
  this->insert_s = &insert_s;
  this->insert_c = &insert_c;
  this->to_int = &to_int;
  this->split_s = &split_s;
  this->split_c = &split_c;
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

static int empty (String* this)
{
  if (this != NULL)
    {
      if (this->str != NULL && strlen(this->str) > 0)
	return -1;
      else
	return 1;
    }
  return 1;
}

static int find_s (String* this, const String *str, size_t pos)
{
  size_t i;
  size_t j;

  if (this != NULL && this->str != NULL && str != NULL && str->str != NULL && strlen(str->str) <= strlen(this->str))
    {
      i = 0;
      while (i < pos)
	i++;
      while (i < strlen(this->str))
	{
	  j = 0;
	  while (this->str[i + j] == str->str[j] && j < strlen(str->str))
	    j++;
	  if (j == strlen(str->str))
	    return (i);
	  i++;
	}
    }
  return -1;
}

static int find_c (String* this, char const* str, size_t pos)
{
  size_t i;
  size_t j;

  if (this != NULL && this->str != NULL && str != NULL && strlen(str) <= strlen(this->str))
    {
      i = 0;
      while (i < pos)
	i++;
      while (i < strlen(this->str))
	{
	  j = 0;
	  while (this->str[i + j] == str[j] && j < strlen(str))
	    j++;
	  if (j == strlen(str))
	    return (i);
	  i++;
	}
    }
  return -1;
}

static void insert_c(String * this, size_t pos, char const* str)
{
  size_t i = 0;
  size_t j = 0;

  if (this != NULL && str != NULL)
    {
      if (pos > strlen(this->str))
	return append_c(this, str);
      char *new_str = malloc((strlen(str) + strlen(this->str) + 1) * sizeof(char));
      while (i < pos)
	new_str[i++] = this->str[j++];
      j = 0;
      while (i < pos + strlen(str))
	new_str[i++] = str[j++];
      j = pos;
      while (i < strlen(this->str) + strlen(str))
	new_str[i++] = this->str[j++];
      new_str[strlen(str) + strlen(this->str)] = '\0';
      this->str = new_str;
    }
}

static void insert_s(String * this, size_t pos, String const* str)
{
  if (this != NULL && str != NULL && str->str != NULL)
    insert_c(this, pos, str->str);
}

static int to_int(String * this)
{
  if (this != NULL && this->str != NULL)
    return (atoi(this->str));
  return (0);
}

static String* split_s(String* this, char separator)
{
  if (this != NULL && this->str != NULL)
    {
      char **tab = split_c(this, separator);
      int i = 0;
      int j;

      while (tab[i])
	i++;
      j = i;
      String *split = malloc((i + 1) * sizeof(String));
      i = 0;
      while (i < j)
	{
	  StringInit(&split[i], tab[i]);
	  i++;
	}
      StringInit(&split[i], "");
      return split;
    }
  return NULL;
}

int is_sep(char c, char *sep)
{
  int i;

  i = -1;
  while (sep[++i])
    if (sep[i] == c)
      return (1);
  return (0);
}

int my_count_word(char *str, char *sep)
{
  int i;
  int nbr;

  nbr = 0;
  i = -1;
  while (str[++i])
    if (!is_sep(str[i], sep))
      {
	while (!is_sep(str[i], sep) && str[i + 1])
	  i++;
	nbr++;
      }
  return (nbr);
}

char **str_to_wordtab(char *str, char *sep)
{
  char**tab;
  int i;
  int j;
  int x;
  int z;

  tab = malloc(sizeof(*tab) * (my_count_word(str, sep) + 1));
  j = -1;
  i = -1;
  while (str[++i])
    if (!is_sep(str[i], sep))
      {
	x = i;
	while (!is_sep(str[++i], sep) && str[i] != '\0');
	tab[++j] = malloc(sizeof(**tab) * (i - x + 1));
	z = -1;
	while (++z < i - x)
	  tab[j][z] = str[x + z];
	tab[j][z] = '\0';
	i -= (str[i] == '\0');
      }
  tab[++j] = NULL;
  return (tab);
}

static char** split_c(String* this, char separator)
{
  if (this != NULL && this->str != NULL)
    {
      return (str_to_wordtab(this->str, &separator));
    }
  return NULL;
}
