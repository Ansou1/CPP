//
// ToyStory.cpp for  in /home/daguen_s/rendu/piscine_cpp_d13/ex06
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Mon Jan 20 14:51:34 2014 daguen_s
// Last update Tue Jan 21 08:57:59 2014 daguen_s
//

#include <string.h>
#include "ToyStory.h"

ToyStory::ToyStory()
{
}

ToyStory::~ToyStory()
{
}

bool	ToyStory::tellMeAStory(const std::string &file_name, Toy &first, bool (Toy::*ptr1)(std::string const &str), Toy &second, bool (Toy::*ptr2)(std::string const &str))
{
  std::ifstream		file(file_name.c_str());

  if (file.is_open())
    {
      if(first.getAscii() != "ERROR")
	std::cout << first.getAscii() << std::endl;
      if(second.getAscii() != "ERROR")
	std::cout << second.getAscii() << std::endl;

      bool		print = true;
      std::string	ligne;
      while (getline(file, ligne))
	{
	  if (strncmp("picture:", ligne.c_str(), 8) == 0)
	    {
	      ligne = ligne.substr(8, (strlen(ligne.c_str())));
	      if (print == true)
		{
		  if (!(first.setAscii(ligne)))
		    {
		      Toy::Error e = first.getLastError();
		      std::cout << e.where() << ": " << e.what() << std::endl;
		      return false;
		    }
		  else
		    std::cout << first.getAscii() << std::endl;
		}
	      else
		{
		  if (!(second.setAscii(ligne)))
		    {
		      Toy::Error e = second.getLastError();
		      std::cout << e.where() << ": " << e.what() << std::endl;
		      return false;
		    }
		  else
		    std::cout << second.getAscii() << std::endl;
		}
	    }
	  if (true)
	    {
	      if (print == true)
		if ((first.*ptr1)(ligne) == false)
		  {
		    Toy::Error e = first.getLastError();
		    std::cout << e.where() << ": " << e.what() << std::endl;
		    return false;
		  }
	      if (print == false)
		if ((second.*ptr2)(ligne) == false)
		  {
		    Toy::Error e = second.getLastError();
		    std::cout << e.where() << ": " << e.what() << std::endl;
		    return false;
		  }
	    }
	  print = (print == false) ? true : false;
	}
      file.close();
      return true;
    }
  else
    {
      std::cout << "Bad Story" << std::endl;
      return false;
    }
}
