//
// ex04.cpp for  in /home/daguen_s/rendu/piscine_cpp_d15/ex04
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Wed Jan 22 11:09:52 2014 daguen_s
// Last update Wed Jan 22 13:46:46 2014 daguen_s
//

#include "ex04.hpp"

template<typename T>
bool Tester<T>::equal(const T &a, const T &b)
{
  return (a == b);
}

template<>
bool Tester<int>::equal(const int &a, const int &b)
{
  return (a == b);
}

template<>
bool Tester<float>::equal(const float &a, const float &b)
{
  return (a == b);
}

template<>
bool Tester<double>::equal(const double &a, const double &b)
{
  return (a == b);
}

template<>
bool Tester<std::string>::equal(const std::string &a, const std::string &b)
{
  return (a == b);
}

template<typename T>
bool equal(const T &a, const T &b)
{
  return (a == b);
}

template<>
bool    equal<int>(const int &a, const int &b)
{
  return (a == b);
}

template<>
bool    equal<float>(const float &a, const float &b)
{
  return (a == b);
}

template<>
bool    equal<double>(const double &a, const double &b)
{
  return (a == b);
}

template<>
bool    equal<std::string>(const std::string &a, const std::string &b)
{
  return (a == b);
}

