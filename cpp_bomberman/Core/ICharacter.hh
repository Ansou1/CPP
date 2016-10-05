#ifndef ICHARACTER_HH
#define ICHARACTER_HH

#include "Data.hh"
#include <Input.hh>
#include <string>

class				ICharacter
{
public:
  virtual ~ICharacter() {}

  virtual void			goUp() = 0;
  virtual void			goDown() = 0;
  virtual void			goLeft() = 0;
  virtual void			goRight() = 0;

  virtual Data::e_action	update(gdl::Input *input) = 0;
  virtual size_t		getX() const = 0;
  virtual size_t		getY() const = 0;
  virtual size_t		getId() const = 0;
  virtual void			setPos(size_t x, size_t y) = 0;

  virtual void			getRandomBonus(std::string &buff) = 0;
  virtual Data::e_type		getType() const = 0;
  virtual void        setType(const Data::e_type) = 0;
};

#endif
