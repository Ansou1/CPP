/*
** koalanurse.h for KoalaNurse.h in /home/daguen_s/rendu/piscine_cpp_d06/ex03
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Mon Jan 13 11:19:57 2014 daguen_s
** Last update Mon Jan 13 12:08:01 2014 daguen_s
*/

#ifndef _KOALANURSE_H_
# define _KOALANURSE_H_

#include <string>
#include "sickkoala.h"

class KoalaNurse
{
  int	id;
  bool  working;

public:
  KoalaNurse(int id);
  ~KoalaNurse();

  void	giveDrug(std::string drug, SickKoala *koala);
  std::string readReport(std::string filename);
  void	timeCheck(void);
};

#endif /* _KOALANURSE_H_ */
