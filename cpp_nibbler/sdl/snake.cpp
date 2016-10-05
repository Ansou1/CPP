//
// snake.cpp for  in /home/corrad_f/rendu/cpp_nibbler/sdl
//
// Made by corrad_f
// Login   <corrad_f@epitech.net>
//
// Started on  Fri Apr  4 17:54:01 2014 corrad_f
// Last update Sun Apr  6 16:41:22 2014 daguen_s
//

#include <unistd.h>

#include "Snake.h"
#include <iostream>

void Snake::aff_score(const unsigned int &score, const float &speed)
{
  SDL_Rect position;

  position.x = 10;
  position.y = 20;
  std::string sp;
  sp = "Score :";
  sp = sp + SSTR(score);
  this->texte = TTF_RenderText_Blended(police, sp.c_str(), this->green);
  if (this->texte == NULL)
    {
      throw exception_lib("texte");
    }
  SDL_BlitSurface(this->texte, NULL, this->screen, &position);

  sp = SSTR(speed);
  sp = sp + " case / sec";
  this->texte = TTF_RenderText_Blended(police, sp.c_str(), this->green);
  position.x = 10;
  position.y = 50;
  if (this->texte == NULL)
    {
      throw exception_lib("texte");
    }
  SDL_BlitSurface(this->texte, NULL, this->screen, &position);
  SDL_FreeSurface(this->texte);
}

void Snake::aff(const std::vector<std::string> &map, const unsigned int &score, const float &speed)
{
  SDL_Rect position;

  position.x = 0;
  position.y = 0;
  SDL_BlitSurface(this->base, NULL, this->screen, &position);
  for (int y = 0; y < this->size.y;++y)
    {
      for (int x = 0; x < this->size.x; ++x)
	{
	  position.x = x * 10;
	  position.y = y * 10;
	  if (map[y][x] == 'h' || map[y][x] == 't')
	    {
	      position.x = x * 10 + 2;
	      position.y = y * 10 + 2;
	    }
	  (map[y][x] == 'w') ? SDL_BlitSurface(this->wall, NULL, this->screen, &position)
	    : (map[y][x] == 's') ? SDL_BlitSurface(this->body, NULL, this->screen, &position)
	    : (map[y][x] == 'f') ? SDL_BlitSurface(this->fruit, NULL, this->screen, &position)
	    : (map[y][x] == 'h') ? SDL_BlitSurface(this->head, NULL, this->screen, &position)
	    : (map[y][x] == 't') ? SDL_BlitSurface(this->tail, NULL, this->screen, &position) : 0;
	}
    }
  try
    {
      aff_score(score, speed);//affiche le score sur la map
    }
  catch (const std::exception & e)
    {
      std::cerr << e.what();
    }
  SDL_Flip(this->screen);
}

void Snake::init(const coord &size)
{
  this->size.x = size.x;
  this->size.y = size.y;
  if (this->size.x > 192 || this->size.y > 103)
    {
      std::cerr << "SDL : invalide map size\n";
      exit(EXIT_FAILURE);
    }
  try
    {
      if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
	  throw exception_lib("SDL fail");
	}
      if(TTF_Init() == -1)
	{
	  std::cerr << "Erreur d'initialisation de TTF_Init : " << TTF_GetError() << std::endl;
	  throw exception_lib("");
	}
      police = TTF_OpenFont("sdl/adrip1.ttf", 40);
      if (police == NULL)
	{
	  throw exception_lib("Cannot find sdl/firewood.ttf");
	}
      this->green.r = 0;
      this->green.g = 255;
      this->green.b = 0;
      TTF_SetFontStyle(police, 0);
      if ((this->screen = SDL_SetVideoMode(this->size.x * 10, this->size.y * 10, 32, SDL_HWSURFACE)) == NULL)
	{
	  throw exception_lib("SDL fail\n");
	}
    }
  catch(const std::exception & e)
    {
      std::cerr << e.what() << std::endl;
      exit(EXIT_FAILURE);
    }
  this->base = SDL_CreateRGBSurface(SDL_HWSURFACE, this->size.x * 10, this->size.y * 10, 32, 0, 0, 0, 0);
  SDL_FillRect(this->base, NULL, SDL_MapRGB(this->screen->format, 0, 0, 10));
  SDL_WM_SetCaption("Nibbler", NULL);
  this->wall = IMG_Load("sdl/100.gif");
  this->fruit = IMG_Load("sdl/diamond.gif");
  this->body = IMG_Load("sdl/010.gif");
  this->head = IMG_Load("sdl/004.gif");
  this->tail = IMG_Load("sdl/009.gif");
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
  SDL_FreeSurface(this->base);
  SDL_FreeSurface(this->wall);
  SDL_FreeSurface(this->body);
  SDL_Quit();
  TTF_CloseFont(this->police); /* Doit être avant TTF_Quit() */
  TTF_Quit();
}

Snake::Snake()
{
  this->screen = NULL;
  this->base = NULL;
  this->wall = NULL;
  this->body = NULL;
  this->texte = NULL;
  this->event_key_keysym_sym[SDLK_ESCAPE] = ESCAPE;
  this->event_key_keysym_sym[SDLK_z] = KEY_Z;
  this->event_key_keysym_sym[SDLK_LEFT] = LEFT;
  this->event_key_keysym_sym[SDLK_RIGHT] = RIGHT;
  this->event_key_keysym_sym[SDLK_s] = KEY_S;
  this->event_key_keysym_sym[SDLK_q] = KEY_Q;
  this->event_key_keysym_sym[SDLK_d] = KEY_D;
}

Snake::Snake(const Snake &cpy)
{
  this->body = cpy.body;
  this->wall = cpy.wall;
  this->size = cpy.size;
}

Snake &Snake::operator=(const Snake &cpy)
{
  this->size = cpy.size;
  return (*this);
}

#if defined(_WIN32)

extern "C" __declspec(dllexport) IDisplayModule* getInstance()
{
  return new Snake();
}

#elif defined(__unix__)

extern "C" IDisplayModule* getInstance()
{
  return new Snake();
}

#endif
