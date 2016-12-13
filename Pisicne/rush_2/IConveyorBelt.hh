//
// IConveyorBelt.hh for  in /home/daguen_s/rendu/rush2
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sun Jan 19 02:33:13 2014 daguen_s
// Last update Sun Jan 19 06:05:26 2014 daguen_s
//

#ifndef _ICONVEYORBELT_H_
# define _ICONVEYORBELT_H_

#include	"Object.hh"
#include	"Box.hh"
#include	"GiftPaper.hh"
#include	"LittlePony.hh"
#include	"Teddy.hh"

class           IConveyorBelt
{
public:
  virtual ~IConveyorBelt(){};
  virtual bool          Put(Object *objet) = 0;
  virtual Object        *Take() = 0;
  virtual bool	        OUT() = 0;
  virtual bool		IN() = 0;
};

#endif /* _ICONVEYORBELT_H_ */
