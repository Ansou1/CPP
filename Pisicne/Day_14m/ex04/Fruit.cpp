//
// Fruit.cpp for  in /home/daguen_s/rendu/piscine_cpp_d14m/ex00
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Tue Jan 21 09:33:25 2014 daguen_s
// Last update Tue Jan 21 14:34:44 2014 daguen_s
//

#include <string>
#include "Fruit.h"

Fruit::Fruit()
{
}

Fruit::~Fruit()
{
}

int		Fruit::getVitamins() const
{
  return (this->_vitamins);
}

void		Fruit::setVitamins(int vita)
{
  this->_vitamins = vita;
}
