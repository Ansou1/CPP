//
// MateriaSource.cpp for MateraSource in /home/daguen_s/rendu/piscine_cpp_d10/ex03
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 16:45:21 2014 daguen_s
// Last update Fri Jan 17 17:31:02 2014 daguen_s
//

#include "MateriaSource.hh"

MateriaSource::MateriaSource()
{
  int i;

  for(i = 0; i < 4; i++)
    slots[i] = NULL;
}

MateriaSource::~MateriaSource()
{
  int i;

  for(i = 0; i < 4; i++)
    {
      if (slots[i])
	  delete slots[i];
    }
}

void MateriaSource::learnMateria(AMateria* materia)
{
  int i;

  if (materia)
    {
      for (i = 0; i < 4; i++)
	{
	  if (!slots[i])
	    {
	      slots[i] = materia;
	      return;
	    }
	}
    }
}

AMateria *MateriaSource::createMateria(std::string const & type)
{
  int i;

  for (i = 0; i < 4; i++)
    {
      if (slots[i] && slots[i]->getType() == type)
	  return slots[i]->clone();
    }
  return NULL;
}
