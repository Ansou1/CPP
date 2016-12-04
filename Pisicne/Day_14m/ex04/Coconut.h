/*
** Coconut.h for  in /home/daguen_s/rendu/piscine_cpp_d14m/ex02
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Tue Jan 21 11:25:10 2014 daguen_s
** Last update Tue Jan 21 11:40:49 2014 daguen_s
*/

#ifndef _COCONUT_H_
# define _COCONUT_H_

#include "Fruit.h"

class Coconut : public Fruit
{
 public:
  Coconut();
  ~Coconut();

  virtual std::string	getName() const;
};

#endif /* _COCONUT_H_ */
