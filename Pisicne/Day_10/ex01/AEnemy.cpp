//
// AEnemy.cpp for AEnemy in /home/daguen_s/rendu/piscine_cpp_d10/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 10:01:59 2014 daguen_s
// Last update Fri Jan 17 10:12:56 2014 daguen_s
//

#include "AEnemy.hh"

AEnemy::AEnemy(int hp, std::string const & type)
{
  this->hit_point = hp;
  this->type = type;
}

AEnemy::~AEnemy()
{
}

std::string const	&AEnemy::getType() const
{
  return this->type;
}

int			AEnemy::getHP() const
{
  return this->hit_point;
}

void			AEnemy::takeDamage(int _damage)
{
  if (_damage > 0)
    this->hit_point -= _damage;
}
