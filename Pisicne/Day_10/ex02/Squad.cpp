//
// Squad.cpp for Squad in /home/daguen_s/rendu/piscine_cpp_d10/ex02
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 17 11:23:57 2014 daguen_s
// Last update Sat Jan 18 09:36:47 2014 daguen_s
//

#include "Squad.hh"

Squad::Squad()
{
}

Squad::Squad(Squad const &copy)
{
  this->soldier.assign(copy.soldier.begin(), copy.soldier.end());
}

Squad::~Squad()
{
  for(unsigned int i(0); i < this->soldier.size(); ++i)
    {
      delete this->soldier[i];
      this->soldier[i] = NULL;
    }
}

int		Squad::getCount() const
{
  return this->soldier.size();
}

ISpaceMarine	*Squad::getUnit(int position)
{
  return this->soldier.at(position + 1);
}

int		Squad::push(ISpaceMarine *marine)
{
  this->soldier.push_back(marine);
  return this->soldier.size();
}

Squad		&Squad::operator=(Squad const & copy)
{
  for(unsigned int i(0); i < this->soldier.size(); ++i)
    {
      delete this->soldier[i];
      this->soldier[i] = NULL;
    }
  this->soldier.assign(copy.soldier.begin(), copy.soldier.end());
  return (*this);
}
