//
// Priest.cpp for Priest.cpp in /home/daguen_s/rendu/piscine_cpp_d09/ex02
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Thu Jan 16 12:23:16 2014 daguen_s
// Last update Thu Jan 16 12:50:30 2014 daguen_s
//

#include <iostream>
#include <string>

#include "Priest.hh"

Priest::Priest(const std::string &name, int level): Mage::Mage(name, level)
{
  this->_strength = 4;
  this->_stamina = 4;
  this->_intelligence = 42;
  this->_spirit = 21;
  this->_agility = 2;
  this->Range = CLOSE;
  std::cout << name << " enters in the order" << std::endl;
}


Priest::~Priest()
{
}


int		Priest::CloseAttack()
{
  if (this->getPower() - 10 < 0)
    {
      std::cout << this->getName() << " out of power" << std::endl;
      return 0;
    }
  this->_power = this->_power - 10;
  std::cout << this->getName() << " uses a spirit explosion" << std::endl;
  return (10 + this->_spirit);
}

int		Priest::RangeAttack()
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

void		Priest::Heal()
{
  if (this->getPower() - 10 < 0)
    std::cout << this->getName() << " out of power" << std::endl;
  else
    {
      this->_power = this->_power - 10;
      if (this->_pv + 70 > 100)
	this->_pv = 100;
      else
	this->_pv = this->_pv + 70;
      std::cout << this->getName() << " casts a little heal spell" << std::endl;
    }
}
