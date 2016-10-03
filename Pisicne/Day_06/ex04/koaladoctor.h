/*
** koaladoctor.h for koaladoctor.h in /home/daguen_s/rendu/piscine_cpp_d06/ex04
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Mon Jan 13 12:19:48 2014 daguen_s
** Last update Mon Jan 13 13:53:34 2014 daguen_s
*/

#ifndef _KOALADOCTOR_H_
# define _KOALADOCTOR_H_

#include <string>
#include "sickkoala.h"

class KoalaDoctor
{
  std::string	name;
  bool		working;

 public:
  KoalaDoctor(std::string name);
  ~KoalaDoctor();

  void	diagnose(SickKoala *koala);
  void	timeCheck(void);
};

#endif /* _KOALADOCTOR_H_ */
