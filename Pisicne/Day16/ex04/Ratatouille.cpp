//
// Ratatouille.cpp for  in /home/daguen_s/rendu/piscine_cpp_d16/ex04
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Thu Jan 23 17:57:58 2014 daguen_s
// Last update Thu Jan 23 18:12:48 2014 daguen_s
//

#include "Ratatouille.h"

Ratatouille::Ratatouille()
{
  this->str = "";
}

Ratatouille::~Ratatouille()
{
}

Ratatouille::Ratatouille(Ratatouille const &src)
{
  this->str = src.str;
}

Ratatouille		&Ratatouille::operator=(const Ratatouille &src)
{
  this->str = src.str;
  return *this;
}

Ratatouille		&Ratatouille::addVegetable(unsigned char src)
{
  std::ostringstream	tmp;

  tmp << src;
  str+= tmp.str();
  return *this;
}

Ratatouille		&Ratatouille::addCondiment(unsigned int src)
{
  std::ostringstream	tmp;

  tmp << src;
  str+= tmp.str();
  return *this;
}

Ratatouille		&Ratatouille::addSpice(double src)
{
  std::ostringstream	tmp;

  tmp << src;
  str+= tmp.str();
  return *this;
}

Ratatouille		&Ratatouille::addSauce(const std::string & src)
{
  std::ostringstream	tmp;

  tmp << src;
  str+= tmp.str();
  return *this;
}

std::string		Ratatouille::kooc(void)
{
  return this->str;
}
