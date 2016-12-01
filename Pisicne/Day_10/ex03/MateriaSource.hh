//
// MateriaSource.hh for MateriaSource in /home/daguen_s/rendu/piscine_cpp_d10/ex03
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 16:48:03 2014 daguen_s
// Last update Fri Jan 17 17:31:15 2014 daguen_s
//

#ifndef __MATERIASOURCE_H__
#define __MATERIASOURCE_H__

#include <string>
#include <iostream>

#include "AMateria.hh"
#include "IMateriaSource.hh"

class MateriaSource : public IMateriaSource
{
protected:
	AMateria *slots[4];

public:
	MateriaSource();
	~MateriaSource();

	virtual void		learnMateria(AMateria *materia);
	virtual AMateria	*createMateria(std::string const & type);
};

#endif
