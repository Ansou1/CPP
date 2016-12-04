//
// Lime.cpp for  in /home/daguen_s/rendu/piscine_cpp_d14m/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Tue Jan 21 10:30:11 2014 daguen_s
// Last update Tue Jan 21 10:34:15 2014 daguen_s
//

#include "Lime.h"

Lime::Lime() : Lemon()
{
  this->_name = "lime";
  this->_vitamins = 2;
}

Lime::~Lime()
{
}

std::string		Lime::getName() const
{
  return this->_name;
}
