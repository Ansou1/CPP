//
// TablePePeNoel.cpp for  in /home/daguen_s/rendu/rush2
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sun Jan 19 03:30:15 2014 daguen_s
// Last update Sun Jan 19 04:08:26 2014 daguen_s
//

#include	"TablePePeNoel.hh"
#include	<iostream>
#include	<cstdio>

TablePePeNoel::TablePePeNoel()
{
  this->gift = new Object*[4];
  this->gift[3] = NULL;
  this->index[0] = -1;
  this->index[1] = -1;
  this->index[2] = -1;

  this->gift[0] = NULL;
  this->gift[1] = NULL;
  this->gift[2] = NULL;

  this->table[0] = NULL;
  this->table[1] = NULL;
  this->table[2] = NULL;
  this->table[3] = NULL;
  this->table[4] = NULL;
  this->table[5] = NULL;
  this->table[6] = NULL;
  this->table[7] = NULL;
  this->table[8] = NULL;
  this->table[9] = NULL;
}

TablePePeNoel::~TablePePeNoel()
{
}

int	TablePePeNoel::Put(Object *objet)
{
  for (int i = 0; i < 10; i++)
    if (this->table[i] == NULL)
      {
	this->table[i] = objet;
	return i;
      }
  return -1;
}

Object	*TablePePeNoel::Take(int index) const
{
  if (index >= 0 && index < 10)
    {
      return this->table[index];
    }
  std::cerr << "It's not possible to take a gift at this index." << std::endl;
  return NULL;
}

Object	**TablePePeNoel::Look()
{
  return this->table;
}

Object		**TablePePeNoel::getGift()
{
  return this->gift;
}

int		*TablePePeNoel::getIndex()
{
  return this->index;
}

Object		**TablePePeNoel::getTable()
{
  return this->table;
}

void	TablePePeNoel::setValueGift(int index, Object *value)
{
  this->gift[index] = value;
}

void	TablePePeNoel::setValueIndex(int index, int value)
{
  this->index[index] = value;
}

void	TablePePeNoel::setValueTable(int index, Object *value)
{
  this->table[index] = value;
}
