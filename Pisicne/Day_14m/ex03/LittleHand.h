/*
** LittleHand.h for  in /home/daguen_s/rendu/piscine_cpp_d14m/ex01
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Tue Jan 21 10:36:45 2014 daguen_s
** Last update Tue Jan 21 17:02:52 2014 daguen_s
*/

#ifndef _LITTLEHAND_H_
# define _LITTLEHAND_H_

#include <iostream>
#include <string>
#include "MixerBase.h"
#include "FruitBox.h"
#include "Coconut.h"
#include "Mixer.h"

class LittleHand
{
 public:
  LittleHand();
  ~LittleHand();

  static void sortFruitBox(FruitBox& unsorted, FruitBox& lemons, FruitBox& bananas, FruitBox& limes);
  static FruitBox * const * organizeCoconut(Coconut const * const * coconuts_packet);
  static void plugMixer(MixerBase &mixer);
};

#endif /* _LITTLEHAND_H_ */
