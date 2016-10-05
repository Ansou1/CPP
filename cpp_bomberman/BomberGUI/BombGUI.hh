//
// BombGUI.hh for lol in /home/lerman_v/Git/C++/cpp_bomberman/BomberGUI
// 
// Made by lerman_v
// Login   <lerman_v@epitech.net>
// 
// Started on  Tue May 27 16:24:42 2014 lerman_v
// Last update Fri May 30 14:10:34 2014 lerman_v
//

#ifndef BOMBGUI_HH_
#define BOMBGUI_HH_

#include "AObject.hh"
#include "../Core/Data.hh"
#include <SdlContext.hh>
#include <BasicShader.hh>
#include <glm/glm.hpp>
#include <BasicShader.hh>
#include <glm/gtc/matrix_transform.hpp>
#include <Model.hh>

#define BOMBANIMTIME	5.0f
#define BOOMANIMTIME	1.0f

class BombGUI : public AObject
{
protected:
  gdl::Model		_model;
  Data::e_direction	_dir;
  float			_state;

public:
  BombGUI();
  ~BombGUI();
  void	initPos(float, float);

  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
  virtual void updateAnime(gdl::Clock const &clock);

  void  setAnim(Data::e_direction dir);
  bool  setAnim(std::string const &obj);
  void	setBoom();

  bool	hasBoom() const;
  bool	boomEnd() const;
};

#endif /* BOMBGUI_HH_ */
