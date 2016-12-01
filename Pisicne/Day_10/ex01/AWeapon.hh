//
// AWeapon.hh for Aweapons in /home/daguen_s/rendu/piscine_cpp_d10/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 09:24:51 2014 daguen_s
// Last update Fri Jan 17 10:52:22 2014 daguen_s
//

#ifndef _AWEAPON_H_
# define _AWEAPON_H_

#include <iostream>
#include <string>

class AWeapon
{
protected:
  std::string	name;
  int		damage;
  int		ap;

public:
  AWeapon(std::string const &, int, int);
  virtual ~AWeapon();

  std::string	const &getName() const;
  int		getAPCost() const;
  int		getDamage() const;
  virtual void	attack() const =0;
};

#endif /* _AWEAPON_H_ */
