/*
** Phaser.h for Phaser in /home/daguen_s/rendu/piscine_cpp_d07a/ex03
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Wed Jan 15 02:17:36 2014 daguen_s
** Last update Wed Jan 15 03:04:48 2014 daguen_s
*/

#ifndef _PHASER_H_
# define _PHASER_H_

#include <string>
#include <iostream>

class Phaser
{
 public:
  enum AmmoType {REGULAR, PLASMA, ROCKET};

 private:
  AmmoType	_type;
  int		maxAmmo;
  int		bullet;

 public:
  Phaser(int maxAmmo = 20, AmmoType type = REGULAR);
  ~Phaser();

  void fire();
  void ejectClip();
  void changeType(AmmoType newType);
  void reload();
  void addAmmo(AmmoType type);
  int getCurrentAmmos();
  static const int Empty = 0;
};

#endif /* _PHASER_H_ */
