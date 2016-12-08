/*
** BF_Translator.h for  in /home/daguen_s/rendu/piscine_cpp_d16/ex03
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Thu Jan 23 19:40:27 2014 daguen_s
** Last update Thu Jan 23 21:26:28 2014 daguen_s
*/

#ifndef _BF_TRANSLATOR_H_
# define _BF_TRANSLATOR_H_

#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <exception>

class BF_Translator
{
 protected:
  std::map<char, std::string> commands;

 public:
  BF_Translator();
  virtual ~BF_Translator();

  int translate(std::string in, std::string out);
};

#endif /* _BF_TRANSLATOR_H_ */
