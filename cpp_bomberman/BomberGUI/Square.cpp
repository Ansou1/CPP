//
// Square.cpp for lol in /home/lerman_v/Git/C++/cpp_bomberman/BomberGUI
// 
// Made by lerman_v
// Login   <lerman_v@epitech.net>
// 
// Started on  Sat May 31 02:20:02 2014 lerman_v
// Last update Mon Jun  9 16:42:09 2014 Boulot
//

#include "Square.hh"

// x = xMin // y = yMin // z = xMax // w = yMax

Square::Square(const gdl::Texture &text, glm::vec2 const &texPos,
	       glm::vec3 const &pos, glm::vec3 const &rot, glm::vec3 const &scale)
{
  _position = pos;
  _rotation = rot;
  _scale = scale;

  _texture = text;

  _geometry.setColor(glm::vec4(1, 1, 1, 1));

  _geometry.pushVertex(glm::vec3(0.50f, 0.50f, 0.0f));
  _geometry.pushVertex(glm::vec3(0.50f, -0.5f, 0.0f));
  _geometry.pushVertex(glm::vec3(-0.5f, -0.5f, 0.0f));
  _geometry.pushVertex(glm::vec3(-0.5f, 0.50f, 0.0f));


  _geometry.pushUv(glm::vec2(texPos.x, texPos.y + 1.0 / 3.0));
  _geometry.pushUv(glm::vec2(texPos.x, texPos.y));
  _geometry.pushUv(glm::vec2(texPos.x + 1.0 / 26.0, texPos.y));
  _geometry.pushUv(glm::vec2(texPos.x + 1.0 / 26.0, texPos.y + 1.0 / 3.0));

  _geometry.build();
}

Square::~Square()
{

}

void Square::updateAnime(gdl::Clock const &clock)
{
  (void)(clock);
}

void Square::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
