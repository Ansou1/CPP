//
// sickkoalalist.cpp for sickkoalalist in /home/daguen_s/rendu/piscine_cpp_d06/ex05
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Mon Jan 13 21:25:10 2014 daguen_s
// Last update Mon Jan 13 23:27:42 2014 daguen_s
//

#include "sickkoalalist.h"

SickKoalaList::SickKoalaList(SickKoala* koala)
{
  this->koala = koala;
  this->next = NULL;
}

SickKoalaList::~SickKoalaList()
{
}

bool SickKoalaList::isEnd()
{
  if (this->next == NULL)
    return (true);
  return (false);
}

void SickKoalaList::append(SickKoalaList* elem)
{
  SickKoalaList *tmp = this;

  while (!(tmp->isEnd()))
    tmp = tmp->next;
  tmp->next = elem;
  elem->next = NULL;
}

SickKoala *SickKoalaList::getFromName(std::string name)
{
  if (this->koala && this->koala->getName() == name)
    return this->koala;
  else if (this->next)
    return this->next->getFromName(name);
  return NULL;
}

SickKoalaList *SickKoalaList::remove(SickKoalaList* remove)
{
  SickKoalaList *current = this;
  SickKoalaList *save = current;
  SickKoalaList *previous = NULL;

  if (current->isEnd())
    {
      current->koala = NULL;
      return NULL;
    }
  while (current)
    {
      if (current == remove)
 	{
 	  if (previous)
	    {
 	      previous->next = current->next;
 	      current->next = NULL;
 	      return this;
 	    }
 	  else
 	    {
 	      current->koala = current->next->koala;
	      current->next = current->next->next;
 	      return current;
 	    }
	}
      previous = current;
      current = current->next;
    }
  return NULL;
}

SickKoalaList *SickKoalaList::removeFromName(std::string remove)
 {
   SickKoalaList *current = this;
   SickKoalaList *save = current;
   SickKoalaList *previous = NULL;

  if (current->isEnd())
    {
      current->koala = NULL;
      return NULL;
    }
  while (current)
    {
      if (current && current->koala && current->koala->getName() == remove)
	{
	  if (previous)
	    {
	      previous->next = current->next;
	      current->next = NULL;
	      return this;
	    }
	  else
	    {
	      current->koala = current->next->koala;
	      current->next = current->next->next;
	      return current;
	    }
	}
      previous = current;
      current = current->next;
    }
  return NULL;
}

void SickKoalaList::dump()
{
  std::cout << "Liste des patients : ";
  SickKoalaList *current = this;
  while (current)
    {
      if (current->koala)
	std::cout << current->koala->getName();
      else
	std::cout << "[NULL]";
      if (current->next)
	std::cout << ", ";
      else
	std::cout << "." << std::endl;
      current = current->next;
    }
}

SickKoala *SickKoalaList::getContent()
{
  return this->koala;
}

void	*SickKoalaList::getNext()
{
  return this->next;
}
