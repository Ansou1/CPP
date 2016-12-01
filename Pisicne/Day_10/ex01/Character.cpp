//
// Character.cpp for Character in /home/daguen_s/rendu/piscine_cpp_d10/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 10:38:07 2014 daguen_s
// Last update Fri Jan 17 15:59:09 2014 daguen_s
//

#include "Character.hh"

Character::Character(std::string const & name) : name(name), ap(40), weapon(NULL)
{
  this->name = name;
  this->ap = 40;
  this->weapon = NULL;
}

Character::~Character()
{
}

void			Character::recoverAP()
{
  this->ap += 10;
  if (this->ap > 40)
    ap = 40;
}

void			Character::equip(AWeapon* weapon)
{
  this->weapon = weapon;
}

void	Character::attack(AEnemy *enemy)
{
  if (this->getWeapon() != NULL && enemy != NULL)
    {
      std::cout << this->name << " attacks " << enemy->getType() << " with a " << (this->getWeapon())->getName() << std::endl;
      if (this->getAp() - (this->getWeapon())->getAPCost() >= 0)
	{
	  this->setAP(this->getAp() - (this->getWeapon())->getAPCost());
	  (this->getWeapon())->attack();
	  enemy->takeDamage((this->getWeapon())->getDamage());
	  if (enemy->getHP() <= 0)
	    delete enemy;
	}
    }
}


void			Character::setAP(int ap)
{
  if (ap <= 0)
    this->ap = 0;
  else
    this->ap = ap;
}

std::string const	&Character::getName() const
{
  return this->name;
}

int			Character::getAp() const
{
  return this->ap;
}

AWeapon			*Character::getWeapon() const
{
  return this->weapon;
}

std::ostream		&operator<<(std::ostream & os, Character const & perso)
{
  if (perso.getWeapon())
    os << perso.getName() << " has " << perso.getAp() << " AP and wields a " << (perso.getWeapon())->getName() << std::endl;
  else
    os << perso.getName() << " has " << perso.getAp() << " AP and is unarmed" << std::endl;
  return (os);
}

