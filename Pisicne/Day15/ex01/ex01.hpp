//
// ex01.hpp for  in /home/daguen_s/rendu/piscine_cpp_d15/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Wed Jan 22 10:02:24 2014 daguen_s
// Last update Wed Jan 22 10:59:14 2014 daguen_s
//

#ifndef _EX01_H_
# define _EX01_H_

#include <string.h>

template<typename T>
int compare(const T & a, const T & b)
{
  if (a > b)
    return 1;
  if (a == b)
    return 0;
  return -1;
}

template<>
int compare<const char *>(const char * const & a, const char * const & b)
{
  int res = strcmp(a, b);
  if (res < 0)
    return -1;
  else if (res > 0)
    return 1;
  return 0;
}

#endif /* _EX01_H_ */
