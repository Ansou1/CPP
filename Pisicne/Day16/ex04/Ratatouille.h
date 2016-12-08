/*
** Ratatouille.h for  in /home/daguen_s/rendu/piscine_cpp_d16/ex04
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Thu Jan 23 17:57:56 2014 daguen_s
** Last update Thu Jan 23 18:04:24 2014 daguen_s
*/

#ifndef _RATATOUILLE_H_
# define _RATATOUILLE_H_

#include <iostream>
#include <string>
#include <sstream>

class Ratatouille
{
  std::string		str;

 public:
  Ratatouille();
  Ratatouille(Ratatouille const &);
  Ratatouille			&operator=(const Ratatouille &);
  ~Ratatouille();

  Ratatouille &addVegetable(unsigned char);
  Ratatouille &addCondiment(unsigned int);
  Ratatouille &addSpice(double);
  Ratatouille &addSauce(const std::string &);

   std::string kooc(void);
};

#endif /* _RATATOUILLE_H_ */
