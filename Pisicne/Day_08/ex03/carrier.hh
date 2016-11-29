//
// carrier.hh for carrier in /home/daguen_s/rendu/piscine_cpp_d08/ex03
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Wed Jan 15 17:14:37 2014 daguen_s
// Last update Wed Jan 15 22:48:28 2014 daguen_s
//

#ifndef _CARRIER_H_
# define _CARRIER_H_

#include <string>
#include <iostream>
#include <stdlib.h>

#include "droid.hh"

class Carrier
{
  std::string	Id;
  size_t	Energy;
  size_t const	Attack;
  size_t const	Toughness;
  size_t	Speed;
  Droid *	Droids[5];

public:
  Carrier(std::string const & = "", size_t const & = 300);
  ~Carrier();

  size_t	getEnergy() const;
  size_t	getSpeed() const;
  void		operator<<(Droid *);
  void		operator>>(Droid *);
  Droid		*operator[](int const &i);
  Bool		operator~(int const &x, int const &y);
};

#endif /* _CARRIER_H_ */
