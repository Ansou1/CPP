//
// sickkoala.cpp for sickkoala.cpp in /home/daguen_s/rendu/piscine_cpp_d06/ex02
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Mon Jan 13 10:24:22 2014 daguen_s
// Last update Mon Jan 13 16:31:07 2014 daguen_s
//

#include <string>
#include <iostream>
#include <string.h>
#include "sickkoala.h"

SickKoala::SickKoala(std::string name)
{
  this->name = name;
}

SickKoala::~SickKoala()
{
  std::cout << "Mr." << this->name << ": Kreooogg !! Je suis gueriiii !" << std::endl;
}

void	SickKoala::poke()
{
  std::cout << "Mr." << this->name << ": Gooeeeeerrk !! :'(" << std::endl;
}

bool	SickKoala::takeDrug(std::string drug)
{
  std::string new_drug("");
  int	i = 0;

  while (drug[i])
    new_drug += std::tolower(drug[i++]);
  if (new_drug == "mars")
    {
      std::cout << "Mr." << this->name << ": Mars, et ca Kreog !" << std::endl;
      return true;
    }
  else if (new_drug == "buronzand" && drug == "Buronzand")
    {
      std::cout << "Mr." << this->name << ": Et la fatigue a fait son temps !" << std::endl;
      return true;
    }
  else
    {
      std::cout << "Mr." << this->name << ": Goerk !" << std::endl;
      return false;
    }
}

void	SickKoala::overDrive(std::string sentence)
{
  size_t find = strlen("Kreog !");
  size_t replace = strlen("1337 !");
  size_t pos = 0;

  while ((pos = sentence.find("Kreog !", pos)) != std::string::npos)
    {
      sentence.replace(pos, find, "1337 !");
      pos += replace;
    }
  std::cout << "Mr." << this->name << ": " << sentence << std::endl;
}

std::string	SickKoala::getName()
{
  return this->name;
}
