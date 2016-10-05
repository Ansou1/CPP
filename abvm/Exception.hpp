//
// Exception.hpp for  in /home/daguen_s/rendu/abstractvm-2017-daguen_s
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Thu Feb 13 11:54:50 2014 daguen_s
// Last update Thu Feb 13 11:54:52 2014 daguen_s
//

#ifndef _EXCEPTION_H_
# define _EXCEPTION_H_

#include <iostream>
#include <sstream>
#include <exception>

class exception_lexical : public std::exception
{
  std::string		message;

public:
  exception_lexical(const char *msg, unsigned int const &line)
  {
    std::ostringstream oss;
    oss << "Error line " << line << ": " << msg;
    this->message = oss.str();
  }

  virtual ~exception_lexical() throw()
  {
  }

  virtual const char *what() const throw()
  {
    return this->message.c_str();
  }
};

class exception_syntax : public std::exception
{
  std::string		message;

public:
  exception_syntax(const char *msg)
  {
    std::ostringstream oss;
    oss << "Error: " << msg;
    this->message = oss.str();
  }

  virtual ~exception_syntax() throw()
  {
  }

  virtual const char *what() const throw()
  {
    return this->message.c_str();
  }
};

class exception_calcul : public std::exception
{
  std::string		message;

public:
  exception_calcul(const char *msg)
  {
    std::ostringstream oss;
    oss << msg;
    this->message = oss.str();
  }

  virtual ~exception_calcul() throw()
  {
  }

  virtual const char *what() const throw()
  {
    return this->message.c_str();
  }
};

#endif /* _EXCEPTION_H_ */
