//
// PlayerGUI.hh for lol in /home/lerman_v/Git/C++/cpp_bomberman/BomberGUI
//
// Made by lerman_v
// Login   <lerman_v@epitech.net>
//
// Started on  Mon May 26 15:13:33 2014 lerman_v
// Last update Thu Jun 12 14:16:28 2014 Boulot
//

#ifndef PLAYERGUI_HH_
#define PLAYERGUI_HH_

#include "AObject.hh"
#include "../Core/Data.hh"
#include <SdlContext.hh>
#include <BasicShader.hh>
#include <glm/glm.hpp>
#include <BasicShader.hh>
#include <glm/gtc/matrix_transform.hpp>
#include <Model.hh>

class PlayerGUI : public AObject
{
protected:
  gdl::Model		_model;
  Data::e_direction	_dir;
  glm::vec4		_color;
  float			_state;
  bool			_isRuning;
  float			_speed;

public:
  PlayerGUI(glm::vec4 const &color);
  ~PlayerGUI();

  void  initPos(float, float);

  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
  virtual void updateAnime(gdl::Clock const &clock);

  bool	setDir(Data::e_direction const dir);
  bool	setAnim(std::string const &obj);

  bool	isAnimated() const;
};

#endif /* PLAYERGUI_HH_ */
