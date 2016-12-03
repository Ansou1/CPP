//
// Picture.cpp for  in /home/daguen_s/rendu/piscine_cpp_d13/ex00
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Mon Jan 20 09:01:21 2014 daguen_s
// Last update Mon Jan 20 15:10:35 2014 daguen_s
//

#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include "Picture.h"

Picture::Picture()
{
  this->data = "";
}

Picture::Picture(const std::string &file)
{
  if (!(this->getPictureFromFile(file)))
    this->data = "ERROR";
}

Picture::Picture(const Picture &src)
{
  this->data = src.data;
}

Picture		&Picture::operator=(Picture const &src)
{
  this->data = src.data;
  return (*this);
}

Picture::~Picture()
{
}

bool		Picture::getPictureFromFile(const std::string &file)
{
  std::ifstream		f(file.c_str());
  bool			success = false;
  char			c;

  this->data.clear();
  if (f.is_open())
    {
      while (f.good())
	{
	  c = f.get();
	  if (f.good())
	    this->data = this->data + c;
	}
      f.close();
      success = true;
    }
  if (!success)
    this->data = "ERROR";
  return (success);
}
