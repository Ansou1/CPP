//
// Banana.cpp for  in /home/daguen_s/rendu/piscine_cpp_d14m/ex00
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Tue Jan 21 09:32:41 2014 daguen_s
// Last update Tue Jan 21 10:05:34 2014 daguen_s
//

#include <string>
#include "Banana.h"

Banana::Banana() : Fruit()
{
  this->_name = "banana";
  this->_vitamins = 5;
}

Banana::~Banana()
{
}

std::string	Banana::getName() const
{
  return (this->_name);
}
