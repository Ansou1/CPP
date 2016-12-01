//
// TacticalMarine.hh for TacticalMarine.hh in /home/daguen_s/rendu/piscine_cpp_d10/ex02
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 12:02:36 2014 daguen_s
// Last update Fri Jan 17 12:03:02 2014 daguen_s
//

#ifndef _TACTICALMARINE_H_
# define _TACTICALMARINE_H_

#include <string>
#include <iostream>

#include "ISpaceMarine.hh"

class TacticalMarine : public ISpaceMarine
{
public:
  TacticalMarine();
  TacticalMarine(TacticalMarine const & marine);
  virtual ~TacticalMarine();

  virtual ISpaceMarine *clone() const;
  virtual void battleCry() const;
  virtual void rangedAttack() const;
  virtual void meleeAttack() const;
};

#endif /* _TACTICALMARINE_H_ */
