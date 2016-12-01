//
// SuperMutant.hh for SuperMutant in /home/daguen_s/rendu/piscine_cpp_d10/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 10:16:01 2014 daguen_s
// Last update Fri Jan 17 10:53:30 2014 daguen_s
//

#ifndef _SUPERMUTANT_H_
# define _SUPERMUTANT_H_

#include <iostream>
#include <string>
#include "AEnemy.hh"

class SuperMutant : public AEnemy
{
public:
    SuperMutant();
    virtual ~SuperMutant();

  void		takeDamage(int);
};

#endif /* _SUPERMUTANT_H_ */
