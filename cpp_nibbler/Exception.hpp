//
// Exception.hpp for  in /home/daguen_s/rendu/cpp_nibbler
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Wed Apr  2 09:47:08 2014 daguen_s
// Last update Wed Apr  2 21:05:51 2014 daguen_s
//

#ifndef _EXCEPTION_H_
# define _EXCEPTION_H_

#include <iostream>
#include <sstream>
#include <exception>
#include <stdexcept>

class exception_lib : public std::exception
{
  std::string		message;

public:
  exception_lib(const char *msg)
  {
    std::ostringstream oss;
    oss << "Error : " << msg;
    this->message = oss.str();
  }

  exception_lib(exception_lib const &src)
  {
    this->message = src.message;
  }

  virtual ~exception_lib() throw()
  {
  }

  exception_lib &operator=(exception_lib const &src)
  {
    if (this != &src)
      this->message = src.message;
    return (*this);
  }

  virtual const char *what() const throw()
  {
    return this->message.c_str();
  }
};

class exception_loader : public std::exception
{
  std::string		message;

public:
  exception_loader(const char *msg)
  {
    std::ostringstream oss;
    oss << "Error: " << msg;
    this->message = oss.str();
  }

  exception_loader(exception_loader const &src)
  {
    this->message = src.message;
  }

  virtual ~exception_loader() throw()
  {
  }

  exception_loader &operator=(exception_loader const &src)
  {
    if (this != &src)
      this->message = src.message;
    return (*this);
  }

  virtual const char *what() const throw()
  {
    return this->message.c_str();
  }
};


class exception_param : public std::invalid_argument
{
  std::string		message;

public:
  exception_param(const char *msg)
    : invalid_argument(msg)
  {
    std::ostringstream oss;
    oss << "Error: " << msg;
    this->message = oss.str();
  }

  exception_param(exception_param const &src)
    : invalid_argument("ok")
  {
    this->message = src.message;
  }

  virtual ~exception_param() throw()
  {
  }

  exception_param &operator=(exception_param const &src)
  {
    if (this != &src)
      this->message = src.message;
    return (*this);
  }

  virtual const char *what() const throw()
  {
    return this->message.c_str();
  }
};

#endif /* _EXCEPTION_H_ */
