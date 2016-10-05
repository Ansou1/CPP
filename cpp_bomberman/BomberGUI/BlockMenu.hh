//
// BlockMenu.hh for lol in /home/lerman_v/Git/C++/cpp_bomberman/BomberGUI
// 
// Made by lerman_v
// Login   <lerman_v@epitech.net>
// 
// Started on  Mon May 12 00:03:42 2014 lerman_v
// Last update Fri May 30 21:07:58 2014 lerman_v
//

#ifndef BLOCKMENU_HH_
#define BLOCKMENU_HH_

#include "AObject.hh"
#include <Geometry.hh>
#include <Texture.hh>
#include <string>
#include <iostream>

#define MOVETIME	30
#define KICKTIME	5
#define DIETIME		12

class BlockMenu : public AObject
{
public:
  enum AnimeBlockMenu {ANY = 1, SELECT = 180, UNSELECT = 0};

private:
  gdl::Texture		_texture;
  gdl::Geometry		_geometry;
  float			_speed;
  float			_state;
  AnimeBlockMenu	_curentAnime;

public:
  BlockMenu(std::string const &textPath);
  virtual ~BlockMenu();

  virtual bool	initialize(std::string const &textPath);

  virtual void	updateAnime(gdl::Clock const &clock);
  virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock);

  void		setAnime(AnimeBlockMenu newAnime);
};

#endif /* BLOCKMENU_HH_ */
