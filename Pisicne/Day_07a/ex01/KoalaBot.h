/*
** KoalaBot.h for KoalaBot.h in /home/daguen_s/rendu/piscine_cpp_d07a/ex01
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Tue Jan 14 22:08:11 2014 daguen_s
** Last update Wed Jan 15 00:31:41 2014 daguen_s
*/

#ifndef _KOALABOT_H_
# define _KOALABOT_H_

#include <iostream>
#include <string>
#include "Parts.h"

class KoalaBot
{
  std::string		serial;
  Arms			arms;
  Legs			legs;
  Head			head;

 public:
  KoalaBot(std::string seraial = "Bob-01");
  ~KoalaBot();

  void		setParts(Arms &arms);
  void		setParts(Legs &legs);
  void		setParts(Head &head);

  void		swapParts(Arms &arms);
  void		swapParts(Legs &legs);
  void		swapParts(Head &head);

  void		informations() const;
  bool		status() const;
};

#endif /* _KOALABOT_H_ */
