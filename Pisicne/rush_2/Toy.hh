//
// Toy.hh for  in /home/daguen_s/rendu/rush2
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sun Jan 19 01:41:56 2014 daguen_s
// Last update Sun Jan 19 06:25:20 2014 daguen_s
//

#ifndef _TOY_H_
# define _TOY_H_

#include <string>
#include <iostream>
#include "Object.hh"

class Toy : public Object
{
public:
  std::string const name;

public:
  Toy(std::string const &, e_type);
  Toy(Toy &);
  virtual ~Toy();

  void			operator=(Toy &);

  virtual bool		wrapMeThat(Object *);
  virtual Object	*openMe();
  virtual void		closeMe();
};

#endif /* _TOY_H_ */

