//
// ex03.hpp for  in /home/daguen_s/rendu/piscine_cpp_d15/ex03
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Wed Jan 22 10:51:47 2014 daguen_s
// Last update Wed Jan 22 11:06:22 2014 daguen_s
//

#ifndef __EX03_HPP__
# define __EX03_HPP__

#include <iostream>

template<typename T>
void	foreach(T *a, void (&func)(const T&), int t)
{
  for(int i = 0; i < t; i++)
    func(a[i]);
}

template<typename T>
void	print(const T& a)
{
  std::cout << a << std::endl;
}

#endif
