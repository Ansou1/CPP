//
// Peon.hh for Peon in /home/daguen_s/rendu/piscine_cpp_d10/ex00
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 09:06:13 2014 daguen_s
// Last update Fri Jan 17 10:29:15 2014 daguen_s
//

#ifndef _PEON_H_
# define _PEON_H_

#include <iostream>
#include <string>

#include "Victim.hh"

class Peon : public Victim
{
public:
  Peon(std::string name);
  virtual ~Peon();

  void		getPolymorphed() const;
};

#endif /* _PEON_H_ */
