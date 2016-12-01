//
// RadScorpion.cpp for RadScorpion in /home/daguen_s/rendu/piscine_cpp_d10/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 10:25:34 2014 daguen_s
// Last update Fri Jan 17 10:27:36 2014 daguen_s
//

#include "RadScorpion.hh"

RadScorpion::RadScorpion() : AEnemy(80, "RadScorpion")
{
  std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
  std::cout << "* SPROTCH *" << std::endl;
}
