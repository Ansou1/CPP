//
// main.cpp for main in /home/falcon_j/tp/nibbler
//
// Made by jeremy falconnier
// Login   <falcon_j@epitech.net>
//
// Started on  Wed Mar 19 16:17:02 2014 jeremy falconnier
// Last update Thu Apr  3 20:13:58 2014 daguen_s
//

#include "core.hh"
#include <stdlib.h>
#include "displaymodule.h"
#include <iostream>
#include "dlloader.h"

int	main(int argc, char **argv)
{
  if (argc != 4)
    {
      std::cerr << "Usage ./nibbler MapSizeX MapSizeY " << std::endl;
      return (EXIT_FAILURE);
    }
  try
    {
      Core test(argv[1], argv[2]);
      IDisplayModule *obj;
      Dlloader lib;
      lib.load(argv[3]);
      obj = lib.getObj();
      test.game(obj);
      delete obj;
    }
  catch (const std::exception & e)
    {
      std::cerr << e.what() << std::endl;
    }
  return (EXIT_SUCCESS);
}
