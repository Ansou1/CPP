//
// Paladin.hh for Paladin.hh in /home/daguen_s/rendu/piscine_cpp_d09/ex03
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Thu Jan 16 13:08:06 2014 daguen_s
// Last update Thu Jan 16 14:34:45 2014 daguen_s
//

#ifndef _PALADIN_H_
# define _PALADIN_H_

#include <string>
#include <iostream>

#include "Character.hh"
#include "Warrior.hh"
#include "Priest.hh"

class Paladin : public Warrior, public Priest
{
public:
  Paladin(const std::string &_name, int level);
  ~Paladin();

  int		CloseAttack();
  int		RangeAttack();
  void		Heal();
  void		RestorePower();
  int		Intercept();
};

#endif /* _PALADIN_H_ */
