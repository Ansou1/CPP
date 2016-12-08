/*
** Event.h for  in /home/daguen_s/rendu/piscine_cpp_d16/ex02
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Thu Jan 23 23:14:59 2014 daguen_s
** Last update Fri Jan 24 00:22:22 2014 daguen_s
*/

#ifndef _EVENT_H_
# define _EVENT_H_

#include <string>
#include <iostream>
#include <list>

class Event
{
  unsigned int		_T;
  std::string		_sentence;

 public:
  Event();
  Event(unsigned int, const std::string&);
  ~Event();
  Event(const Event&);
  Event& operator=(const Event&);

  unsigned int getTime() const;
  const std::string& getEvent() const;
  void setTime(unsigned int);
  void setEvent(const std::string&);
};

#endif /* _EVENT_H_ */
