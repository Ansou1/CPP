//
// Objet.cpp for  in /home/daguen_s/rendu/rush2
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sun Jan 19 01:11:34 2014 daguen_s
// Last update Sun Jan 19 09:46:04 2014 daguen_s
//

#include	"Object.hh"

Object::Object(std::string const & name, e_type type): type(type), name(name)
{
}

Object::Object(Object &src)
{
  (std::string)this->name = src.name;
  this->type = src.type;
}

void		Object::operator=(Object &src)
{
  (std::string)this->name = src.name;
  this->type = src.type;
}

Object::~Object()
{
}

e_type		Object::getType() const
{
  return this->type;
}

std::string const &Object::getName() const
{
  return this->name;
}

std::ostream &	operator<<(std::ostream & stream, Object * objet)
{
  stream << "Objet " << objet->getName() << " is ";
  switch (objet->getType())
    {
    case(TEDDY):
      stream << "a teddy";
      break;
    case(LITTLEPONY):
      stream << "a little poney";
      break;
    case(BOX):
      stream << "a box";
      break;
    case(GIFTPAPER):
      stream << "a gift paper";
      break;
    default:
      stream << "unknow";
      break;
    }
  stream << std::endl;
  return stream;
}

Object *Object::openMe()
{
  this->open = true;
  return (this->content);
}
