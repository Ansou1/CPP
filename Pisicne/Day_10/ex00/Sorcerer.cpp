//
// Sorcerer.cpp for Sorcerer in /home/daguen_s/rendu/piscine_cpp_d10/ex00
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 09:05:46 2014 daguen_s
// Last update Fri Jan 17 10:29:25 2014 daguen_s
//

#include "Sorcerer.hh"
#include "Victim.hh"

Sorcerer::Sorcerer(std::string name, std::string title)
{
  this->name = name;
  this->title = title;
  speak("is born !");
}

Sorcerer::~Sorcerer()
{
  speak("is dead. Consequences will never be the same !");
}

void		Sorcerer::speak(std::string message)
{
  std::cout << this->name << ", " << this->title << ", " << message << std::endl;
}

std::string	Sorcerer::getName() const
{
  return this->name;
}

std::string	Sorcerer::getTitle() const
{
  return this->title;
}

void		Sorcerer::polymorph(Victim const &civil) const
{
  civil.getPolymorphed();
}

std::ostream	&operator<<(std::ostream &os, Sorcerer & sorcerer)
{
  os << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies !" << std::endl;
  return os;
}
