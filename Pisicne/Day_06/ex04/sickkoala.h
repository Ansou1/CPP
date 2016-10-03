/*
** sickkoala.h for sickkoala.h in /home/daguen_s/rendu/piscine_cpp_d06/ex02
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Mon Jan 13 10:21:15 2014 daguen_s
** Last update Mon Jan 13 13:04:41 2014 daguen_s
*/

#ifndef _SICKKOALA_H_
# define _SICKKOALA_H_

#include <string>

class SickKoala
{
  std::string name;

 public:
  SickKoala(std::string name);
  ~SickKoala();

  void	poke(void);
  bool	takeDrug(std::string drug);
  void	overDrive(std::string sentence);

  std::string getName();
};

#endif /* _SICKKOALA_H_ */
