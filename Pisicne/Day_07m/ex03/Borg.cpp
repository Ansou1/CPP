//
// Borg.cpp for borg in /home/daguen_s/rendu/piscine_cpp_d07m/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Tue Jan 14 11:20:05 2014 daguen_s
// Last update Tue Jan 14 15:15:50 2014 daguen_s
//

#include <iostream>
#include <string>
#include "Destination.hh"
#include "Borg.hh"

Borg::Ship::Ship(int wF, short repair)
{
  this->_side = 300;
  this->_maxWarp = 9;
  this->_location = UNICOMPLEX;
  this->_home = UNICOMPLEX;
  this->_shield = 100;
  this->_weaponFrequency = wF;
  this->_repair = repair;
  std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
  std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
  std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{
}

void	Borg::Ship::setupCore(WarpSystem::Core *core)
{
  this->core = core;
}

void	Borg::Ship::checkCore()
{
  if ((this->core->checkReactor())->isStable())
    std::cout << "Everything is in order." << std::endl;
  else
    std::cout << "Critical failure imminent." << std::endl;
}

bool Borg::Ship::move(int warp, Destination d)
{
  if ((warp <= this->_maxWarp) && (d != this->_location) && (this->core->checkReactor()->isStable()))
    {
      this->_location = d;
      return true;
    }
  return false;
}

bool Borg::Ship::move(int warp)
{
  if ((warp <= this->_maxWarp) && (this->_home != this->_location) && (this->core->checkReactor()->isStable()))
    {
      this->_location = this->_home;
      return true;
    }
  return false;
}

bool Borg::Ship::move(Destination d)
{
  if ((this->_location != d) && (this->core->checkReactor()->isStable()))
    {
      this->_location = d;
      return true;
    }
  return false;
}

bool Borg::Ship::move()
{
    if ((this->_home != this->_location) && (this->core->checkReactor()->isStable()))
    {
      this->_location = this->_home;
      return true;
    }
  return false;
}


int		Borg::Ship::getShield()
{
  return this->_shield;
}

void		Borg::Ship::setShield(int shield)
{
  this->_shield -= shield;
}

int		Borg::Ship::getWeaponFrequency()
{
  return this->_weaponFrequency;
}

void		Borg::Ship::setWeaponFrequency(int weapon)
{
  this->_weaponFrequency = weapon;
}

short		Borg::Ship::getRepair()
{
  return this->_repair;
}

void		Borg::Ship::setRepair(short repair)
{
  this->_repair = repair;
}

void		Borg::Ship::fire(Federation::Starfleet::Ship* sf)
{
  sf->setShield(sf->getShield() - this->getWeaponFrequency());
  std::cout << "Firing on target with " << this->getWeaponFrequency() << "GW frequency." << std::endl;
}

void		Borg::Ship::fire(Federation::Ship* s)
{
  s->getCore()->checkReactor()->setStability(false);
  std::cout << "Firing on target with " << this->getWeaponFrequency() << "GW frequency." << std::endl;
}

void		Borg::Ship::repair()
{
  if (this->getRepair() - 1 >= 0)
    {
      this->setRepair(this->getRepair() - 1);
      std:: cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
    }
  else
    std::cout << "Energy cells depleted, shield weakening." << std::endl;
}
