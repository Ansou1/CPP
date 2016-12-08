//
// EventManager.cpp for  in /home/daguen_s/rendu/piscine_cpp_d16/ex02
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Thu Jan 23 23:25:49 2014 daguen_s
// Last update Fri Jan 24 09:03:42 2014 daguen_s
//

#include <list>
#include "EventManager.h"


EventManager::EventManager()
{
  current_time = 0;
}

EventManager::~EventManager()
{
}

EventManager::EventManager(EventManager const &src)
{
  _event(src);
}

EventManager		&EventManager::operator=(EventManager const &src)
{
  _event = src._event;
  return (*this);
}

void			EventManager::addEvent(const Event& src)
{
  _event.push_front(src);
}

void			EventManager::removeEventsAt(unsigned int index)
{
  for (std::list<Event>::iterator it = _event.begin(); it != _event.end(); ++it)
    {
      if (index == (*it).getTime())
	_event.erase(index);
    }
}

void			EventManager::dumpEvents() const
{
  _event.sort();
  for (std::list<Event>::iterator it = _event.begin(); it != _event.end(); ++it)
    {
      std::cout << (*it).getTime() << ": " << (*it).getEvent()  << std::endl;
    }
}

void			EventManager::dumpEventAt(unsigned int index) const
{
  for (std::list<Event>::iterator it = _event.begin(); it != _event.end(); ++it)
    {
      if (index == (*it).getTime())
	std::cout << (*it).getTime() << ": " << (*it).getEvent()  << std::endl;
    }
}

void			EventManager::addTime(unsigned int time;);
{
  current_time += time;
  _event.sort();
  for (std::list<Event>::iterator it = _event.begin(); it != _event.end(); ++it)
    {
      std::cout << (*it).getTime() << ": " << (*it).getEvent()  << std::endl;
      if (current_time > (*it).getTime())
	_event.erase(index);
    }
}

void			EventManager::addEventList(std::list<Event>&);
{
}
