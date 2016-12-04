/*
** Mixer.h for  in /home/daguen_s/rendu/piscine_cpp_d14m/ex03
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Tue Jan 21 13:02:07 2014 daguen_s
** Last update Tue Jan 21 14:17:02 2014 daguen_s
*/

#ifndef _MIXER_H_
# define _MIXER_H_

#include <string>
#include <iostream>
#include "MixerBase.h"

class Mixer : public MixerBase
{
 public:
  Mixer();
  ~Mixer();

  void		connect();
};

#endif /* _MIXER_H_ */
