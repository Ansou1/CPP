/*
** ToyStory.h for  in /home/daguen_s/rendu/piscine_cpp_d13/ex06
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Mon Jan 20 14:52:22 2014 daguen_s
** Last update Mon Jan 20 16:30:56 2014 daguen_s
*/

#ifndef _TOYSTORY_H_
# define _TOYSTORY_H_

#include "Toy.h"
#include <string>
#include <fstream>

class ToyStory
{
public:
ToyStory();
~ToyStory();

 static bool		tellMeAStory(const std::string &, Toy &, bool (Toy::*ptr1)(std::string const &), Toy &, bool (Toy::*ptr2)(std::string const &));
};

#endif /* _TOYSTORY_H_ */


