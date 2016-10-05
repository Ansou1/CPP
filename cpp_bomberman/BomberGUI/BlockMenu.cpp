//
// BlockMenu.cpp for lol in /home/lerman_v/Git/C++/cpp_bomberman/BomberGUI
// 
// Made by lerman_v
// Login   <lerman_v@epitech.net>
// 
// Started on  Mon May 12 00:27:36 2014 lerman_v
// Last update Fri Jun 13 13:41:57 2014 Boulot
//

#include "BlockMenu.hh"

BlockMenu::BlockMenu(std::string const &textPath)
{
  initialize(textPath);
}

BlockMenu::~BlockMenu()
{

}

bool BlockMenu::initialize(std::string const &textPath)
{
  _speed = 500.0f;
  _curentAnime = BlockMenu::ANY;
  if (_texture.load(textPath.c_str()) == false)
    {
      std::string err;
      err = std::string("Cannot load the cube texture (") + textPath + std::string (")");
      throw my_exception(err.c_str());
    }

  _geometry.setColor(glm::vec4(1, 1, 1, 1));

  // UP
  _geometry.pushVertex(glm::vec3(3, -0.5, 0.5));
  _geometry.pushVertex(glm::vec3(3, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-3, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-3, -0.5, 0.5));
  _geometry.pushUv(glm::vec2(0.00f, 0.50f));
  _geometry.pushUv(glm::vec2(0.00f, 0.00f));
  _geometry.pushUv(glm::vec2(1.0f / 14.0f * 6.0f, 0.00f));
  _geometry.pushUv(glm::vec2(1.0f / 14.0f * 6.0f, 0.50f));

  // DOWN
  _geometry.pushVertex(glm::vec3(3, -0.5, -0.5));
  _geometry.pushVertex(glm::vec3(3, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(-3, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(-3, -0.5, -0.5));
  _geometry.pushUv(glm::vec2(1.0f / 14.0f * 6.0f, 0.00f));
  _geometry.pushUv(glm::vec2(1.0f / 14.0f * 6.0f, 0.50f));
  _geometry.pushUv(glm::vec2(1.0f / 14.0f * 12.0f, 0.50f));
  _geometry.pushUv(glm::vec2(1.0f / 14.0f * 12.0f, 0.00f));

  // LEFT
  _geometry.pushVertex(glm::vec3(3, -0.5, -0.5));
  _geometry.pushVertex(glm::vec3(3, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(3, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(3, -0.5, 0.5));
  _geometry.pushUv(glm::vec2(1.0f / 14.0f * 12.0f, 1.00f));
  _geometry.pushUv(glm::vec2(1.0f / 14.0f * 12.0f, 0.50f));
  _geometry.pushUv(glm::vec2(1.0f / 14.0f * 13.0f, 0.50f));
  _geometry.pushUv(glm::vec2(1.0f / 14.0f * 13.0f, 1.00f));


  // RIGHT
  _geometry.pushVertex(glm::vec3(-3, -0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-3, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-3, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(-3, -0.5, -0.5));
  _geometry.pushUv(glm::vec2(1.00f, 0.50f));
  _geometry.pushUv(glm::vec2(1.00f, 1.00f));
  _geometry.pushUv(glm::vec2(1.0f / 14.0f * 13.0f, 1.00f));
  _geometry.pushUv(glm::vec2(1.0f / 14.0f * 13.0f, 0.50f));

  // FRONT
  _geometry.pushVertex(glm::vec3(3, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(3, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(-3, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(-3, 0.5, 0.5));
  _geometry.pushUv(glm::vec2(1.0f / 14.0f * 6.0f, 0.50f));
  _geometry.pushUv(glm::vec2(1.0f / 14.0f * 6.0f, 1.00f));
  _geometry.pushUv(glm::vec2(0.00f, 1.00f));
  _geometry.pushUv(glm::vec2(0.00f, 0.50f));

  // BACK
  _geometry.pushVertex(glm::vec3(3, -0.5, -0.5));
  _geometry.pushVertex(glm::vec3(3, -0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-3, -0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-3, -0.5, -0.5));
  _geometry.pushUv(glm::vec2(1.0f / 14.0f * 12.0f, 0.50f));
  _geometry.pushUv(glm::vec2(1.0f / 14.0f * 12.0f, 1.00f));
  _geometry.pushUv(glm::vec2(1.0f / 14.0f * 6.0f, 1.00f));
  _geometry.pushUv(glm::vec2(1.0f / 14.0f * 6.0f, 0.50f));

  _geometry.build();
  return (true);
}

void BlockMenu::updateAnime(gdl::Clock const &clock)
{
  float		nextMove;

  if (_curentAnime == BlockMenu::ANY)
    return ;
  nextMove = (_curentAnime == BlockMenu::SELECT ? 1.0f : -1.0f) *
    static_cast<float>(clock.getElapsed()) * _speed;
  if ((_curentAnime == BlockMenu::SELECT && (_state + nextMove) > (float)BlockMenu::SELECT) ||
      (_curentAnime == BlockMenu::UNSELECT && (_state + nextMove) < (float)BlockMenu::UNSELECT))
    {
      nextMove = (float)_curentAnime - _state;
      _curentAnime = BlockMenu::ANY;
    }
  rotate(glm::vec3(1, 0, 0), nextMove);
  _state += nextMove;
}

void BlockMenu::setAnime(BlockMenu::AnimeBlockMenu newAnime)
{
  _curentAnime = newAnime;
}

void BlockMenu::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  updateAnime(clock);
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
