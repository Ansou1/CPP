//
// koalanurse.cpp for KoalaNurse.cpp in /home/daguen_s/rendu/piscine_cpp_d06/ex03
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Mon Jan 13 11:19:44 2014 daguen_s
// Last update Mon Jan 13 16:32:58 2014 daguen_s
//

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include "koalanurse.h"
#include "sickkoala.h"

KoalaNurse::KoalaNurse(int id)
{
  this->id = id;
  this->working = false;
}

KoalaNurse::~KoalaNurse()
{
  std::cout << "Nurse " << this->id << ": Enfin un peu de repos !"  << std::endl;
}

void	KoalaNurse::giveDrug(std::string drug, SickKoala *koala)
{
  koala->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string filename)
{
  std::string drug = std::string();
  std::string koala = filename.substr(0, (strlen(filename.c_str()) - 7));
  std::ifstream file(filename.c_str());

  if (file)
    {
      getline(file, drug);
      std::cout << "Nurse " << this->id << ": Kreog ! Il faut donner un " << drug << " a Mr." << koala << " !" << std::endl;
    }
  file.close();
  return drug;
}

void	KoalaNurse::timeCheck()
{
  if (!this->working)
    std::cout << "Nurse " << this->id << ": Je commence le travail !" << std::endl;
  else
    std::cout << "Nurse " << this->id << ": Je rentre dans ma foret d'eucalyptus !" << std::endl;
  this->working = !this->working;
}
