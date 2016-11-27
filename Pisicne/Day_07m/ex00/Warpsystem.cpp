//
// Warpsystem.cpp for Warpsystem.cpp in /home/daguen_s/rendu/piscine_cpp_d07m/ex00
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Tue Jan 14 10:32:58 2014 daguen_s
// Last update Tue Jan 14 13:42:40 2014 daguen_s
//

#include <iostream>
#include <string>
#include "Warpsystem.hh"

WarpSystem::QuantumReactor::QuantumReactor()
{
  this->_stability = true;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{
}

bool	WarpSystem::QuantumReactor::isStable()
{
  return (this->_stability);
}

void	WarpSystem::QuantumReactor::setStability(bool stability)
{
  this->_stability = stability;
}

WarpSystem::Core::Core(QuantumReactor *reactor)
{
  this->_coreReactor = reactor;
}

WarpSystem::Core::~Core()
{
}

WarpSystem::QuantumReactor      *WarpSystem::Core::checkReactor()
{
  return this->_coreReactor;
}
