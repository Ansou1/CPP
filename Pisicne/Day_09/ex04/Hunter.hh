//
// Hunter.hh for hunter in /home/daguen_s/rendu/piscine_cpp_d09/ex04
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Thu Jan 16 15:08:25 2014 daguen_s
// Last update Thu Jan 16 16:55:52 2014 daguen_s
//

#ifndef _HUNTER_H_
# define _HUNTER_H_

#include <iostream>
#include <string>

#include "Warrior.hh"

class Hunter : virtual public Character, protected Warrior
{
  std::string Weapons;

public:
  Hunter(const std::string &, int);
  ~Hunter();

  void	RestorePower();
  int	RangeAttack();
  using Character::Heal;
  using Warrior::CloseAttack;
};

#endif /* _HUNTER_H_ */
