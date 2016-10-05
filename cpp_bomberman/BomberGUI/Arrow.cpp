//
// Arrow.cpp for lol in /home/lerman_v/Git/C++/cpp_bomberman/BomberGUI
// 
// Made by lerman_v
// Login   <lerman_v@epitech.net>
// 
// Started on  Sun May 11 02:51:49 2014 lerman_v
// Last update Fri Jun 13 13:34:30 2014 Boulot
//

#include "Arrow.hh"

Arrow::Arrow(std::string const &textPath)
{
  initialize(textPath);
}

Arrow::~Arrow()
{

}

bool Arrow::initialize(std::string const &textPath)
{
  std::string err;
  if (_texture.load(textPath) == false)
    {
      err = std::string("Cannot load the arrow texture (") + textPath + std::string(")");
      throw my_exception(err.c_str());
    }

  _geometry.setColor(glm::vec4(1, 0, 0, 1));

  // Back
  _geometry.pushVertex(glm::vec3( 0.5, 0.5, 0.0));
  _geometry.pushVertex(glm::vec3( 0.35, 0.0, 0.15));
  _geometry.pushVertex(glm::vec3(-0.5, 0.0, 0.0));
  _geometry.pushUv(glm::vec2(0.1f, 0.9f));
  _geometry.pushUv(glm::vec2(0.9f, 0.1f));
  _geometry.pushUv(glm::vec2(0.9f, 0.9f));

  _geometry.setColor(glm::vec4(0, 1, 0, 1));

  // Front
  _geometry.pushVertex(glm::vec3( 0.5, 0.5,  0.0));
  _geometry.pushVertex(glm::vec3( 0.35, 0.0, -0.15));
  _geometry.pushVertex(glm::vec3(-0.5, 0.0,  0.0));
  _geometry.pushUv(glm::vec2(0.1f, 0.9f));
  _geometry.pushUv(glm::vec2(0.9f, 0.1f));
  _geometry.pushUv(glm::vec2(0.9f, 0.9f));

  _geometry.setColor(glm::vec4(0, 0, 1, 1));

  // Left
  _geometry.pushVertex(glm::vec3(0.5, 0.5,  0.0));
  _geometry.pushVertex(glm::vec3(0.35, 0.0, -0.15));
  _geometry.pushVertex(glm::vec3(0.35, 0.0,  0.15));
  _geometry.pushUv(glm::vec2(0.1f, 0.9f));
  _geometry.pushUv(glm::vec2(0.9f, 0.1f));
  _geometry.pushUv(glm::vec2(0.9f, 0.9f));

  _geometry.setColor(glm::vec4(0, 1, 1, 1));

  // Right
  _geometry.pushVertex(glm::vec3(0.5, -0.5,  0.0));
  _geometry.pushVertex(glm::vec3(0.35,  0.0, -0.15));
  _geometry.pushVertex(glm::vec3(0.35,  0.0,  0.15));
  _geometry.pushUv(glm::vec2(0.1f, 0.9f));
  _geometry.pushUv(glm::vec2(0.9f, 0.1f));
  _geometry.pushUv(glm::vec2(0.9f, 0.9f));

  _geometry.setColor(glm::vec4(1, 0, 1, 1));

  // Up
  _geometry.pushVertex(glm::vec3( 0.5, -0.5, 0.0));
  _geometry.pushVertex(glm::vec3( 0.35,  0.0, 0.15));
  _geometry.pushVertex(glm::vec3(-0.5,  0.0, 0.0));
  _geometry.pushUv(glm::vec2(0.1f, 0.9f));
  _geometry.pushUv(glm::vec2(0.9f, 0.1f));
  _geometry.pushUv(glm::vec2(0.9f, 0.9f));

  _geometry.setColor(glm::vec4(1, 1, 0, 1));

  // Down
  _geometry.pushVertex(glm::vec3( 0.5, -0.5,  0.0));
  _geometry.pushVertex(glm::vec3( 0.35,  0.0, -0.15));
  _geometry.pushVertex(glm::vec3(-0.5,  0.0,  0.0));
  _geometry.pushUv(glm::vec2(0.1f, 0.9f));
  _geometry.pushUv(glm::vec2(0.9f, 0.1f));
  _geometry.pushUv(glm::vec2(0.9f, 0.9f));

  _geometry.build();

  _scale = glm::vec3(1, 0.75, 1);

  return (true);
}

void Arrow::updateAnime(__attribute__((unused))gdl::Clock const &clock)
{

}

void Arrow::draw(gdl::AShader &shader, __attribute__((unused))gdl::Clock const &clock)
{
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_TRIANGLES);
}
