/*
** displaymodule.h for  in /home/daguen_s/rendu/cpp_nibbler
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Thu Apr  3 20:10:02 2014 daguen_s
** Last update Fri Apr  4 17:32:01 2014 corrad_f
*/

#ifndef _DISPLAY_
# define _DISPLAY_

#include <iostream>
#include <string>
#include <vector>
#include "Exception.hpp"

#define HEAD  ('h')
#define BODY  ('s')
#define TAIL  ('t')
#define FRUIT ('f')
#define FREE  ('v')
#define WALL  ('w')

typedef enum e_key
  {
    UP,
    DOWN,
    RIGHT,
    LEFT,
    KEY_D,
    KEY_Z,
    KEY_S,
    KEY_Q,
    NONE,
    ESCAPE
  }	e_key;

typedef struct coord
{
  short x;
  short y;
}coord;

class IDisplayModule
{
 public:
  virtual ~IDisplayModule() {};

  virtual void aff(const std::vector<std::string> &, const unsigned int &score, const float &speed) = 0;
  virtual void init(const coord &size) = 0;
  virtual e_key getKey(void) const = 0;
};

#endif
