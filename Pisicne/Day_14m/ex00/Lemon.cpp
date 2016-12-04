//
// Lemon.cpp for  in /home/daguen_s/rendu/piscine_cpp_d14m/ex00
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Tue Jan 21 09:34:08 2014 daguen_s
// Last update Tue Jan 21 10:06:26 2014 daguen_s
//

#include <string>

#include "Lemon.h"

Lemon::Lemon() : Fruit()
{
  this->_name = "lemon";
  this->_vitamins = 3;
}

Lemon::~Lemon()
{
}

std::string	Lemon::getName() const
{
  return (this->_name);
}
