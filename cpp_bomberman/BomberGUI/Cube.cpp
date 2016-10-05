//
// Cube.cpp for lol in /home/lerman_v/Git/C++/cpp_bomberman/BomberGUI
// 
// Made by lerman_v
// Login   <lerman_v@epitech.net>
// 
// Started on  Sun May 11 02:51:49 2014 lerman_v
// Last update Fri Jun 13 13:47:27 2014 Boulot
//

#include "Cube.hh"

Cube::Cube(std::string const &textPath)
{
  initialize(textPath);
}

Cube::~Cube()
{

}

bool Cube::initialize(std::string const &textPath)
{
  if (_texture.load(textPath) == false)
    {
      std::string err;

      err = std::string("Cannot load the cube texture (") + textPath + std::string(")");
      throw my_exception(err.c_str());
    }

  _geometry.setColor(glm::vec4(1, 1, 1, 1));

  // Back
  _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
  _geometry.pushUv(glm::vec2(0.25f, 0.00f));
  _geometry.pushUv(glm::vec2(0.25f, 0.50f));
  _geometry.pushUv(glm::vec2(0.00f, 0.50f));
  _geometry.pushUv(glm::vec2(0.00f, 0.00f));

  // Front
  _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
  _geometry.pushUv(glm::vec2(0.250f, 0.00f));
  _geometry.pushUv(glm::vec2(0.25f, 0.50f));
  _geometry.pushUv(glm::vec2(0.50f, 0.50f));
  _geometry.pushUv(glm::vec2(0.50f, 0.00f));

  // Left
  _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
  _geometry.pushUv(glm::vec2(0.25f, 0.50f));
  _geometry.pushUv(glm::vec2(0.25f, 1.00f));
  _geometry.pushUv(glm::vec2(0.00f, 1.00f));
  _geometry.pushUv(glm::vec2(0.00f, 0.50f));

  // Right
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
  _geometry.pushUv(glm::vec2(0.50f, 0.50f));
  _geometry.pushUv(glm::vec2(0.50f, 1.00f));
  _geometry.pushUv(glm::vec2(0.25f, 1.00f));
  _geometry.pushUv(glm::vec2(0.25f, 0.50f));

  // Up
  _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  _geometry.pushUv(glm::vec2(0.50f, 1.00f));
  _geometry.pushUv(glm::vec2(0.50f, 0.50f));
  _geometry.pushUv(glm::vec2(0.75f, 0.50f));
  _geometry.pushUv(glm::vec2(0.75f, 1.00f));

  // Down
  _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
  _geometry.pushUv(glm::vec2(1.00f, 0.50f));
  _geometry.pushUv(glm::vec2(1.00f, 1.00f));
  _geometry.pushUv(glm::vec2(0.75f, 1.00f));
  _geometry.pushUv(glm::vec2(0.75f, 0.50f));

  _geometry.build();
  return (true);
}

void Cube::updateAnime(gdl::Clock const &clock)
{
  (void)(clock);
}

void Cube::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
