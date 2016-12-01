//
// Victim.cpp for Victim in /home/daguen_s/rendu/piscine_cpp_d10/ex00
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 09:06:40 2014 daguen_s
// Last update Fri Jan 17 10:29:45 2014 daguen_s
//

#include "Victim.hh"

Victim::Victim(std::string name)
{
  this->name = name;
  std::cout << "Some random victim called " << this->name << " just popped !" << std::endl;
}

Victim::~Victim()
{
  std::cout << "Victim " << this->name << " just died for no apparent reason !" << std::endl;
}

std::string		Victim::getName() const
{
  return this->name;
}

void			Victim::getPolymorphed() const
{
  std::cout << this->name << " has been turned into a cute little sheep !" << std::endl;
}

std::ostream		&operator<<(std::ostream &os, Victim &victim)
{
  os << "I'm " << victim.getName() << " and i like otters !" << std::endl;
  return os;
}
