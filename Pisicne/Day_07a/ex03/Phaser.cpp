//
// Phaser.cpp for phaser in /home/daguen_s/rendu/piscine_cpp_d07a/ex03
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Wed Jan 15 02:29:29 2014 daguen_s
// Last update Wed Jan 15 03:04:03 2014 daguen_s
//

#include <iostream>
#include <string>
#include "Sounds.h"
#include "Phaser.h"

Phaser::Phaser(int maxAmmo, AmmoType type)
{
  this->maxAmmo = maxAmmo;
  this->_type = type;
  this->bullet = maxAmmo;
}

Phaser::~Phaser()
{
}

void	Phaser::fire()
{
  std::cout << "Clip empty, please reload" << std::endl;
}

void Phaser::ejectClip()
{
  this->bullet = 0;
}
void Phaser::changeType(AmmoType newType)
{
  std::string src("");
  if (newType == REGULAR)
    src = "regular";
  else if (newType == PLASMA)
    src = "plasma";
  else if (newType == ROCKET)
    src = "rocket";
  std::cout << "Switching ammo to type : " << src << std::endl;
  this->_type = newType;
}

void Phaser::reload()
{
  std::cout << "Reloading ..." << std::endl;
}

void Phaser::addAmmo(AmmoType type)
{
  if (this->bullet == this->maxAmmo)
    std::cout << "Clip full" << std::endl;
}

int Phaser::getCurrentAmmos()
{
  return this->bullet;
}
