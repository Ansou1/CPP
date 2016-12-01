//
// Cure.hh for Cure in /home/daguen_s/rendu/piscine_cpp_d10/ex03
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 16:35:22 2014 daguen_s
// Last update Fri Jan 17 17:30:10 2014 daguen_s
//

#ifndef __CURE_H__
#define __CURE_H__

#include <string>
#include <iostream>

#include "AMateria.hh"
#include "ICharacter.hh"

class Cure : public AMateria
{
protected:

public:
	Cure();
	Cure(Cure const & cure);
	~Cure();

	virtual AMateria * clone() const;
	virtual void effect(ICharacter & target);

};

#endif
