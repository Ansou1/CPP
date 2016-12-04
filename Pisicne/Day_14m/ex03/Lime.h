/*
** Lime.h for  in /home/daguen_s/rendu/piscine_cpp_d14m/ex01
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Tue Jan 21 10:25:47 2014 daguen_s
** Last update Tue Jan 21 10:35:54 2014 daguen_s
*/

#ifndef _LIME_H_
# define _LIME_H_

#include "Lemon.h"

class Lime : public Lemon
{
 public:
  Lime();
  ~Lime();

  virtual std::string		getName() const;
};

#endif /* _LIME_H_ */
