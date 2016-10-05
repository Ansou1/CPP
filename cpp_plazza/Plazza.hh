#ifndef	_PLAZZA_HH_
# define _PLAZZA_HH_

#include <iostream>
#include <string>
#include <list>
#include <sstream>

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>

#include "kitchen_management.hh"
#define FILE1 "fifo1.plazza"
#define FILE2 "fifo2.plazza"
#define SSTR( x ) dynamic_cast< std::ostringstream & >(( std::ostringstream() << std::dec << x ) ).str()

enum TypePizza
{
    REGINA = 1,
    MARGARITA = 2,
    AMERICAINE = 4,
    FANTASIA = 8
};

enum TaillePizza
{
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
};

typedef struct      Fridge
{
    unsigned int    pasta;
    unsigned int    tomato;
    unsigned int    swiss_cheese;
    unsigned int    ham;
    unsigned int    mushroom;
    unsigned int    steak;
    unsigned int    goat_cheese;
    unsigned int    eggplant;
}                   Fridge;

#endif			/* !_PLAZZA_HH_ */
