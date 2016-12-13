//
// LittlePony.cpp for  in /home/daguen_s/rendu/rush2
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sun Jan 19 01:10:27 2014 daguen_s
// Last update Sun Jan 19 06:12:18 2014 daguen_s
//

#include "LittlePony.hh"

LittlePony::LittlePony(std::string const& name) : Toy(name, LITTLEPONY)
{
}

LittlePony::LittlePony(LittlePony &src) : Toy(src.name, src.type)
{
}

void		LittlePony::operator=(LittlePony &src)
{
  (std::string)this->name =src.name;
  this->type = src.type;
}

LittlePony::~LittlePony()
{
}

void		LittlePony::isTaken() const
{
  std::cout << "yo man" << std::endl;
}
