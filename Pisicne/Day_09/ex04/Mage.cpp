//
// Mage.cpp for Mage.cpp in /home/daguen_s/rendu/piscine_cpp_d09/ex02
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Thu Jan 16 12:09:35 2014 daguen_s
// Last update Thu Jan 16 14:22:36 2014 daguen_s
//

#include <iostream>
#include <string>

#include "Mage.hh"

Mage::Mage(const std::string &name, int level) : Character(name, level)
{
  this->_strength = 6;
  this->_stamina = 6;
  this->_intelligence = 12;
  this->_spirit = 11;
  this->_agility = 7;
  this->Range = CLOSE;
  std::cout << name << " teleported" << std::endl;
}

Mage::~Mage()
{
}

int		Mage::CloseAttack()
{
  if (this->getPower() - 10 < 0)
    {
      std::cout << this->getName() << " out of power" << std::endl;
      return 0;
    }
  this->_power = this->_power - 10;
  std::cout << this->getName() << " blinks" << std::endl;
  this->Range = RANGE;
  return (0);
}

int		Mage::RangeAttack()
{
  if (this->getPower() - 25 < 0)
    {
      std::cout << this->getName() << " out of power" << std::endl;
      return (0);
    }
  this->_power = this->_power - 25;
  std::cout << this->getName() << " launches a fire ball" << std::endl;
  return (20 + this->_spirit);
}

void		Mage::RestorePower()
{
  if (this->_power + 50 + this->_intelligence >= 100)
    this->_power = 100;
  else
    this->_power = this->_power + 50 + this->_intelligence;
  std::cout << this->getName() << " takes a mana potion" << std::endl;
}

