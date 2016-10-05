/*
** Snake.h for nibbler in /home/falcon_j/projet/cpp_nibbler/opengl
**
** Made by jeremy falconnier
** Login   <falcon_j@epitech.net>
**
** Started on  Fri Apr  4 13:08:41 2014 jeremy falconnier
** Last update Fri Apr  4 17:12:59 2014 jeremy falconnier
*/

#ifndef SNAKE_H
#define SNAKE_H

#include "../displaymodule.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include <cmath>
#include <map>

#define FPS 60
#define LARGEUR_FENETRE 600
#define HAUTEUR_FENETRE 400

class Snake : public IDisplayModule
{
 private:
  coord size;
  SDL_Surface *ecran;
  SDL_Event event;
  //  Uint32 time_per_frame;
  std::map<int, e_key> event_key_keysym_sym;

 public:
  void		aff_score(const unsigned int &score, const float &);
  virtual void aff(const std::vector<std::string> &, const unsigned int &, const float &);
  void	DrawCube(int x, int y, const int &r, const int &g, const int &b, float h) const;
  void	display_o(int x, int y, const char &n) const;
  void init(const coord &size);
  virtual e_key getKey(void) const;
  virtual ~Snake();
  Snake();
  Snake(const Snake &);
  Snake &operator=(const Snake &);
};

#endif
