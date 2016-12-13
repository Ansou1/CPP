//
// ConveyorBeltPePeNoel.hh for  in /home/daguen_s/rendu/rush2
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sun Jan 19 02:08:18 2014 daguen_s
// Last update Sun Jan 19 04:01:00 2014 daguen_s
//

#ifndef _CONVEYORBELTPEPENOEL_H_
# define _CONVEYORBELTPEPENOEL_H_

#include	<iostream>
#include	<cstdio>
#include	"IConveyorBelt.hh"

class           ConveyorBeltPePeNoel : public IConveyorBelt
{
protected:
  int			index;
  Object		*current;
  Object		**stack;

public:
  ConveyorBeltPePeNoel();
  virtual ~ConveyorBeltPePeNoel();

  virtual bool          Put(Object *objet);
  virtual Object        *Take();

  bool			OUT(){return true;};
  bool			IN(){return true;};
};

#endif /* _CONVEYORBELTPEPENOEL_H_ */
