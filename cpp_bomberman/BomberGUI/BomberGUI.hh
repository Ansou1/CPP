//
// BomberGUI.hh for lol in /home/lerman_v/Git/C++/cpp_bomberman/BomberGUI
//
// Made by lerman_v
// Login   <lerman_v@epitech.net>
//
// Started on  Fri May  9 08:34:10 2014 lerman_v
// Last update Sat Jun 14 16:38:26 2014 lerman_v
//

#ifndef BOMBERGUI_HH_
#define BOMBERGUI_HH_

#include <SdlContext.hh>
#include <BasicShader.hh>
#include <Geometry.hh>
#include <Texture.hh>
#include <glm/gtc/matrix_transform.hpp>
#include <map>
#include <vector>

#include <iostream>
#include <sstream>

#include "PlayerGUI.hh"
#include "BombGUI.hh"
#include "Cube.hh"
#include "Bonus.hh"
#include "Background.hh"
#include "BlockMenu.hh"

#include "Arrow.hh"

#include "TextGUI.hh"

#include "../Core/Map.hh"
#include "../Core/GameManager.hh"
#include "../Core/Exception.hpp"

#include "../Encapsulation/ScanDir.hh"

#define FOV	60.0f
#define MAXIA	10000
#define MINMAP	5
#define MAXMAP	100

#define PI 3.14159265f


class BomberGUI
{
private:
  gdl::Clock				_clock;
  gdl::SdlContext			_context;
  gdl::Input				_input;
  gdl::BasicShader			_shader;

  std::map<Data::e_case, AObject*>	_objects;

  float					_ratio;

  GameManager				*_GameManager;
  std::map<int, Data::e_action>		_playerBind[2];

  glm::vec3				_camera;

  std::vector<std::string>		_mapSelect;
  std::vector<char>			_inputPut;

  int					_soundLevel;
  bool					_isMute;

public:
  BomberGUI();
  ~BomberGUI();
  void		intro();
  void		menu();

  bool		createWindow(int width, int height);
  bool		setCamera(glm::vec3 const& origin);

  bool	        initObjects();

  void		draw();
  void		drawMenu(std::vector<AObject *> const &items);
  void		drawMap(Map const &map);

  bool		update();

  void		MenuPlay();
  void		MenuSetting();
  void		Credit();

  void	        runGame();
  bool		MenuPause();
  void		checkError(FMOD_RESULT result);
};

#endif /* BOMBERGUI_HH_ */
