//
// AWeapon.cpp for AWeapon in /home/daguen_s/rendu/piscine_cpp_d10/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 09:30:46 2014 daguen_s
// Last update Fri Jan 17 10:52:00 2014 daguen_s
//

#include "AWeapon.hh"

AWeapon::AWeapon(std::string const &name, int damage, int ap)
{
  this->name = name;
  this->damage = damage;
  this->ap = ap;
}

AWeapon::~AWeapon()
{
}

std::string		const &AWeapon::getName() const
{
  return this->name;
}

int			AWeapon::getAPCost() const
{
  return this->ap;
}

int			AWeapon::getDamage() const
{
  return this->damage;
}
