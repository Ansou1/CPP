//
// Mage.hh for Mage.hh in /home/daguen_s/rendu/piscine_cpp_d09/ex02
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Thu Jan 16 12:07:07 2014 daguen_s
// Last update Thu Jan 16 14:34:30 2014 daguen_s
//

#ifndef _MAGE_H_
# define _MAGE_H_

#include <iostream>
#include <string>

#include "Character.hh"

class Mage : public virtual Character
{
public:
  Mage(const std::string &_name, int level);
  ~Mage();

  int		CloseAttack();
  int		RangeAttack();
  void		RestorePower();
};

#endif /* _MAGE_H_ */
