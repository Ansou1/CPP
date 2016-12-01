//
// Peon.cpp for Peon in /home/daguen_s/rendu/piscine_cpp_d10/ex00
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 09:06:03 2014 daguen_s
// Last update Fri Jan 17 14:22:15 2014 daguen_s
//

#include "Peon.hh"

Peon::Peon(std::string name) : Victim(name)
{
  this->name = name;
  std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
  std::cout << "Bleuark..." << std::endl;
}

void	Peon::getPolymorphed() const
{
  std::cout << this->name << " has been turned into a pink pony !" << std::endl;
}
