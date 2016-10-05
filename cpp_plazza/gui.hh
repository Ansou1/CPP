#ifndef GUI_H
#define GUI_H

#include <stdio.h>
#include <signal.h>
#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses/curses.h>
#include <term.h>
#include "manage_kitchen.h"

class Gui
{
private:
  std::list<Data_kitchen 	*> 	*kitchens;
  std::list<std::string 	*> 	*wait_list;
  std::list<std::string   *> 	*finish_list;
  fd_set        fd_read;
  std::string input;
  struct termios old;
  bool flush_stream;
  char *term;
  char *home;
public:
  Gui();
  ~Gui();
  void reload(Manage_kitchen &);
  std::string &get_input();
  int rawMode(const int fd);
};

#endif
