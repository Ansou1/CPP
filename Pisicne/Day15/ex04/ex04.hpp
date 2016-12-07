//
// ex04.hpp for  in /home/daguen_s/rendu/piscine_cpp_d15/ex04
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Wed Jan 22 11:09:25 2014 daguen_s
// Last update Wed Jan 22 13:41:30 2014 daguen_s
//

#ifndef _EX04_H_
# define _EX04_H_

#include <string>

template <typename T>
bool equal(const T &a, const T &b);

template <class T>
class Tester
{
public:
  bool	equal(const T &a, const T &b);
};

template<>
bool Tester<int>::equal(const int &a, const int &b);
template<>
bool Tester<float>::equal(const float &a, const float &b);
template<>
bool Tester<double>::equal(const double &a, const double &b);
template<>
bool Tester<std::string>::equal(const std::string &a, const std::string &b);


template<>
bool equal<int>(const int &a, const int &b);
template<>
bool equal<float>(const float &a, const float &b);
template<>
bool equal<double>(const double &a, const double &b);
template<>
bool equal<std::string>(const std::string &a, const std::string &b);


#endif /* _EX04_H_ */
