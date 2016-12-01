//
// SuperMutant.cpp for SuperMutant in /home/daguen_s/rendu/piscine_cpp_d10/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 10:18:36 2014 daguen_s
// Last update Fri Jan 17 10:55:21 2014 daguen_s
//

#include "SuperMutant.hh"
#include "AEnemy.hh"

SuperMutant::SuperMutant() : AEnemy(170, "Super Mutant")
{
  std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant()
{
  std::cout << "Aaargh ..." << std::endl;
}

void		SuperMutant::takeDamage(int _damage)
{
  AEnemy::takeDamage(_damage - 3);
}
