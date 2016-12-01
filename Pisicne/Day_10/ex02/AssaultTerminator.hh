//
// AssaultTerminator.hh for Assault terminator in /home/daguen_s/rendu/piscine_cpp_d10/ex02
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 12:07:34 2014 daguen_s
// Last update Fri Jan 17 12:07:48 2014 daguen_s
//

#ifndef _ASSAULTTERMINATOR_H_
# define _ASSAULTTERMINATOR_H_

#include <string>
#include <iostream>

#include "ISpaceMarine.hh"

class AssaultTerminator : public ISpaceMarine
{
public:
  AssaultTerminator();
  AssaultTerminator(AssaultTerminator const & marine);
  virtual ~AssaultTerminator();

  virtual ISpaceMarine *clone() const;
  virtual void battleCry() const;
  virtual void rangedAttack() const;
  virtual void meleeAttack() const;
};

#endif /* _ASSAULTTERMINATOR_H_ */
