/*
** Woody.h for  in /home/daguen_s/rendu/piscine_cpp_d13/ex02
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Mon Jan 20 10:41:44 2014 daguen_s
** Last update Mon Jan 20 14:13:03 2014 daguen_s
*/

#ifndef _WOODY_H_
# define _WOODY_H_

#include "Toy.h"

class Woody : public Toy
{
 public:
  Woody(const std::string & name);
  Woody(const std::string & name, const std::string & ascii);

  bool			speak(const std::string &);
};

#endif /* _WOODY_H_ */
