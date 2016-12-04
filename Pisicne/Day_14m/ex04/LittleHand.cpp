//
// LittleHand.cpp for  in /home/daguen_s/rendu/piscine_cpp_d14m/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Tue Jan 21 10:41:09 2014 daguen_s
// Last update Wed Jan 22 09:32:05 2014 daguen_s
//

#include <iostream>

#include "Fruit.h"
#include "Banana.h"
#include "Lemon.h"
#include "Lime.h"
#include "Coconut.h"
#include "FruitBox.h"
#include "LittleHand.h"

typedef struct InTheMatrixFruit
{
  virtual	~InTheMatrixFruit();
  int		vitamins;
} InTheMatrixFruit;

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

FruitBox * const * LittleHand::organizeCoconut(Coconut const * const * coconuts_packet)
{
  FruitBox	**box_of_coconut;
  int		count_coconut = 0;
  int		i = 0;
  int		j = 0;

  while (coconuts_packet[count_coconut])
    count_coconut++;
  box_of_coconut = new FruitBox*[(count_coconut / 6) + 2];
  for (i = 0; i < (count_coconut / 6) + 2; i++)
    box_of_coconut[i] = new FruitBox(6);
  i = 0;
  count_coconut = 0;
  while (coconuts_packet[count_coconut] != NULL)
    {
      if (j == 5)
	{
	  j = 0;
	  i = i + 1;
	}
      box_of_coconut[i]->putFruit(const_cast<Coconut *>(coconuts_packet[count_coconut]));
      j++;
      count_coconut++;
    }
  box_of_coconut[i + 1] = NULL;
  return box_of_coconut;
}

void	LittleHand::plugMixer(MixerBase &mixer)
{
  Mixer &a = static_cast<Mixer &>(mixer);
  a.connect();
}

void	LittleHand::injectVitamin(Fruit &fruit, int quantity)
{
  fruit = fruit;
  quantity = quantity;
  ((InTheMatrixFruit&)fruit)._vitamins = quantity;
}
