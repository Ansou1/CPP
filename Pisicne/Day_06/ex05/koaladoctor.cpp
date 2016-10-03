//
// koaladoctor.cpp for koaladoctor.cpp in /home/daguen_s/rendu/piscine_cpp_d06/ex04
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Mon Jan 13 12:19:30 2014 daguen_s
// Last update Mon Jan 13 14:26:39 2014 daguen_s
//

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "koaladoctor.h"
#include "sickkoala.h"

KoalaDoctor::KoalaDoctor(std::string name)
{
  this->name = name;
  this->working = false;
  std::cout << "Dr." << this->name << ": Je suis le Dr." << this->name << " ! Comment Kreoggez-vous ?" << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{
}

void	KoalaDoctor::diagnose(SickKoala *koala)
{
  std::string tab[5] = {"mars", "Buronzand", "Viagra", "Extasy", "Feuille d’eucalyptus"};
  std::string report;

  std::cout << "Dr." << this->name << ": Alors, qu'est-ce qui vous goerk, Mr." << koala->getName() << " ?" << std::endl;
  koala->poke();

  report = koala->getName().append(".report");
  std::ofstream file(report.c_str());

  file << tab[random() % 5];
  file.close();
}


void	KoalaDoctor::timeCheck()
{
  if (!this->working)
    std::cout << "Dr." << this->name << ": Je commence le travail !" << std::endl;
  else
    std::cout << "Dr." << this->name << ": Je rentre dans ma foret d'eucalyptus !" << std::endl;
  this->working = !this->working;
}

std::string KoalaDoctor::getName()
{
  return this->name;
}
