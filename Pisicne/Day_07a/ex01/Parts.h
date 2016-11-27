/*
** Parts.h for parts in /home/daguen_s/rendu/piscine_cpp_d07a/ex01
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Tue Jan 14 21:30:46 2014 daguen_s
** Last update Wed Jan 15 00:12:03 2014 daguen_s
*/

#ifndef _PARTS_H_
# define _PARTS_H_

#include <iostream>
#include <string>

class Arms
{
  std::string		_serial;
  bool			_functionnal;

 public:
  Arms(std::string const serial = "A-01" , bool functionnal = true);
  ~Arms();

  bool			isFunctionnal() const;
  std::string		serial() const;
  void			informations() const;
};

class Legs
{
  std::string		_serial;
  bool			_functionnal;

 public:
  Legs(std::string const serial = "L-01", bool functionnal = true);
  ~Legs();

  bool			isFunctionnal() const;
  std::string		serial() const;
  void			informations() const;
};

class Head
{
  std::string		_serial;
  bool			_functionnal;

 public:
  Head(std::string const serial = "H-01", bool functionnal = true);
  ~Head();

  bool			isFunctionnal() const;
  std::string		serial() const;
  void			informations() const;
};

#endif /* _PARTS_H_ */
