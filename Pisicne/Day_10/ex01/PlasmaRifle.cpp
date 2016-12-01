//
// PlasmaRifle.cpp for PLasma in /home/daguen_s/rendu/piscine_cpp_d10/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 09:37:52 2014 daguen_s
// Last update Fri Jan 17 09:50:49 2014 daguen_s
//

#include "PlasmaRifle.hh"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 21, 5)
{
}

PlasmaRifle::~PlasmaRifle()
{
}

void		PlasmaRifle::attack() const
{
  std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
