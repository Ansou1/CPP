//
// KreogCom.cpp for KreogCom.cpp in /home/daguen_s/rendu/piscine_cpp_d07a/ex02
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Wed Jan 15 01:28:36 2014 daguen_s
// Last update Wed Jan 15 09:34:06 2014 daguen_s
//

#include <iostream>
#include <string>
#include "KreogCom.h"

KreogCom::KreogCom(int x, int y, int serial)
{
  this->my_x = x;
  this->my_y = y;
  this->m_serial = serial;
  this->next = NULL;
  std::cout << "KreogCom " << serial << " initialised" << std::endl;
}

KreogCom::~KreogCom()
{
  std::cout << "KreogCom " << this->m_serial << " shutting down" << std::endl;
}

void		KreogCom::addCom(int x, int y, int serial)
{
  KreogCom *elem = new KreogCom(x, y, serial);

  elem->next = this->next;
  this->next = elem;
}

KreogCom	*KreogCom::getCom()
{
  return this->next;
}

void		KreogCom::removeCom()
{
  KreogCom	*elem;

  if (this->next)
    {
      elem = this->next;
      this->next = this->next->next;
      delete elem;
    }
}

void		KreogCom::ping() const
{
  if (this)
    std::cout << "KreogCom " << this->m_serial << " currently at " << this->my_x << " " << this->my_y  << std::endl;
}

void		KreogCom::locateSquad() const
{
  KreogCom *tmp = this->next;

  while (tmp)
    {
      tmp->ping();
      tmp = tmp->next;
    }
  ping();
}
