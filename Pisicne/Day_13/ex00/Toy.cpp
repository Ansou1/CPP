//
// Toy.cpp for  in /home/daguen_s/rendu/piscine_cpp_d13/ex00
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Mon Jan 20 09:15:29 2014 daguen_s
// Last update Mon Jan 20 09:50:09 2014 daguen_s
//

#include "Toy.h"

Toy::Toy(ToyType type, const std::string &name, const std::string &file)
{
  this->type = type;
  this->name = name;
  this->image.getPictureFromFile(file);
}

Toy::Toy()
{
  this->type = BASIC_TOY;
  this->name = "toy";
  this->image.data = "";
}

Toy::~Toy()
{
}

int		Toy::getType() const
{
  return this->type;
}

std::string	Toy::getName() const
{
  return this->name;
}

std::string	Toy::getAscii() const
{
  return this->image.data;
}

void		Toy::setName(const std::string &name)
{
  this->name = name;
}

bool		Toy::setAscii(const std::string &file)
{
  return (this->image.getPictureFromFile(file));
}
