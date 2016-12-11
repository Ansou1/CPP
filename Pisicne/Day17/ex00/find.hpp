//
// find.hpp for  in /home/daguen_s/rendu/piscine_cpp_d17/ex00
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 24 09:08:28 2014 daguen_s
// Last update Fri Jan 24 09:19:27 2014 daguen_s
//

#ifndef _FIND_H_
# define _FIND_H_

#include <iostream>
#include <string>
#include <algorithm>

template <typename T>
typename T::iterator	do_find(T &container, int const &value)
{
  return (std::find(container.begin(), container.end(), value));
}

#endif /* _FIND_H_ */
