//
// search_value.cpp for  in /home/daguen_s/rendu/piscine_cpp_d06/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sat Jan 25 10:27:58 2014 daguen_s
// Last update Sat Jan 25 15:47:44 2014 daguen_s
//

#include <iostream>
#include <fstream>
#include <errno.h>
#include <vector>
#include <iterator>
#include <string>
#include <string.h>
#include <algorithm>

std::vector<std::string>	&search_value(const std::string &file_name, const std::string &to_find)
{
  std::ifstream			fichier(file_name.c_str());
  std::vector<std::string>	*t = new std::vector<std::string>();

  if (fichier)
    {
      std::string		line;
      std::string		str;
      unsigned int		a = 1;

      while (getline(fichier, line))
	{
	  if (line.compare(0, to_find.size(), to_find) == 0)
	    {
	      a = 1;
	      a += line.find(":");
	      while (line.c_str()[a++] == ' ' || line.c_str()[a] == '\t');
	      a--;
	      str = line.substr(a, line.size());
	      t->push_back(str);
	    }
	}
      fichier.close();
    }
  else
    std::cerr << "File: <" << file_name << ">: " << strerror(errno) << std::endl;
  return *t;
}
