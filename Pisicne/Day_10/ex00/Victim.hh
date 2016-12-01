//
// Victim.hh for Victim in /home/daguen_s/rendu/piscine_cpp_d10/ex00
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 09:06:51 2014 daguen_s
// Last update Fri Jan 17 10:29:55 2014 daguen_s
//

#ifndef _VICTIM_H_
# define _VICTIM_H_

#include <iostream>
#include <string>

class Victim
{
protected:
  std::string		name;

public:
  Victim(std::string);
    virtual ~Victim();

  virtual std::string	getName() const;
  virtual void		getPolymorphed() const;
};

std::ostream &operator<<(std::ostream &, Victim &);

#endif /* _VICTIM_H_ */
