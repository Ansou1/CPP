//
// ex00.hpp for  in /home/daguen_s/rendu/piscine_cpp_d15/ex00
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Wed Jan 22 09:56:07 2014 daguen_s
// Last update Wed Jan 22 10:59:29 2014 daguen_s
//

#ifndef _EX00_H_
# define _EX00_H_

template<typename T>
void swap(T &a, T &b)
{
  T c = a;
  a = b;
  b = c;
}

template<typename T>
const T &min(const T &a, const T &b)
{
  if (a < b)
    return a;
  return b;
}

template<typename T>
const T &max(const T &a, const T &b)
{
  if (a > b)
    return a;
  return b;
}

template<typename T>
T add(const T &a, const T &b)
{
  T result = a + b;
  return result;
}

#endif /* _EX00_H_ */
