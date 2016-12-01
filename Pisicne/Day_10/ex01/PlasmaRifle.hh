//
// PlasmaRifle.hh for plasma in /home/daguen_s/rendu/piscine_cpp_d10/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 09:36:52 2014 daguen_s
// Last update Fri Jan 17 09:50:07 2014 daguen_s
//

#ifndef _PLASMARIFLE_H_
# define _PLASMARIFLE_H_

#include "AWeapon.hh"

class PlasmaRifle : public AWeapon
{
public:
  PlasmaRifle();
    virtual ~PlasmaRifle();

  virtual void	attack() const;
};


#endif /* _PLASMARIFLE_H_ */
