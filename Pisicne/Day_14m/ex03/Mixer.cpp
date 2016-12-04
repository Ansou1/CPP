//
// Mixer.cpp for  in /home/daguen_s/rendu/piscine_cpp_d14m/ex03
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Tue Jan 21 13:26:05 2014 daguen_s
// Last update Tue Jan 21 14:16:25 2014 daguen_s
//

#include "Mixer.h"

int		mixit(FruitBox &src)
{
  FruitNode	*list = src.head();
  int		nbr_vitamine = 0;

  while (list)
    {
      nbr_vitamine += list->f->getVitamins();
      list = list->next;
    }
  return nbr_vitamine;
}

Mixer::Mixer()
{
  this->_plugged = false;
  this->_mixfunc = &mixit;
}

Mixer::~Mixer()
{
}

void	Mixer::connect()
{
  this->_plugged = true;
}
