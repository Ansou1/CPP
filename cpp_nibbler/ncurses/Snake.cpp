//
// Snake.cpp for  in /home/daguen_s/rendu/cpp_nibbler/ncurses
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Mon Mar 31 08:45:12 2014 daguen_s
// Last update Fri Apr  4 15:21:21 2014 daguen_s
//

#include "Snake.hh"
#include <stdlib.h>
#include <ncurses/panel.h>
#include "../Exception.hpp"

void Snake::aff(const std::vector<std::string> &map, const unsigned int &score, const float &speed)
{
  draw	func_pointer;

  for (unsigned int y = (unsigned int)0; y < (unsigned int)this->size.y; ++y)
    {
      for (unsigned int x = (unsigned int)0; x < (unsigned int)this->size.x; ++x)
	{
	  wmove(stdscr, y, x * 2);
	  func_pointer = print_tab[map[y][x]];
	  (this->*func_pointer)();
	}
    }
  wmove(stdscr, this->size.y, 0);
  wprintw(stdscr, "Score: %d || case/s %f\n", score, speed);
  refresh();
}

void Snake::init(const coord &size)
{
  try
    {
      if (size.y > 50 || size.x > 90)
	throw exception_lib("Map is too big\n");
      this->size.x = size.x;
      this->size.y = size.y;
      initscr();
      raw();
      timeout(0);
      keypad(stdscr, TRUE);
      noecho();

      start_color();
      init_pair(1, COLOR_RED, COLOR_RED);
      init_pair(2, COLOR_GREEN, COLOR_GREEN);
      init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
      init_pair(4, COLOR_BLUE, COLOR_BLUE);
      init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
      init_pair(6, COLOR_CYAN, COLOR_CYAN);
      init_pair(7, COLOR_WHITE, COLOR_WHITE);
      curs_set(0);

      int x, y;
      x = getmaxx(stdscr);
      y = getmaxy(stdscr);
      if (y < size.y || x < size.x * 2)
	{
	  endwin();
	  throw exception_lib("Map is too big\n");
	}
    }
  catch(const std::exception & e)
    {
      std::cerr << e.what() << std::endl;
      exit(EXIT_FAILURE);
    }
}

e_key Snake::getKey(void) const
{
  int ch;

  ch = getch();
  std::map<int, e_key>::const_iterator it = this->key.find(ch);
  return ((it == this->key.end()) ? NONE : (*it).second);
}

void	Snake::wall() const
{
  attron(COLOR_PAIR(1));
  wprintw(stdscr, "  ");
  attroff(COLOR_PAIR(1));
}

void	Snake::snake() const
{
  attron(COLOR_PAIR(2));
  wprintw(stdscr, "  ");
  attroff(COLOR_PAIR(2));
}

void	Snake::fruit() const
{
  attron(COLOR_PAIR(5));
  wprintw(stdscr, "  ");
  attroff(COLOR_PAIR(5));
}

void	Snake::head() const
{
  attron(COLOR_PAIR(4));
  wprintw(stdscr, "  ");
  attroff(COLOR_PAIR(4));
}

void	Snake::tail() const
{
  attron(COLOR_PAIR(6));
  wprintw(stdscr, "  ");
  attroff(COLOR_PAIR(6));
}

void	Snake::empty() const
{
  attron(COLOR_PAIR(7));
  wprintw(stdscr, "  ");
  attroff(COLOR_PAIR(7));
}

Snake::~Snake()
{
  endwin();
}

Snake::Snake()
{
  this->key[27] = ESCAPE;
  this->key['z'] = KEY_Z;
  this->key['s'] = KEY_S;
  this->key['q'] = KEY_Q;
  this->key['d'] = KEY_D;
  this->key[KEY_LEFT] =  LEFT;
  this->key[KEY_RIGHT] = RIGHT;
  this->print_tab['w'] = &Snake::wall;
  this->print_tab['s'] = &Snake::snake;
  this->print_tab['f'] = &Snake::fruit;
  this->print_tab['h'] = &Snake::head;
  this->print_tab['t'] = &Snake::tail;
  this->print_tab['v'] = &Snake::empty;
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
