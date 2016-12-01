//
// Ice.hh for Ice in /home/daguen_s/rendu/piscine_cpp_d10/ex03
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 16:40:28 2014 daguen_s
// Last update Fri Jan 17 17:30:52 2014 daguen_s
//

#ifndef __ICE_H__
#define __ICE_H__

#include <string>
#include <iostream>

#include "AMateria.hh"
#include "ICharacter.hh"

class Ice : public AMateria
{
public:
  Ice();
  Ice(Ice const & ice);
  ~Ice();

  virtual AMateria	*clone() const;
  virtual void		effect(ICharacter & target);
};

#endif
