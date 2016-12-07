//
// ex02.hpp for  in /home/daguen_s/rendu/piscine_cpp_d15/ex02
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Wed Jan 22 10:36:29 2014 daguen_s
// Last update Wed Jan 22 10:44:50 2014 daguen_s
//

#ifndef __EX02_HPP__
#define __EX02_HPP__

#include <iostream>

template<typename T>
T	min(T a, T b)
{
  std::cout << "template min" << std::endl;
  if (b < a)
    return (b);
  return (a);
}

int	min(int a, int b)
{
  std::cout << "non-template min" << std::endl;
  if (b < a)
    return (b);
  return (a);
}

template<typename T>
T	templateMin(T *a, int s)
{
  int	i;
  T	res;

  res = a[0];
  i = 1;
  while (i < s)
    {
      res = min<T>(a[i], res);
      i++;
    }
  return (res);
}

int	nonTemplateMin(int *a, int s)
{
  int	i;
  int	res;

  res = a[0];
  i = 1;
  while (i < s)
    {
      res = min(a[i], res);
      i++;
    }
  return (res);
}

#endif
