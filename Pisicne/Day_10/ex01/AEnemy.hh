//
// AEnemy.hh for AEnemy in /home/daguen_s/rendu/piscine_cpp_d10/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 09:56:10 2014 daguen_s
// Last update Fri Jan 17 17:07:00 2014 daguen_s
//

#ifndef _AENEMY_H_
# define _AENEMY_H_

#include <iostream>
#include <string>

class AEnemy
{
  int		hit_point;
  std::string	type;

public:
  AEnemy(int hp, std::string const & type);
  virtual ~AEnemy();

  std::string const	&getType() const;
  int			getHP() const;
  virtual void		takeDamage(int);
};

#endif /* _AENEMY_H_ */
