//
// PlayerGUI.cpp for lol in /home/lerman_v/Git/C++/cpp_bomberman/BomberGUI
// 
// Made by lerman_v
// Login   <lerman_v@epitech.net>
// 
// Started on  Mon May 26 17:50:11 2014 lerman_v
// Last update Fri Jun 13 13:49:12 2014 Boulot
//

#include "PlayerGUI.hh"

PlayerGUI::PlayerGUI(glm::vec4 const &color)
{
  if (!_model.load("./BomberGUI/assets/marvin.fbx"))
    {
      std::string err = std::string("Cannot load model : ./BomberGUI/assets/marvin.fbx");
      throw my_exception(err.c_str());
    }
  scale(glm::vec3(0.003f, 0.003f, 0.003f));

  _dir = Data::UP;
  _state = 0.0f;
  _isRuning = false;
  _color = color;

  _model.createSubAnim(0, "NONE", 0, 0);
  _model.createSubAnim(0, "START", 0, 30);
  _model.createSubAnim(0, "RUN", 36, 53);
  _model.createSubAnim(0, "STOP", 60, 120);

  _speed = 1.0f;
}

PlayerGUI::~PlayerGUI()
{

}

void	PlayerGUI::initPos(float x, float y)
{
  _position = glm::vec3(x, -0.5f, y);
}

void	PlayerGUI::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  updateAnime(clock);
  shader.setUniform("color", _color);
  _model.draw(shader, getTransformation(), clock.getElapsed() * _speed);
  shader.setUniform("color", glm::vec4(0.0f, 0.0f, 0.0f, 0.0f));
}

void	PlayerGUI::updateAnime(gdl::Clock const &clock)
{
  float	move;

  if (_state == 0.0f)
    {
      if (_isRuning)
	_model.setCurrentSubAnim("NONE", false);
      _isRuning = false;
      return ;
    }
  move = clock.getElapsed() * 4.0f * _speed;
  if (_state < move)
    move = _state;

  move *= Data::DOWN == _dir || Data::LEFT == _dir ? -1.0f : 1.0f;
  translate(glm::vec3(
		      (Data::LEFT == _dir || Data::RIGHT == _dir ? move : 0.0f),
		      0.0f,
		      (Data::UP == _dir || Data::DOWN == _dir ? move : 0.0f)
		      )
	    );
  _state -= (Data::DOWN == _dir || Data::LEFT == _dir ? -1.0f : 1.0f) * move;
}

bool	PlayerGUI::setAnim(std::string const &obj)
{
  if (_state != 0.0f)
    return false;
  _state = 1.0f;

  if (obj == "RUN")
    {
      if (_isRuning)
	return true;
      _isRuning = true;
    }
  else
    _isRuning = false;

  return _model.setCurrentSubAnim(obj, true);
}

bool	PlayerGUI::setDir(Data::e_direction const dir)
{
  if (_state != 0.0f)
    return false;
  rotate(glm::vec3(0, 1, 0), (float)(_dir - dir) * 90.0f);
  _dir = dir;
  return true;
}

bool	PlayerGUI::isAnimated() const
{
  return (_state != 0.0f); 
}
