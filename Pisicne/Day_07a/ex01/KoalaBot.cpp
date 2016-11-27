//
// KoalaBot.cpp for KoalaBot.cpp in /home/daguen_s/rendu/piscine_cpp_d07a/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Tue Jan 14 22:07:23 2014 daguen_s
// Last update Wed Jan 15 09:48:12 2014 daguen_s
//

#include <iostream>
#include <string>
#include "KoalaBot.h"
#include "Parts.h"

KoalaBot::KoalaBot(std::string serial)
{
  this->serial = serial;
}

KoalaBot::~KoalaBot()
{
}

void	KoalaBot::setParts(Arms &arms)
{
  this->arms = arms;
}

void	KoalaBot::setParts(Legs &legs)
{
  this->legs = legs;
}

void	KoalaBot::setParts(Head &head)
{
  this->head = head;
}

void	KoalaBot::swapParts(Arms &arms)
{
  Arms	tmp;

  tmp = this->arms;
  this->arms = arms;
  arms = tmp;
}

void	KoalaBot::swapParts(Legs &legs)
{
  Legs	tmp;

  legs = this->legs;
  this->legs = legs;
  legs = tmp;
}

void	KoalaBot::swapParts(Head &head)
{
  Head	tmp;

  tmp = this->head;
  this->head = head;
  head = tmp;
}

void	KoalaBot::informations() const
{
  std::cout << "[KoalaBot] " << this->serial << std::endl;
  arms.informations();
  legs.informations();
  head.informations();
}

bool	KoalaBot::status() const
{
  return arms.isFunctionnal() && legs.isFunctionnal() && head.isFunctionnal();
}
