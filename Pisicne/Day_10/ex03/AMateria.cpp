//
// AMateria.cpp for AMateria in /home/daguen_s/rendu/piscine_cpp_d10/ex03
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 16:22:32 2014 daguen_s
// Last update Fri Jan 17 17:29:35 2014 daguen_s
//

#include "AMateria.hh"

AMateria::AMateria(std::string const & type)
{
  this->xp = 0;
  this->type = type;
}

AMateria::~AMateria()
{
}

unsigned int		AMateria::getXP() const
{
  return this->xp;
}

std::string const	&AMateria::getType() const
{
  return this->type;
}

void			AMateria::use(ICharacter & target)
{
  this->xp += 10;
  effect(target);
}

void			AMateria::effect(ICharacter& target)
{
  (void) target;
}

