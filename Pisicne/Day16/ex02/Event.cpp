//
// Event.cpp for  in /home/daguen_s/rendu/piscine_cpp_d16/ex02
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Thu Jan 23 23:14:56 2014 daguen_s
// Last update Fri Jan 24 00:26:55 2014 daguen_s
//

#include "Event.h"

Event::Event()
{
  _T = 0;
  _sentence = "";
}

Event::Event(unsigned int T, const std::string& sentence)
{
  _T = T;
  _sentence = sentence;
}

Event::~Event()
{
}

Event::Event(const Event& src)
{
  _T = src._T;
  _sentence = src._sentence;
}

Event			&Event::operator=(const Event& src)
{
  _T = src._T;
  _sentence = src._sentence;
  return (*this);
}

unsigned int		Event::getTime() const
{
  return _T;
}

const std::string&	Event::getEvent() const
{
  return _sentence;
}

void			Event::setTime(unsigned int T)
{
  _T = T;
}

void			Event::setEvent(const std::string& sentence)
{
  _sentence = sentence;
}
