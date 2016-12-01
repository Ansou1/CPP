//
// PowerFist.hh for powerfist in /home/daguen_s/rendu/piscine_cpp_d10/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 09:38:39 2014 daguen_s
// Last update Fri Jan 17 09:53:05 2014 daguen_s
//

#ifndef _POWERFIST_H_
# define _POWERFIST_H_

#include "AWeapon.hh"

class PowerFist : public AWeapon
{
public:
    PowerFist();
    virtual ~PowerFist();

  virtual void	attack() const;
};

#endif /* _POWERFIST_H_ */
