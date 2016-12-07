//
// ex06.hpp for  in /home/daguen_s/rendu/piscine_cpp_d15/ex06
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Wed Jan 22 16:37:25 2014 daguen_s
// Last update Thu Jan 23 09:13:53 2014 daguen_s
//

#ifndef _EX06_H_
# define _EX06_H_

#include <string>
#include <sstream>

template<typename T, typename U = T>
struct Tuple
{
public:
  T a;
  U b;

  std::string toString() const
  {
    return std::string("[TUPLE [") + get_print(a) + "] [" + get_print(b) + "]]";
  }

private:
  std::string get_print(int a) const
  {
    std::stringstream oss;
    oss << a;
    return std::string("int:") + oss.str();
  }

  std::string get_print(float a) const
  {
    std::stringstream oss;
    oss << a;
    return std::string("float:") + oss.str() + "f";
  }

  std::string get_print(std::string a) const
  {
    return std::string("string:\"") + a + "\"";
  }

  template<typename X>
  std::string get_print(X) const
  {
    return std::string("???");
  }
};

#endif
