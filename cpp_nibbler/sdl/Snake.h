/*
** Snake.h<2> for  in /home/daguen_s/rendu/cpp_nibbler
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Thu Apr  3 20:21:24 2014 daguen_s
** Last update Fri Apr  4 16:55:55 2014 jeremy falconnier
*/

#ifndef SNAKE_H
#define SNAKE_H

#include "../displaymodule.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <sstream>
#include <map>

#define SSTR( x ) dynamic_cast< std::ostringstream & >(( std::ostringstream() << std::dec << x ) ).str()

class Snake : public IDisplayModule
{
 private:
  coord		size;
  SDL_Surface	*screen;
  SDL_Surface	*base;
  SDL_Surface	*body;
  SDL_Surface	*wall;
  SDL_Surface	*fruit;
  SDL_Surface	*tail;
  SDL_Surface	*head;
  TTF_Font 	*police;
  SDL_Surface	*texte;
  SDL_Color 	green;
  std::map<int, e_key> event_key_keysym_sym;

 public:
  virtual void	aff(const std::vector<std::string> &, const unsigned int &score, const float &);
  void		aff_score(const unsigned int &score, const float &);
  void		init(const coord &size);
  virtual e_key getKey(void) const;
  virtual	~Snake();
  Snake();
  Snake(const Snake &);
  Snake &operator=(const Snake &);
};

#endif
