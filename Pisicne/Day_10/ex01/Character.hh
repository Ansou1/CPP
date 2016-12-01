//
// Character.hh for Character in /home/daguen_s/rendu/piscine_cpp_d10/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 10:33:41 2014 daguen_s
// Last update Fri Jan 17 15:56:37 2014 daguen_s
//

#ifndef _CHARACTER_H_
# define _CHARACTER_H_

#include "AEnemy.hh"
#include "AWeapon.hh"

class Character
{
  std::string		name;
  int			ap;
  AWeapon		*weapon;

public:
  Character(std::string const &name);
  ~Character();

  void			setAP(int ap);
  void			recoverAP();
  void			equip(AWeapon*);
  void			attack(AEnemy*);
  std::string const	&getName() const;
  int			getAp() const;
  AWeapon		*getWeapon() const;
};

std::ostream & operator<<(std::ostream & os, Character const & perso);


#endif /* _CHARACTER_H_ */
