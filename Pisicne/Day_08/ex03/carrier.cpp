//
// carrier.cpp for carrier.cpp in /home/daguen_s/rendu/piscine_cpp_d08/ex03
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Wed Jan 15 17:33:45 2014 daguen_s
// Last update Wed Jan 15 21:59:29 2014 daguen_s
//

#include <iostream>
#include <string>
#include <cstring>
#include "carrier.hh"

Carrier::Carrier(std::string const &Id, size_t const &Energy) : Attack(100), Toughness(90)
{
  this->Id = Id;
  this->Energy = Energy;
  this->Speed = 0;

  unsigned int i = 0;
  while (i < 5)
    {
      this->Droids[i] = NULL;
      i++;
    }
}

Carrier::~Carrier()
{
}

void	Carrier::operator<<(Droid *droid)
{
  unsigned int i = 0;

  while (i < 5 && this->Droids[i] == NULL)
    ++i;
  if (i == 5)
    this->Speed = 100;
  i = 0;
  while (i < 5 && this->Droids[i] == NULL)
    ++i;
  if (i != 5)
    {
      this->Droids[i] = droid;
      this->Speed -=10;
    }
}

void	Carrier::operator>>(Droid *droid)
{
  unsigned int i = 0;

  while (i < 5 && this->Droids[i] == droid)
    ++i;
  if (i != 5)
    {
      this->Speed += 10;
      this->Droids[i] = NULL;
    }
  i = 0;
  while (i < 5 && this->Droids[i] == NULL)
    ++i;
  if (i == 5)
    this->Speed = 0;
}

Droid	*Carrier::operator[](int const &val)
{
  return this->Droids[val];
}

Carrier	*Carrier::operator~()
{
  unsigned int i = 0;
  unsigned int count = 0;

  while (i < 5 && this->Droids[i] == NULL)
    {
      count++;
      i++;
    }

  if (cout == 0)
    this->Energy = 0;
  else
    this->Energy = 100 - (count * 10);
  return this;
}

bool Carrier::operator()(int const &x, int const &y)
{
  (abs(x) + abs(y)) * (10 + (NbDroid))
}

size_t Carrier::getEnergy() const
{
  return (this->Energy);
}

size_t Carrier::getSpeed() const
{
  return (this->Speed);
}

void Carrier::setEnergy(size_t e)
{
  this->Energy = e;
}

void Carrier::setSpeed(size_t s)
{
  this->Speed = s;
}
