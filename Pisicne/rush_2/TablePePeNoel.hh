//
// TablePePeNoel.hh for  in /home/daguen_s/rendu/rush2
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sun Jan 19 04:03:43 2014 daguen_s
// Last update Sun Jan 19 04:04:36 2014 daguen_s
//

#ifndef		__TABLEPEPENOEL_HH__
#define		__TABLEPEPENOEL_HH__

#include	"ITable.hh"

class           TablePePeNoel : public ITable
{
protected:
  int		index[3];
  Object	**gift;
  Object	*table[10];

public:
  TablePePeNoel();
  virtual ~TablePePeNoel();
  virtual int		Put(Object *objet);
  virtual Object        *Take(int index) const;
  virtual Object	**Look();
  Object		**getGift();
  int			*getIndex();
  Object		**getTable();
  void			setValueGift(int index, Object *value);
  void			setValueIndex(int index, int value);
  void			setValueTable(int index, Object *value);
};

#endif
