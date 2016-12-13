//
// ITable.hh for  in /home/daguen_s/rendu/rush2
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sun Jan 19 02:35:06 2014 daguen_s
// Last update Sun Jan 19 06:05:40 2014 daguen_s
//

#ifndef		__ITABLE_HH__
#define		__ITABLE_HH__

#include	"Object.hh"

class		ITable
{
public:
  virtual int	        Put(Object *objet) = 0;
  virtual Object        *Take(int index) const = 0;
  virtual Object	**Look() = 0;
  virtual Object	**getGift() = 0;
  virtual int		*getIndex() = 0;
  virtual Object	**getTable() = 0;
  virtual void		setValueGift(int index, Object *value) = 0;
  virtual void		setValueIndex(int index, int value) = 0;
  virtual void		setValueTable(int index, Object *value) = 0;
};

#endif
