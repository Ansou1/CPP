/*
** Toy.h for  in /home/daguen_s/rendu/piscine_cpp_d13/ex00
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Mon Jan 20 09:05:27 2014 daguen_s
** Last update Mon Jan 20 09:48:49 2014 daguen_s
*/

#ifndef _TOY_H_
# define _TOY_H_

#include "Picture.h"

class Toy
{
 public:
  enum ToyType {BASIC_TOY, ALIEN};

 private:
  ToyType		type;
  std::string		name;
  Picture		image;

 public:
  Toy();
  Toy(ToyType type, const std::string & name, const std::string & file);
  ~Toy();

  int			getType() const;
  std::string		getName() const;
  std::string		getAscii() const;

  void			setName(const std::string &name);
  bool			setAscii(const std::string &file);
};


#endif /* _TOY_H_ */
