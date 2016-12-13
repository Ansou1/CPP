//
// Toy.cpp for  in /home/daguen_s/rendu/rush2
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sun Jan 19 01:40:06 2014 daguen_s
// Last update Sun Jan 19 09:04:22 2014 daguen_s
//

#include "Toy.hh"

Toy::Toy(std::string const& name, e_type type): Object(name, type), name(name)
{
}

Toy::Toy(Toy &src) : Object(src.name, src.type)
{
}

void			Toy::operator=(Toy &src)
{
  (std::string)this->name = src.name;
  this->type = src.type;
}

Toy::~Toy()
{
}

bool		Toy::wrapMeThat(Object *obj)
{
  (void) obj;
  std::cerr << "You can't wrap with a toy." << std::endl;
  return false;
}

Object		*Toy::openMe()
{
  std::cerr << "You can't open a toy." << std::endl;
  return NULL;
}

void		Toy::closeMe()
{
  std::cerr << "You can't close a toy." << std::endl;
}
