//
// BombGUI.cpp for lol in /home/lerman_v/Git/C++/cpp_bomberman/BomberGUI
// 
// Made by lerman_v
// Login   <lerman_v@epitech.net>
// 
// Started on  Tue May 27 16:26:40 2014 lerman_v
// Last update Sun Jun 15 13:57:00 2014 daguenet
//

#include "BombGUI.hh"

BombGUI::BombGUI()
{
  if (!_model.load("./BomberGUI/assets/bomb.fbx"))
    {
      std::string err;

      err = std::string("Cannot load Model");
      throw my_exception(err.c_str());
    }
  scale(glm::vec3(0.002f, 0.002f, 0.002f));

  _state = 0.0f;
}

BombGUI::~BombGUI()
{

}

void	BombGUI::initPos(float x, float y)
{
  _position = glm::vec3(x, 0.0f, y);
}

void	BombGUI::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  shader.setUniform("color", glm::vec4(_state / BOMBANIMTIME, 0.0f, 0.0f, 1.0f));
  _model.draw(shader, getTransformation(), clock.getElapsed());
  shader.setUniform("color", glm::vec4(0.0f, 0.0f, 0.0f, 0.0f));
  updateAnime(clock);
}

void	BombGUI::updateAnime(gdl::Clock const &clock)
{
  _state += clock.getElapsed();

  if (!hasBoom())
    scale(glm::vec3(1.0f + clock.getElapsed() / 10.0f, 1.0f + clock.getElapsed() / 10.0f, 1.0f + clock.getElapsed() / 10.0f));
  else
    scale(glm::vec3(0.0f, 0.0f, 0.0f));
}

bool	BombGUI::setAnim(std::string const &obj)
{
  (void)(obj);
  return true;
}

void	BombGUI::setAnim(Data::e_direction dir)
{
  rotate(glm::vec3(0, 1, 0), (float)(_dir - dir) * 90.0f);
  _dir = dir;
}

void  BombGUI::setBoom()
{
  _state = BOMBANIMTIME;
}

bool	BombGUI::hasBoom() const
{
  return (_state > BOMBANIMTIME);
}

bool	BombGUI::boomEnd() const
{
  return (_state > BOMBANIMTIME + BOOMANIMTIME);
}
