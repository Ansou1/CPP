//
// Teddy.cpp for  in /home/daguen_s/rendu/rush2
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sun Jan 19 01:35:27 2014 daguen_s
// Last update Sun Jan 19 06:19:58 2014 daguen_s
//

#include "Teddy.hh"

Teddy::Teddy(std::string const & name) : Toy(name, TEDDY)
{
}

Teddy::Teddy(Teddy &src) : Toy(src.name, src.type)
{
}

void			Teddy::operator=(Teddy &src)
{
  (std::string)this->name = src.name;
  this->type = src.type;
}

Teddy::~Teddy()
{
}

void	Teddy::isTaken() const
{
  std::cout << "gra hu" << std::endl;
}
