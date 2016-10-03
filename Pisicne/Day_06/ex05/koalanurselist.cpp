//
// koalanurselist.cpp for nurse in /home/daguen_s/rendu/piscine_cpp_d06/ex05
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Mon Jan 13 22:12:15 2014 daguen_s
// Last update Mon Jan 13 23:28:27 2014 daguen_s
//

#include "koalanurselist.h"

KoalaNurseList::KoalaNurseList(KoalaNurse* nurse)
{
  this->nurse = nurse;
  this->next = NULL;
}

KoalaNurseList::~KoalaNurseList()
{
}

bool KoalaNurseList::isEnd()
{
  if (this->next == NULL)
    return (true);
  return (false);
}

void KoalaNurseList::append(KoalaNurseList* elem)
{
  KoalaNurseList *tmp = this;

  while (!(tmp->isEnd()))
    tmp = tmp->next;
  tmp->next = elem;
  elem->next = NULL;
}

KoalaNurse *KoalaNurseList::getFromID(int id)
{
  if (this->nurse && this->nurse->getID() == id)
    return this->nurse;
  else if (this->next)
    return this->next->getFromID(id);
  return NULL;
}

KoalaNurseList *KoalaNurseList::remove(KoalaNurseList* remove) {
  KoalaNurseList *current = this;
  KoalaNurseList *save = current;
  KoalaNurseList *previous = NULL;

  if (current->isEnd())
    {
      current->nurse = NULL;
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
	      current->nurse = current->next->nurse;
	      current->next = current->next->next;
	      return current;
	    }
	}
      previous = current;
      current = current->next;
    }
  return NULL;
}

KoalaNurseList *KoalaNurseList::removeFromID(int remove)
{
  KoalaNurseList *current = this;
  KoalaNurseList *save = current;
  KoalaNurseList *previous = NULL;

  if (current->isEnd())
    {
      current->nurse = NULL;
      return NULL;
    }
  while (current)
    {
      if (current && current->nurse && current->nurse->getID() == remove)
	{
	  if (previous)
	    {
	      previous->next = current->next;
	      current->next = NULL;
	      return this;
	    }
	  else
	    {
	      current->nurse = current->next->nurse;
	      current->next = current->next->next;
	      return current;
	    }
	}
      previous = current;
      current = current->next;
    }
  return NULL;
}

void KoalaNurseList::dump()
{
  std::cout << "Liste des infirmieres : ";
  KoalaNurseList *current = this;
  while (current)
    {
      if (current->nurse)
	std::cout << current->nurse->getID();
      else
	std::cout << "[NULL]";
      if (current->next)
	std::cout << ", ";
      else
	std::cout << "." << std::endl;
      current = current->next;
    }
}
