//
// koaladoctorlist.cpp for doctor in /home/daguen_s/rendu/piscine_cpp_d06/ex05
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Mon Jan 13 21:53:36 2014 daguen_s
// Last update Mon Jan 13 23:29:06 2014 daguen_s
//

#include "koaladoctorlist.h"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor* doctor)
{
  this->doctor = doctor;
  this->next = NULL;
}

KoalaDoctorList::~KoalaDoctorList()
{
}

bool KoalaDoctorList::isEnd()
{
  if (this->next == NULL)
    return (true);
  return (false);
}

void KoalaDoctorList::append(KoalaDoctorList* elem)
{
  KoalaDoctorList *tmp = this;

  while (!(tmp->isEnd()))
    tmp = tmp->next;
  tmp->next = elem;
  elem->next = NULL;
}

KoalaDoctor *KoalaDoctorList::getFromName(std::string name)
{
  if (this->doctor && this->doctor->getName() == name)
    return this->doctor;
  else if (this->next)
    return this->next->getFromName(name);
  return NULL;
}

KoalaDoctorList *KoalaDoctorList::remove(KoalaDoctorList* remove)
{
  KoalaDoctorList *current = this;
  KoalaDoctorList *save = current;
  KoalaDoctorList *previous = NULL;

  if (current->isEnd())
    {
      current->doctor = NULL;
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
	      current->doctor = current->next->doctor;
	      current->next = current->next->next;
	      return current;
	    }
	}
      previous = current;
      current = current->next;
    }
  return NULL;
}

KoalaDoctorList *KoalaDoctorList::removeFromName(std::string remove)
{
  KoalaDoctorList *current = this;
  KoalaDoctorList *save = current;
  KoalaDoctorList *previous = NULL;

  if (current->isEnd())
    {
      current->doctor = NULL;
      return NULL;
    }
  while (current)
    {
      if (current && current->doctor && current->doctor->getName() == remove)
	{
	  if (previous)
	    {
	      previous->next = current->next;
	      current->next = NULL;
	      return this;
	    }
	  else
	    {
	      current->doctor = current->next->doctor;
	      current->next = current->next->next;
	      return current;
	    }
	}
      previous = current;
      current = current->next;
    }
  return NULL;
}

void KoalaDoctorList::dump()
{
  std::cout << "Liste des medecins : ";
  KoalaDoctorList *current = this;
  while (current)
    {
      if (current->doctor)
	std::cout << current->doctor->getName();
      else
	std::cout << "[NULL]";
      if (current->next)
	std::cout << ", ";
      else
	std::cout << "." << std::endl;
      current = current->next;
    }
}
