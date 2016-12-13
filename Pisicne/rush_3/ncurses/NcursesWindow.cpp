//
// DisplayNcurse.cpp for  in /home/daguen_s/rendu/piscine_cpp_rush3
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sat Jan 25 21:26:11 2014 daguen_s
// Last update Sun Jan 26 03:38:20 2014 daguen_s
//

#include <iostream>
#include "NcursesWindow.hh"

NcursesWindow::NcursesWindow(int lignes, int colonnes, int posX, int posY)
{
  this->titre = "";
  this->cadre = newwin(lignes, colonnes, posY, posX);
  box(this->cadre, 0 , 0);
  this->fenetre = subwin(this->cadre, lignes - 2, colonnes - 2, posY + 1, posX + 1);
  this->lignes = lignes;
  this->colonnes = colonnes;
  this->posX = posX;
  this->posY = posY;
}

NcursesWindow::~NcursesWindow()
{
  delwin(this->fenetre);
  delwin(this->cadre);
}

std::string	NcursesWindow::getTitre() const
{
  return (this->titre);
}

WINDOW*		NcursesWindow::getCadre() const
{
  return (this->cadre);
}

WINDOW*		NcursesWindow::getFenetre() const
{
  return (this->fenetre);
}

int		NcursesWindow::getLignes() const
{
  return (this->lignes);
}

int		NcursesWindow::getColonnes() const
{
  return (this->colonnes);
}

int		NcursesWindow::getPosX() const
{
  return (this->posX);
}

int		NcursesWindow::getPosY() const
{
  return (this->posY);
}

void		NcursesWindow::setTitre(std::string const &s)
{
  int		start = 0;

  this->titre = s;
  start = (this->colonnes - s.size()) / 2;
  mvwprintw(this->cadre, 0, start, s.c_str());
}

int		NcursesWindow::putText(std::string const &s) const
{
  return (wprintw(this->fenetre, s.c_str()));
}

int		NcursesWindow::putText(char const *s) const
{
  std::cout << s << std::endl;
  return (wprintw(this->fenetre, s));
}

int		NcursesWindow::putTextAt(int x, int y, std::string const &s) const
{
  return (mvwprintw(this->fenetre, y, x, s.c_str()));
}

int		NcursesWindow::putTextAt(int x, int y, char const *s) const
{
  return (mvwprintw(this->fenetre, y, x, s));
}

void		NcursesWindow::setBkgd(chtype ch) const
{
  wbkgd(this->fenetre, ch);
}

void		NcursesWindow::displayWindow() const
{
  wrefresh(this->cadre);
  wrefresh(this->fenetre);
}

int		NcursesWindow::clearWindow() const
{
  return (werase(this->fenetre));
}
