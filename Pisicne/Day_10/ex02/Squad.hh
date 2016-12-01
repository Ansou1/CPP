//
// Squad.hh for  in /home/daguen_s/rendu/piscine_cpp_d10/ex02
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 11:17:51 2014 daguen_s
// Last update Fri Jan 17 13:56:14 2014 daguen_s
//

#ifndef _SQUAD_H_
# define _SQUAD_H_

#include <iostream>
#include <string>
#include <vector>
#include "ISquad.hh"
#include "ISpaceMarine.hh"

class Squad : public ISquad
{
  std::vector<ISpaceMarine*>		soldier;

public:
  Squad();
  Squad(Squad const &);
  virtual ~Squad();

  virtual int			getCount() const;
  virtual ISpaceMarine		*getUnit(int);
  virtual int			push(ISpaceMarine *);

  Squad				&operator=(Squad const &);
};

#endif /* _SQUAD_H_ */
