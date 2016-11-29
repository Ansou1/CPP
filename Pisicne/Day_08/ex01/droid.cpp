//
// droid.cpp for droid in /home/daguen_s/rendu/piscine_cpp_d08/ex00
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Wed Jan 15 09:52:13 2014 daguen_s
// Last update Wed Jan 15 22:16:39 2014 daguen_s
//

#include <iostream>
#include <string>
#include "droid.hh"
#include "droidmemory.hh"

Droid::Droid(std::string id) : attack(25), toughness(15)
{
  this->battleData = new DroidMemory();
  this->id = id;
  this->energy = 50;
  this->status = new std::string("Standing by");
  std::cout << "Droid '" << id << "' Activated" << std::endl;
}

Droid::Droid(Droid const &src) : attack(25), toughness(15)
{
  this->id = src.id;
  this->energy = src.energy;
  this->status = new std::string(*(src.status));
  this->battleData = new DroidMemory();
  if (src.getBattleData())
    {
      (this->battleData)->setFingerPrint((src.getBattleData())->getFingerPrint());
      (this->battleData)->setExp((src.getBattleData())->getExp());
    }
  std::cout << "Droid '" << this->id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
  if (this->status)
    delete this->status;
  if (this->battleData)
    delete this->battleData;
  std::cout << "Droid '" << this->id << "' Destroyed" << std::endl;
}

void	Droid::setId(std::string id)
{
  this->id = id;
}

std::string	Droid::getId() const
{
  return this->id;
}

void	Droid::setEnergy(size_t energy)
{
  this->energy = energy;
}

size_t	Droid::getEnergy() const
{
  return this->energy;
}

size_t Droid::getAttack() const
{
  return this->attack;
}

size_t Droid::getToughness() const
{
  return this->toughness;
}

void Droid::setStatus(std::string *status)
{
  if (this->status)
    delete this->status;
  this->status = status;
}

std::string *Droid::getStatus() const
{
  return this->status;
}

Droid&	Droid::operator=(Droid const &src)
{
  if (&src != this)
    {
      this->id = src.id;
      this->energy = src.energy;
      if (this->status)
	delete
	  this->status;
      this->status = new std::string(*(src.status));
      if (this->battleData)
	delete this->battleData;
      this->battleData = new DroidMemory();
      if (src.getBattleData())
	{
	  (this->battleData)->setFingerPrint((src.getBattleData())->getFingerPrint());
	  (this->battleData)->setExp((src.getBattleData())->getExp());
	}
    }
  return (*this);
}

bool	Droid::operator==(Droid const &droid) const
{
  return (*(this->status) == *(droid.getStatus()));
}

bool	Droid::operator!=(Droid const &droid) const
{
  return (*(this->status) != *(droid.getStatus()));
}

Droid	&Droid::operator<<(size_t &chrg)
{
  size_t recharge = 100 - this->energy;

  if (recharge > chrg)
    recharge = chrg;
  this->energy = this->energy + recharge;
  chrg = chrg - recharge;
  if (this->energy > 100)
    this->energy = 100;
  return (*this);
}

std::ostream	&operator<<(std::ostream &os, Droid const &droid)
{
  os << "Droid '" << droid.getId() << "', " << *(droid.getStatus()) << ", " << droid.getEnergy();
  return (os);
}

DroidMemory	*Droid::getBattleData() const
{
  return this->battleData;
}

void		Droid::setBattleData(DroidMemory * src)
{
  this->battleData = src;
}
