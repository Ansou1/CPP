//
// droidmemory.cpp for droidmemory.cpp in /home/daguen_s/rendu/piscine_cpp_d08/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Wed Jan 15 11:58:48 2014 daguen_s
// Last update Wed Jan 15 19:52:54 2014 daguen_s
//

#include <string>
#include <iostream>
#include <stdlib.h>
#include "droid.hh"
#include "droidmemory.hh"

DroidMemory::DroidMemory()
{
  this->FingerPrint = random();
  this->Exp = 0;
}

DroidMemory::DroidMemory(DroidMemory const &src)
{
  this->FingerPrint = src.getFingerPrint();
  this->Exp = src.getExp();;
}

DroidMemory::~DroidMemory()
{
}

void	DroidMemory::setFingerPrint(size_t FingerPrint)
{
  this->FingerPrint = FingerPrint;
}

void	DroidMemory::setExp(size_t Exp)
{
  this->Exp = Exp;
}

size_t	DroidMemory::getFingerPrint() const
{
  return this->FingerPrint;
}

size_t	DroidMemory::getExp() const
{
  return this->Exp;
}

DroidMemory	&DroidMemory::operator<<(DroidMemory const &src)
{
  this->Exp += src.Exp;
  this->FingerPrint = this->FingerPrint ^ src.FingerPrint;
  return (*this);
}

DroidMemory	&DroidMemory::operator>>(DroidMemory &src)
{
  src.Exp = src.Exp + this->Exp;
  src.FingerPrint = src.FingerPrint ^ this->FingerPrint;
  return (src);
}

DroidMemory	&DroidMemory::operator+=(DroidMemory const &src)
{
  this->Exp = this->Exp + src.Exp;
  this->FingerPrint = this->FingerPrint ^ src.FingerPrint;
  return (*this);
}

DroidMemory	&DroidMemory::operator+=(size_t const &src)
{
  this->Exp += src;
  this->FingerPrint = this->FingerPrint ^ src;
  return (*this);
}

DroidMemory	&DroidMemory::operator+(DroidMemory const &src) const
{
  DroidMemory *_new = new DroidMemory();

  _new->setExp(this->Exp + src.Exp);
  _new->setFingerPrint(this->FingerPrint ^ src.FingerPrint);
  return (*_new);
}

DroidMemory	&DroidMemory::operator+(size_t const &src) const
{
  DroidMemory *_new = new DroidMemory();

  _new->setExp(this->Exp + src);
  _new->setFingerPrint(this->FingerPrint ^ src);
  return (*_new);
}

std::ostream& operator<<(std::ostream &os, DroidMemory const &dm)
{
  os << "DroidMemory '" << dm.getFingerPrint() << "', " << dm.getExp();
  return os;
}

bool          DroidMemory::operator==(DroidMemory const &src) const
{
  return ((this->FingerPrint == src.FingerPrint) && (this->Exp == src.Exp));
}

bool          DroidMemory::operator!=(DroidMemory const &src) const
{
  return ((this->FingerPrint != src.FingerPrint) || (this->Exp != src.Exp));
}

bool          DroidMemory::operator<(DroidMemory const &src) const
{
  return (this->Exp < src.Exp);
}

bool          DroidMemory::operator<=(DroidMemory const &src) const
{
  return (this->Exp <= src.Exp);
}

bool          DroidMemory::operator>(DroidMemory const &src) const
{
  return (this->Exp > src.Exp);
}

bool          DroidMemory::operator>=(DroidMemory const &src) const
{
  return (this->Exp >= src.Exp);
}

bool          DroidMemory::operator<(size_t const &src) const
{
  return (this->Exp < src);
}

bool          DroidMemory::operator<=(size_t const &src) const
{
  return (this->Exp <= src);
}

bool          DroidMemory::operator>(size_t const &src) const
{
  return (this->Exp > src);
}

bool          DroidMemory::operator>=(size_t const &src) const
{
  return (this->Exp >= src);
}
