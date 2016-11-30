//
// Hunter.cpp for Hunter.cpp in /home/daguen_s/rendu/piscine_cpp_d09/ex04
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Thu Jan 16 15:23:40 2014 daguen_s
// Last update Thu Jan 16 17:04:14 2014 daguen_s
//

#include <iostream>
#include <string>
#include "Hunter.hh"

Hunter::Hunter(const std::string &name, int level) : Character(name, level), Warrior(name, level, "sword")
{
  this->Weapons = "sword";
  this->_strength = 9;
  this->_stamina = 9;
  this->_intelligence = 5;
  this->_spirit = 6;
  this->_agility = 24;
  this->Range = CLOSE;
  std::cout << this->getName() << " is born from a tree" << std::endl;
}

Hunter::~Hunter()
{
}

void			Hunter::RestorePower()
{
  this->_power = 100;
  std::cout << this->getName() << " meditates" << std::endl;
}

int		Hunter::RangeAttack()
{
  if (this->getPower() - 25 < 0)
    {
      std::cout << this->getName() << " out of power" << std::endl;
      return (0);
    }
  this->_power = this->_power - 25;
  std::cout << this->getName() << " uses his bow" << std::endl;
  return (20 + this->_agility);
}
