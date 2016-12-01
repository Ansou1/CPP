//
// Character.hh for Character in /home/daguen_s/rendu/piscine_cpp_d10/ex03
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 16:33:39 2014 daguen_s
// Last update Fri Jan 17 17:29:56 2014 daguen_s
//

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <string>
#include <iostream>

#include "ICharacter.hh"
#include "AMateria.hh"

class Character : public ICharacter
{
protected:
	AMateria *slots[4];
	std::string name;

public:
	Character(std::string const & name);
	Character(Character const & perso);
	~Character();

	virtual std::string const & getName() const;
	virtual void equip(AMateria * materia);
	virtual void unequip(int index);
	virtual void use(int index, ICharacter & target);
};

#endif
