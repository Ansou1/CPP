//
// AssaultTerminator.cpp for assault terminator in /home/daguen_s/rendu/piscine_cpp_d10/ex02
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 12:03:59 2014 daguen_s
// Last update Fri Jan 17 16:09:16 2014 daguen_s
//

#include "AssaultTerminator.hh"

AssaultTerminator::AssaultTerminator()
{
  std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const & marine)
{
  (void) marine;
  std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::~AssaultTerminator()
{
  std::cout << "I'll be back ..." << std::endl;
}

ISpaceMarine * AssaultTerminator::clone() const
{
  return new AssaultTerminator(*this);
}

void AssaultTerminator::battleCry() const
{
  std::cout << "This code is unclean. PURIFY IT !" << std::endl;
}

void AssaultTerminator::rangedAttack() const
{
  std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack() const
{
  std::cout << "* attacks with chainfists *" << std::endl;
}

