//
// Warrior.hh for Warrior.hh in /home/daguen_s/rendu/piscine_cpp_d09/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Thu Jan 16 10:48:24 2014 daguen_s
// Last update Thu Jan 16 11:29:36 2014 daguen_s
//

#ifndef _WARRIOR_H_
# define _WARRIOR_H_

#include <iostream>
#include <string>
#include "Character.hh"

class Warrior : public Character
{
  std::string	Weapons;

public:
  Warrior(const std::string &, int);
  ~Warrior();

  int		CloseAttack();
  int		RangeAttack();
};

#endif /* _WARRIOR_H_ */
