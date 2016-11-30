//
// Priest.hh for Priest.hh in /home/daguen_s/rendu/piscine_cpp_d09/ex02
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Thu Jan 16 12:19:55 2014 daguen_s
// Last update Thu Jan 16 14:35:01 2014 daguen_s
//

#ifndef _PRIEST_H_
# define _PRIEST_H_

#include <iostream>
#include <string>

#include "Mage.hh"

class Priest : public Mage
{
public:
  Priest(const std::string &_name, int level);
  ~Priest();

  int		CloseAttack();
  int		RangeAttack();
  void		Heal();
};

#endif /* _PRIEST_H_ */
