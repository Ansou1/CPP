/*
** EventManager.h for  in /home/daguen_s/rendu/piscine_cpp_d16/ex02
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Thu Jan 23 23:25:44 2014 daguen_s
** Last update Fri Jan 24 00:56:41 2014 daguen_s
*/

#ifndef _EVENTMANAGER_H_
# define _EVENTMANAGER_H_

#include <iostream>
#include <string>
#include <list>
#include "Event.h"

class EventManager
{
 public:
  std::list<Event>	_event;
  unsigned int		current_time;

  EventManager();
  ~EventManager();
  EventManager(EventManager const &);
  EventManager& operator=(EventManager const &);


  void			addEvent(const Event&);
  void			removeEventsAt(unsigned int);
  void			dumpEvents(void) const;
  void			dumpEventAt(unsigned int) const;
  void			addTime(unsigned int);
  void			addEventList(std::list<Event>&);
};

#endif /* _EVENTMANAGER_H_ */
