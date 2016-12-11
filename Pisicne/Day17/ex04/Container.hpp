//
// Container.hpp for  in /home/daguen_s/rendu/piscine_cpp_d17/ex04
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 24 13:25:27 2014 daguen_s
// Last update Fri Jan 24 15:40:07 2014 daguen_s
//

#ifndef _CONTAINER_H_
# define _CONTAINER_H_

#include <iostream>
#include <string>
#include <algorithm>


template <typename T>
void	add(T &b)
{
  b = b + 1;
}

template <typename T>
void	aff(T b)
{
  std::cout << "Valeur : " << b << std::endl;
}

template <typename T, template <class , class > class Container>
class contain
{
  Container<T, std::allocator<T> > c;

public:
  void			push(T t)
  {
    c.push(t);
  }

  void			aff()
  {
    std::for_each(c.begin(), c.end(), &::aff<T>);
  }

  void			add()
  {
    std::for_each(c.begin(), c.end(), &::add<T>);
  }
};

#endif /* _CONTAINER_H_ */
