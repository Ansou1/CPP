//
// snake.cpp for snake in /home/falcon_j/projet/cpp_nibbler/opengl
//
// Made by jeremy falconnier
// Login   <falcon_j@epitech.net>
//
// Started on  Fri Apr  4 13:08:22 2014 jeremy falconnier
// Last update Fri Apr  4 17:23:45 2014 jeremy falconnier
//

#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include "Snake.h"

void	Snake::DrawCube(int x, int y, const int &r, const int &g, const int &b, float h) const
{
  float llum;

  llum = 2 - (sqrt(x * x + y * y) / (size.x + size.y));
  glBegin(GL_QUADS);

  x += (size.x + size.y)/100;
  y += (size.x + size.y)/100;
  h += (size.x + size.y)/100;

  glColor3ub(llum * r, llum * g, llum * b);
  glVertex3d(y + 0.5,x + 0.5,h);
  glVertex3d(y+0.5,x+0.5,-h);
  glVertex3d(y-0.5,x+0.5,-h);
  glVertex3d(y-0.5,x+0.5,h);

  glVertex3d(y+0.5,x-0.5,h);
  glVertex3d(y+0.5,x-0.5,-h);
  glVertex3d(y+0.5,x+0.5,-h);
  glVertex3d(y+0.5,x+0.5,h);

  glVertex3d(y-0.5,x-0.5,h);
  glVertex3d(y-0.5,x-0.5,-h);
  glVertex3d(y+0.5,x-0.5,-h);
  glVertex3d(y+0.5,x-0.5,h);

  glVertex3d(y-0.5,x+0.5,h);
  glVertex3d(y-0.5,x+0.5,-h);
  glVertex3d(y-0.5,x-0.5,-h);
  glVertex3d(y-0.5,x-0.5,h);


  glVertex3d(y+0.5,x+0.5,-h);
  glVertex3d(y+0.5,x-0.5,-h);
  glVertex3d(y-0.5,x-0.5,-h);
  glVertex3d(y-0.5,x+0.5,-h);

  glVertex3d(y+0.5,x-0.5,h);
  glVertex3d(y+0.5,x+0.5,h);
  glVertex3d(y-0.5,x+0.5,h);
  glVertex3d(y-0.5,x-0.5,h);

    glEnd();
}

void	Snake::display_o(int x, int y, const char &n) const
{
  x -= size.x / 2;
  y-= size.y;
  glPushMatrix();
  n == 'w' ? DrawCube(x,y,80,100,80,0.8)
    : n == 's' ? DrawCube(x,y,0,255,0,0.8)
    : n == 'h' ? DrawCube(x,y,255,0,0,0.8)
    : n == 'f' ? DrawCube(x,y,255,0,255,0.8)
    : n == 't' ? DrawCube(x,y,0,0,255,0.8)
    : DrawCube(x,y,255,255,255, 0);
  glPopMatrix();
}

void Snake::aff(const std::vector<std::string> &map, const unsigned int &score, const float &speed)
{
  int	x;
  int	y = -1;

  std::cout << "your score : " << score << "     your speed : " << speed << "case/s" << std::endl;
  usleep(1000);
  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity();
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  gluLookAt(size.x, 0, size.y * 0.6, 0, 0, 0, 0, 0, 1);
  atexit(SDL_Quit);
  while (++y < size.y)
    {
      x = -1;
      while (++x < size.x)
  	display_o(x, y, map[y][x]);
    }
  glFlush();
  SDL_GL_SwapBuffers();
}

void Snake::init(const coord &size)
{
  try
    {
      if (SDL_Init(SDL_INIT_VIDEO) == -1)
	throw exception_lib("SDL fail");
      SDL_Init(SDL_INIT_VIDEO);
      SDL_WM_SetCaption("NIBBLER",NULL);
      if (SDL_SetVideoMode(1500, 1500, 32, SDL_OPENGL) == NULL)
	throw exception_lib("SDL fail\n");
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glMatrixMode(GL_PROJECTION);
      gluPerspective(60,(double)1500/1500,1,1000);
      glEnable(GL_DEPTH_TEST);
      //      this->time_per_frame = 1000 / FPS;
      if (size.x > 200 || size.y > 200)
	throw exception_lib("invalid map size you need more than 20 and less than 200 .\n");
      this->size.x = size.x;
      this->size.y = size.y;
      this->ecran = NULL;
      this->event_key_keysym_sym[SDLK_ESCAPE] = ESCAPE;
      this->event_key_keysym_sym[SDLK_z] = KEY_Z;
      this->event_key_keysym_sym[SDLK_LEFT] = LEFT;
      this->event_key_keysym_sym[SDLK_RIGHT] = RIGHT;
      this->event_key_keysym_sym[SDLK_s] = KEY_S;
      this->event_key_keysym_sym[SDLK_q] = KEY_Q;
      this->event_key_keysym_sym[SDLK_d] = KEY_D;
    }
    catch(const std::exception & e)
    {
      std::cerr << e.what() << std::endl;
      exit(EXIT_FAILURE);
    }
}
e_key Snake::getKey(void) const
{
  SDL_Event	event;

  if (SDL_PollEvent(&event) == 1)
    {
      if (event.type == SDL_QUIT)
	return ESCAPE;
      if (event.type == SDL_KEYDOWN)
	{
	  std::map<int, e_key>::const_iterator it = this->event_key_keysym_sym.find(event.key.keysym.sym);
	  return it == this->event_key_keysym_sym.end() ? NONE : (*it).second;
	}
    }
  return NONE;
}

Snake::~Snake()
{
  SDL_Quit();
}

Snake::Snake()
{
}

Snake::Snake(const Snake &cpy)
{
  this->size = cpy.size;
}

Snake &Snake::operator=(const Snake &cpy)
{
  this->size = cpy.size;
  return (*this);
}

extern "C" IDisplayModule* getInstance()
{
  return new Snake();
}
