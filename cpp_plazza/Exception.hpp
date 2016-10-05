#ifndef _EXCEPTION_H_
# define _EXCEPTION_H_

#include <iostream>
#include <sstream>
#include <exception>
#include <stdexcept>

class exception : public std::exception
{
  std::string		message;

public:
  exception(const char *msg)
  {
    std::ostringstream oss;
    oss << "Error : " << msg;
    this->message = oss.str();
  }

  exception(exception const &src)
  {
    this->message = src.message;
  }

  virtual ~exception() throw()
  {
  }

  exception &operator=(exception const &src)
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
