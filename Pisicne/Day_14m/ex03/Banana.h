/*
** Banana.h for  in /home/daguen_s/rendu/piscine_cpp_d14m/ex00
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Tue Jan 21 09:33:02 2014 daguen_s
** Last update Tue Jan 21 10:05:41 2014 daguen_s
*/

#ifndef __BANANA_H__
#define __BANANA_H__

#include <string>
#include "Fruit.h"

class		Banana : public Fruit
{
 public:
  Banana();
  ~Banana();

  virtual std::string		getName() const;
};

#endif
