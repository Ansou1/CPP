#ifndef IITEM_HH
#define IITEM_HH

#include "Map.hh"
#include "Data.hh"

class				IItem
{
public:
  virtual ~IItem() {}

  virtual Data::e_bombState	update(Map *map) = 0;
  virtual size_t		getId() const = 0;
  virtual Data::e_item		getType() const = 0;
};

#endif
