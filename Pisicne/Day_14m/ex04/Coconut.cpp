//
// Coconut.cpp for  in /home/daguen_s/rendu/piscine_cpp_d14m/ex02
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Tue Jan 21 11:27:42 2014 daguen_s
// Last update Wed Jan 22 09:34:31 2014 daguen_s
//

#include <string>
#include "Coconut.h"

Coconut::Coconut() : Fruit()
{
  this->_name = "coconut";
  this->_vitamins = 15;
}

Coconut::~Coconut()
{
}

std::string	Coconut::getName() const
{
  return (this->_name);
}
