//
// main.cpp for ex_00 in /home/daguen_s/rendu/piscine_cpp_d06/ex00
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Mon Jan 13 09:16:54 2014 daguen_s
// Last update Sat Jan 25 10:42:24 2014 daguen_s
//

#include <iostream>
#include <fstream>
#include <errno.h>
#include <string.h>

int	main(int ac, char **av)
{
  if (ac > 1)
    {
      int i = 1;
      while (i < ac)
	{
	  std::ifstream fichier(av[i]);
	  if (fichier)
	    {
	      std::cout << fichier.rdbuf();
	      fichier.close();
	    }
	  else
	    std::cerr << "my_cat: <" << av[i] << ">: " << strerror(errno) << std::endl;
	  i++;
	}
    }
  else
    std::cout << "my_cat: Usage : ./my_cat file [...]" << std::endl;
  return (0);
}
