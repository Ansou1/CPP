//
// Exam.cpp for exam in /home/daguen_s/rendu/piscine_cpp_d07m/ex05
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Tue Jan 14 22:30:37 2014 daguen_s
// Last update Tue Jan 14 23:02:04 2014 daguen_s
//

#include <iostream>
#include <string>
#include "Exam.hh"

bool Exam::cheat = false;

Exam::Exam(bool *toto)
{
  this->cheat = *toto;
}

Exam::~Exam()
{
}

void	Exam::start(int nbr)
{
  std::cout << "[The exam is starting]" << std::endl;
  std::cout << nbr << " Klingon vessels appeared out of nowhere." << std::endl;
  std::cout << "they are fully armed and shielded" << std::endl;
  if (this->cheat == false)
    std::cout << "This exam is hard... you lost again." << std::endl;
  if (this->cheat == true)
    std::cout << "What the... someone changed the parameters of the exam !" << std::endl;
}

bool	Exam::isCheating()
{
  return this->cheat;
}
