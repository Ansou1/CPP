//
// LittleHand.cpp for  in /home/daguen_s/rendu/piscine_cpp_d14m/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Tue Jan 21 10:41:09 2014 daguen_s
// Last update Tue Jan 21 20:41:29 2014 daguen_s
//

#include <iostream>

#include "Fruit.h"
#include "Banana.h"
#include "Lemon.h"
#include "Lime.h"
#include "FruitBox.h"
#include "LittleHand.h"

LittleHand::LittleHand()
{
}


LittleHand::~LittleHand()
{
}

void		LittleHand::sortFruitBox(FruitBox& unsorted, FruitBox& lemons, FruitBox& bananas, FruitBox& limes)
{
  int		nb = unsorted.nbFruits();
  int		i = 0;
  Fruit		*f;
  Lemon		*ptrLemon;
  Banana	*ptrBanana;
  Lime		*ptrLime;

  while (i < nb)
    {
      f = unsorted.pickFruit();

      ptrLemon = dynamic_cast<Lemon *>(f);
      ptrBanana = dynamic_cast<Banana *>(f);
      ptrLime = dynamic_cast<Lime *>(f);

      if (ptrLime)
	{
	  if (!limes.putFruit(f))
	    unsorted.putFruit(f);
	}
      else if (ptrBanana)
	{
	  if (!bananas.putFruit(f))
	    unsorted.putFruit(f);
	}
      else if (ptrLemon)
	{
	  if (!lemons.putFruit(f))
	    unsorted.putFruit(f);
	}
      else
	unsorted.putFruit(f);
      i++;
    }
}

