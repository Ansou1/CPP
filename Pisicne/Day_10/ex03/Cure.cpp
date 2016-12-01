//
// Cure.cpp for Cure in /home/daguen_s/rendu/piscine_cpp_d10/ex03
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 16:34:25 2014 daguen_s
// Last update Fri Jan 17 17:30:03 2014 daguen_s
//

#include "Cure.hh"

Cure::Cure(): AMateria("cure")
{
}

Cure::Cure(Cure const & cure) : AMateria("cure")
{
  this->xp = cure.xp;
}

Cure::~Cure()
{
}

AMateria * Cure::clone() const
{
  return new Cure(*this);
}

void Cure::effect(ICharacter & target)
{
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;;
}
