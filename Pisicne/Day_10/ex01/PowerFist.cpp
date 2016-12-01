//
// PowerFist.cpp for powerfist in /home/daguen_s/rendu/piscine_cpp_d10/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 09:39:16 2014 daguen_s
// Last update Fri Jan 17 09:54:57 2014 daguen_s
//

#include "PowerFist.hh"

PowerFist::PowerFist() : AWeapon("Power Fist", 50, 8)
{
}

PowerFist::~PowerFist()
{
}

void	PowerFist::attack() const
{
  std::cout << "* pschhh... SBAM! *" << std::endl;
}
