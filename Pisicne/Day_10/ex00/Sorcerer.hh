//
// Sorcerer.hh for Sorcerer in /home/daguen_s/rendu/piscine_cpp_d10/ex00
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 09:06:29 2014 daguen_s
// Last update Fri Jan 17 10:29:35 2014 daguen_s
//

#ifndef _SORCERER_H_
# define _SORCERER_H_

#include "Victim.hh"

class Sorcerer
{
protected:
  std::string	name;
  std::string	title;

  virtual void	speak(std::string);

public:
  Sorcerer(std::string, std::string);
    virtual ~Sorcerer();

  std::string	getName() const;
  std::string	getTitle() const;

  virtual void	polymorph(Victim const &) const;
};

std::ostream	&operator<<(std::ostream &, Sorcerer &);

#endif /* _SORCERER_H_ */
