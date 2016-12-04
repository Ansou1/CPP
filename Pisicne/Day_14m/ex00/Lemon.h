/*
** Lemon.h for  in /home/daguen_s/rendu/piscine_cpp_d14m/ex00
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Tue Jan 21 09:36:13 2014 daguen_s
** Last update Tue Jan 21 10:06:30 2014 daguen_s
*/

#ifndef _LEMON_H_
# define _LEMON_H_

#include <string>
#include "Fruit.h"

class Lemon : public Fruit
{
 public:
  Lemon();
  ~Lemon();

  virtual std::string	getName() const;
};

#endif /* _LEMON_H_ */
