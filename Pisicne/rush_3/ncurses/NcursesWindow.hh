//
// DisplayNcurse.hh for  in /home/daguen_s/rendu/piscine_cpp_rush3
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sat Jan 25 21:26:14 2014 daguen_s
// Last update Sun Jan 26 01:23:09 2014 daguen_s
//

#ifndef _NCURSESWINDOW_H_
# define _NCURSESWINDOW_H_

#include <ncurses.h>

#include <string>

#include "IMonitorDisplay.hpp"

class		NcursesWindow : public IMonitorDisplay
{
protected:
  std::string	titre;
  WINDOW	*cadre;
  WINDOW	*fenetre;
  int		lignes;
  int		colonnes;
  int		posX;
  int		posY;

public:
  NcursesWindow(int lignes, int colonnes, int posX, int posY);
  ~NcursesWindow();

  std::string	getTitre() const;
  WINDOW*	getCadre() const;
  WINDOW*	getFenetre() const;
  int		getLignes() const;
  int		getColonnes() const;
  int		getPosX() const;
  int		getPosY() const;

  void		setTitre(std::string const &s);

  int		putText(std::string const &s) const;
  int		putText(char const *s) const;
  int		putTextAt(int x, int y, std::string const &s) const;
  int		putTextAt(int x, int y, char const *s) const;

  void		setBkgd(chtype ch) const;

  int		clearWindow() const;
  virtual void	displayWindow() const;
};

#endif /* _NCURSESWINDOW_H_ */
