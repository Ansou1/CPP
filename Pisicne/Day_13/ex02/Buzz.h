/*
** Buzz.h for  in /home/daguen_s/rendu/piscine_cpp_d13/ex02
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Mon Jan 20 10:30:57 2014 daguen_s
** Last update Mon Jan 20 10:42:36 2014 daguen_s
*/

#ifndef _BUZZ_H_
# define _BUZZ_H_

#include "Toy.h"

class Buzz : public Toy
{
 public:
  Buzz(const std::string & name);
  Buzz(const std::string & name, const std::string & ascii);
};

#endif /* _BUZZ_H_ */