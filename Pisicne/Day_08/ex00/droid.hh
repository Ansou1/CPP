//
// droid.hh for droid in /home/daguen_s/rendu/piscine_cpp_d08/ex00
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Wed Jan 15 09:53:14 2014 daguen_s
// Last update Wed Jan 15 11:40:07 2014 daguen_s
//

#ifndef _DROID_H_
# define _DROID_H_

#include <string>
#include <iostream>
#include <cstring>

class Droid
{
  std::string		id;
  size_t		energy;
  size_t const		attack;
  size_t const		toughness;
  std::string		*status;

public:
  Droid(std::string id = "");
  ~Droid();
  Droid(const Droid &);

  Droid			&operator=(Droid const &src);

  std::string		getId() const;
  size_t		getEnergy() const;
  std::string		*getStatus() const;
  size_t		getAttack() const;
  size_t		getToughness() const;

  void			setId(std::string id);
  void			setEnergy(size_t e);
  void			setStatus(std::string* s);

  bool			operator==(Droid const &d) const;
  bool			operator!=(Droid const &d) const;
  Droid			&operator<<(size_t &chrg);
};

std::ostream	&operator<<(std::ostream &os, Droid const &droid);

#endif /* _DROID_H_ */
