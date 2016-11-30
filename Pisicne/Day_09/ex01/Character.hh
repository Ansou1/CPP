//
// Character.hh for character in /home/daguen_s/rendu/piscine_cpp_d09/ex00
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Thu Jan 16 09:04:07 2014 daguen_s
// Last update Thu Jan 16 12:52:29 2014 daguen_s
//


#ifndef _CHARACTER_H_
# define _CHARACTER_H_

#include <iostream>
#include <string>

class Character
{
public:
  enum AttackRange	{CLOSE, RANGE};

  AttackRange		Range;

protected:
  std::string		_name;
  int			_level;
  int			_pv;
  int			_power;
  int			_strength;
  int			_stamina;
  int			_intelligence;
  int			_spirit;
  int			_agility;

public:
  Character(const std::string &, int);
  ~Character();

  const std::string	&getName() const;
  int			getLvl() const;
  int			getPv() const;
  int			getPower() const;

  int			CloseAttack();
  int			RangeAttack();
  void			Heal();
  void			RestorePower();
  void			TakeDamage(int damage);
};

#endif /* _CHARACTER_H_ */

