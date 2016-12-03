//
// Woody.cpp for  in /home/daguen_s/rendu/piscine_cpp_d13/ex02
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Mon Jan 20 10:43:09 2014 daguen_s
// Last update Mon Jan 20 11:13:59 2014 daguen_s
//

#include "Woody.h"

Woody::Woody(const std::string & name) : Toy(Toy::WOODY, name, "woody.txt")
{
}

Woody::Woody(const std::string & name, const std::string & ascii) : Toy(Toy::WOODY, name, ascii)
{
}

void		Woody::speak(const std::string & src)
{
  std::cout << "WOODY: " << this->getName() << " \"" << src << "\"" << std::endl;
}
