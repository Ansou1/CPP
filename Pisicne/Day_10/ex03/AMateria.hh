//
// AMateria.hh for Amateria in /home/daguen_s/rendu/piscine_cpp_d10/ex03
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 16:24:09 2014 daguen_s
// Last update Fri Jan 17 17:29:44 2014 daguen_s
//

#ifndef __AMATERIA_H__
#define __AMATERIA_H__

#include <string>
#include <iostream>

class AMateria;

#include "ICharacter.hh"

class AMateria
{
protected:
  unsigned int		xp;
  std::string		type;

public:
  AMateria(std::string const & type);
  ~AMateria();

  std::string const &	getType() const;
  unsigned int		getXP() const;

  virtual AMateria	*clone() const = 0;
  virtual void		use(ICharacter & target);
  virtual void		effect(ICharacter & target);
};

#endif
