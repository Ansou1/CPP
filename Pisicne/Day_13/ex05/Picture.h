/*
** Picture.h for  in /home/daguen_s/rendu/piscine_cpp_d13/ex00
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Mon Jan 20 08:58:34 2014 daguen_s
** Last update Mon Jan 20 10:08:50 2014 daguen_s
*/

#ifndef _PICTURE_H_
# define _PICTURE_H_

#include <iostream>
#include <string>

class Picture
{
 public:
  Picture(const std::string &file);
  Picture();
  Picture(const Picture &);
  ~Picture();

  std::string		data;
  bool			getPictureFromFile(const std::string &file);

  Picture		&operator=(Picture const &);
};

#endif /* _PICTURE_H_ */
