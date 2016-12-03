//
// Toy.cpp for  in /home/daguen_s/rendu/piscine_cpp_d13/ex00
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Mon Jan 20 09:15:29 2014 daguen_s
// Last update Tue Jan 21 08:50:18 2014 daguen_s
//

#include "Toy.h"

Toy::Toy(ToyType type, const std::string &name, const std::string &file)
{
  this->type = type;
  this->name = name;
  this->image.getPictureFromFile(file);
}

Toy::Toy()
{
  this->type = BASIC_TOY;
  this->name = "toy";
  this->image.data = "";
}

Toy::Toy(const Toy &src)
{
  this->type = src.type;
  this->name = src.name;
  this->image = src.image;
}

Toy		&Toy::operator=(Toy const &src)
{
  this->type = src.type;
  this->name = src.name;
  this->image = src.image;
  return (*this);
}

Toy::~Toy()
{
}

int		Toy::getType() const
{
  return this->type;
}

std::string	Toy::getName() const
{
  return this->name;
}

std::string	Toy::getAscii() const
{
  return this->image.data;
}

void		Toy::setName(const std::string &name)
{
  this->name = name;
}

bool		Toy::setAscii(const std::string &file)
{
  if (!(this->image.getPictureFromFile(file)))
    {
      this->erreur.setType(Error::PICTURE);
      return false;
    }
  return true;
}

bool		Toy::speak(const std::string & src)
{
  std::cout << this->getName() << " \"" << src << "\"" << std::endl;
  return true;
}

Toy		&Toy::operator<<(const std::string &src)
{
  this->image.data = src;
  return (*this);
}

std::ostream	&operator<<(std::ostream &os, const Toy &src)
{
  os << src.getName() << std::endl;
  os << src.getAscii() << std::endl;
  return os;
}

bool		Toy::speak_es(const std::string & src)
{
  (void)src;
  this->erreur.setType(Error::SPEAK);
  return false;
}

void		Toy::Error::setType(ErrorType type)
{
  this->type = type;
}

Toy::Error::Error()
{
  this->type = UNKNOWN;
}

Toy::Error::~Error()
{
}

Toy::Error	Toy::getLastError() const
{
  return this->erreur;
}

std::string	Toy::Error::what() const
{
  if (type == PICTURE)
    return "bad new illustration";
  else if (type == SPEAK)
    return "wrong mode";
  else
    return "";
}

std::string	Toy::Error::where() const
{
  if (type == PICTURE)
    return "setAscii";
  else if (type == SPEAK)
    return "speak_es";
  else
    return "";
}
