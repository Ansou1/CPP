//
// Paladin.cpp for Paladin.cpp in /home/daguen_s/rendu/piscine_cpp_d09/ex03
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Thu Jan 16 13:28:40 2014 daguen_s
// Last update Thu Jan 16 14:31:07 2014 daguen_s
//

#include <iostream>
#include <string>
#include "Paladin.hh"

Paladin::Paladin(const std::string &name, int level) : Character(name, level) , Warrior(name, level) , Priest(name, level)
{
  this->_strength = 9;
  this->_stamina = 10;
  this->_intelligence = 10;
  this->_spirit = 10;
  this->_agility = 2;
  this->Range = CLOSE;
  std::cout << "the light falls on " << name << std::endl;
}

Paladin::~Paladin()
{
}

int Paladin::CloseAttack()
{
  return (Warrior::CloseAttack());
}

int Paladin::RangeAttack()
{
  return (Priest::RangeAttack());
}

void Paladin::Heal()
{
  Priest::Heal();
}

void Paladin::RestorePower()
{
  Character::RestorePower();
}

int Paladin::Intercept()
{
  return (Warrior::RangeAttack());
}

