//
// Box.cpp for  in /home/daguen_s/rendu/rush2
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sun Jan 19 00:57:55 2014 daguen_s
// Last update Sun Jan 19 09:58:14 2014 daguen_s
//

#include <iostream>
#include "Box.hh"

Box::Box() : Wrap("Box", BOX)
{
  this->opened = true;
}

Box::~Box()
{
}

Box::Box(Box &src): Wrap(src.name, src.type)
{
}

void		Box::operator=(Box &src)
{
  (std::string)this->name = src.name;
  this->type = src.type;
}

bool		Box::wrapMeThat(Object *object)
{
  bool	estEmballe = false;

  if (this->opened)
    estEmballe = Wrap::wrapMeThat(object);
  else
      std::cerr << "The box is already close :(" << std::endl;
  if (estEmballe)
    this->closeMe();
  return estEmballe;
}

void		Box::closeMe()
{
  this->opened = false;
}


Object *Box::openMe()
{
  this->open = true;
  return (this->content);
}
