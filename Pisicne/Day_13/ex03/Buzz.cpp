//
// Buzz.cpp for  in /home/daguen_s/rendu/piscine_cpp_d13/ex02
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Mon Jan 20 10:32:57 2014 daguen_s
// Last update Mon Jan 20 11:13:50 2014 daguen_s
//

#include "Buzz.h"

Buzz::Buzz(const std::string & name) : Toy(Toy::BUZZ, name, "buzz.txt")
{
}

Buzz::Buzz(const std::string & name, const std::string & ascii) : Toy(Toy::BUZZ, name, ascii)
{
}

void		Buzz::speak(const std::string & src)
{
  std::cout << "BUZZ: " << this->getName() << " \"" << src << "\"" << std::endl;
}
