//
// Warrior.cpp for Warrior.cpp in /home/daguen_s/rendu/piscine_cpp_d09/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Thu Jan 16 10:53:42 2014 daguen_s
// Last update Thu Jan 16 14:49:53 2014 daguen_s
//

#include <iostream>
#include <string>
#include "Warrior.hh"

Warrior::Warrior(const std::string &name, int level) : Character(name, level)
{
  this->Weapons = "hammer";
  this->_strength = 12;
  this->_stamina = 12;
  this->_intelligence = 6;
  this->_spirit = 5;
  this->_agility = 7;
  this->Range = CLOSE;
  std::cout << "I'm " << this->getName() << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::~Warrior()
{
}

int		Warrior::CloseAttack()
{
  if (this->getPower() - 30 < 0)
    {
      std::cout << this->getName() << " out of power" << std::endl;
      return (0);
    }
  this->_power = this->_power - 30;
  std::cout << this->getName() << " strikes with his " << this->Weapons << std::endl;
  return (20 + this->_strength);
}

int		Warrior::RangeAttack()
{
  if (this->getPower() - 10 < 0)
    {
      std::cout << this->getName() << " out of power" << std::endl;
      return (0);
    }
  this->_power = this->_power - 10;
  std::cout << this->getName() << " intercepts" << std::endl;
  this->Range = CLOSE;
  return (0);
}
