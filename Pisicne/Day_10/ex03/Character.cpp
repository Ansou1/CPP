//
// Character.cpp for Character in /home/daguen_s/rendu/piscine_cpp_d10/ex03
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 16:29:35 2014 daguen_s
// Last update Fri Jan 17 17:29:51 2014 daguen_s
//

#include "Character.hh"

Character::Character(std::string const & name)
{
  int i;

  this->name = name;
  for (i = 0; i < 4; i++)
    slots[i] = NULL;
}

Character::Character(Character const & perso)
{
  int i;

  this->name = perso.name;
  for (i = 0; i < 4; i++)
    {
      if (slots[i])
	delete slots[i];
      slots[i] = NULL;
      if (perso.slots[i])
	slots[i] = perso.slots[i]->clone();
    }
}

Character::~Character()
{
  int i;

  for(i = 0; i < 4; i++)
    {
      if (slots[i])
	delete slots[i];
    }
}

std::string const &	Character::getName() const
{
  return this->name;
}

void			Character::equip(AMateria* materia)
{
  int i;

  if (materia)
    {
      for(i = 0; i < 4; i++)
	{
	  if (slots[i] == NULL)
	    {
	      slots[i] = materia;
	      return;
	    }
	}
    }
}

void			Character::unequip(int index)
{
  if (index >= 0 && index < 4)
    slots[index] = NULL;
}

void			Character::use(int index, ICharacter& target)
{
  if (index >= 0 && index < 4 && slots[index] != NULL)
      slots[index]->use(target);
}
