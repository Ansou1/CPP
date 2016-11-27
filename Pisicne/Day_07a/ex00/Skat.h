/*
** Skat.h for Skat.h in /home/daguen_s/rendu/piscine_cpp_d07a/ex00
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Tue Jan 14 18:29:14 2014 daguen_s
** Last update Tue Jan 14 19:42:35 2014 daguen_s
*/

#ifndef _SKAT_H_
# define _SKAT_H_

#include <string>
#include <iostream>

class Skat
{
  std::string		_name;
  int			stimpaks;

 public:
  Skat(std::string const &_name = "bob", int stimpaks = 15);
  ~Skat();

  int			&stimPaks();
  const	std::string	&name();

  void			shareStimPaks(int number, int &stock);
  void			addStimPaks(unsigned int number);
  void			useStimPaks();
  void			status();
};

#endif /* _SKAT_H_ */
