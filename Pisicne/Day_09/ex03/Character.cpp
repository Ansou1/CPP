//
// Character.cpp for Character.cpp in /home/daguen_s/rendu/piscine_cpp_d09/ex00
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Thu Jan 16 09:06:28 2014 daguen_s
// Last update Thu Jan 16 14:42:37 2014 daguen_s
//

#include <iostream>
#include <string>
#include "Character.hh"

Character::Character(const std::string &name, int level)
{
  this->_power = 100;
  this->_pv = 100;
  this->_strength = 5;
  this->_stamina = 5;
  this->_intelligence = 5;
  this->_spirit = 5;
  this->_agility = 5;
  this->_name = name;
  this->_level = level;
  this->Range = CLOSE;
  std::cout << name << " Created" << std::endl;
}

Character::~Character()
{
}

const std::string	&Character::getName() const
{
  return this->_name;
}

int			Character::getLvl() const
{
  return this->_level;
}

int			Character::getPv() const
{
  return this->_pv;
}

int			Character::getPower() const
{
  return this->_power;
}

int			Character::CloseAttack()
{
  if (this->getPower() - 10 < 0)
    {
      std::cout << this->getName() << " out of power" << std::endl;
      return (0);
    }
  this->_power = this->_power - 10;
  std::cout << this->getName() << " strikes with a wood stick" << std::endl;
  return (10 + this->_strength);
}

int			Character::RangeAttack()
{
  if (this->getPower() - 10 < 0)
    {
      std::cout << this->getName() << " out of power" << std::endl;
      return (0);
    }
  this->_power = this->_power - 10;
  std::cout << this->getName() << " launches a stone" << std::endl;
  return (5 + this->_strength);
}

void			Character::Heal()
{
  this->_pv += 50;
  this->_pv = (this->_pv > 100) ? 100 : this->_pv;
  std::cout << this->getName() << " takes a potion" << std::endl;
}

void			Character::RestorePower()
{
  this->_power = 100;
  std::cout << this->getName() << " eats" << std::endl;
}

void			Character::TakeDamage(int _damage)
{
  this->_pv = this->_pv - _damage;
  if (this->_pv <= 0)
    std::cout << this->getName() << " out of combat" << std::endl;
  else
    std::cout << this->getName() << " takes " << _damage << " damage" << std::endl;
}
