//
// Wrap.cpp for  in /home/daguen_s/rendu/rush2
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sun Jan 19 01:21:01 2014 daguen_s
// Last update Sun Jan 19 09:53:05 2014 daguen_s
//

#include	<iostream>
#include	<fstream>
#include	"Wrap.hh"

Wrap::Wrap(std::string const & name, e_type type): Object(name, type)
{
  this->content = NULL;
}

Wrap::Wrap(Wrap &src) : Object(src.name, src.type)
{
}

void			Wrap::operator=(Wrap & src)
{
  (std::string)this->name = src.name;
  this->type = src.type;
}

Wrap::~Wrap()
{
}

void	Wrap::isTaken() const
{
}

bool	Wrap::wrapMeThat(Object * obj)
{
  if (!obj) {
    std::cerr << "Pas d'objet disponible." << std::endl;
    return false;
  }
  if (this->content) {
    std::cerr << "L'emballage contient deja un objet." << std::endl;
    return false;
  }
  this->content = obj;
  return true;
}

Object *	Wrap::openMe()
{
  Object		*tmp = this->content;
  if (!tmp)
    std::cerr << "L'emballage est vide !" << std::endl;
  else
    this->content = NULL;
  return (tmp);
}
