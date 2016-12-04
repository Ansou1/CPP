/*
** Fruit.h for  in /home/daguen_s/rendu/piscine_cpp_d14m/ex00
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Tue Jan 21 09:33:39 2014 daguen_s
** Last update Tue Jan 21 14:53:35 2014 daguen_s
*/

#ifndef __FRUIT_H__
#define __FRUIT_H__

#include <string>

class		Fruit
{
 protected:
  int		_vitamins;
  std::string	_name;

 public:
  Fruit();
  ~Fruit();

  virtual std::string		getName() const = 0;
  int				getVitamins() const;
  void				setVitamins(int);
};

#endif
