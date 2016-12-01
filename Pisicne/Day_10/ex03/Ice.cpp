//
// Ice.cpp for Ice in /home/daguen_s/rendu/piscine_cpp_d10/ex03
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 16:39:05 2014 daguen_s
// Last update Fri Jan 17 17:30:35 2014 daguen_s
//

#include "Ice.hh"

Ice::Ice(): AMateria("ice")
{
}

Ice::Ice(Ice const & ice): AMateria("ice")
{
  this->xp = ice.xp;
}

Ice::~Ice()
{
}

AMateria * Ice::clone() const
{
  return new Ice(*this);
}

void Ice::effect(ICharacter & target)
{
  std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
