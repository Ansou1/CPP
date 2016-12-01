//
// TacticalMarine.cpp for TacticalMarine in /home/daguen_s/rendu/piscine_cpp_d10/ex02
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 11:54:07 2014 daguen_s
// Last update Fri Jan 17 12:02:01 2014 daguen_s
//

#include "TacticalMarine.hh"

TacticalMarine::TacticalMarine()
{
  std::cout << "Tactical Marine ready for battle" << std::endl ;
}

TacticalMarine::TacticalMarine(TacticalMarine const & marine)
{
  (void) marine;
  std::cout << "Tactical Marine ready for battle" << std::endl ;
}

TacticalMarine::~TacticalMarine()
{
  std::cout << "Aaargh ..." << std::endl;
}

ISpaceMarine * TacticalMarine::clone() const
{
  return new TacticalMarine(*this);
}

void TacticalMarine::battleCry() const
{
  std::cout << "For the holy PLOT !" << std::endl;
}

void TacticalMarine::rangedAttack() const
{
  std::cout << "* attacks with bolter *" << std::endl;
}

void TacticalMarine::meleeAttack() const
{
  std::cout << "* attacks with chainsword *" << std::endl;
}

