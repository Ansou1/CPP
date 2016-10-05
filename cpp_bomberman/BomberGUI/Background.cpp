//
// Background.cpp for lol in /home/lerman_v/Git/C++/cpp_bomberman/BomberGUI
// 
// Made by lerman_v
// Login   <lerman_v@epitech.net>
// 
// Started on  Fri May 30 14:58:12 2014 lerman_v
// Last update Fri Jun 13 13:39:29 2014 Boulot
//

#include "Background.hh"

#define PI 3.14159265f

Background::Background(std::string const &textPath, glm::vec3 const &pos, float fov, float ratio, bool front)
{
  initialize(textPath);
  _isFront = front;

  resetPos(pos, fov, ratio);
}

Background::~Background()
{

}

void	Background::resetPos(glm::vec3 const &pos, float fov, float ratio)
{
  _position = glm::vec3(0, 0, 0);
  _rotation = glm::vec3(0, 0, 0);
  _scale = glm::vec3(1.0, 1.0, 1.0);

  fov /= 2.0f;

  translate(pos);


  if (pos.z != 0.0)
    {
      rotate(glm::vec3(-1, 0, 0), atan(pos.y / pos.z) * 180 / PI);
    }

  if (pos.z != 0.0)
    {
      rotate(glm::vec3(0, 1, 0), atan(pos.x / pos.z) * 180 / PI);
    }

  scale(glm::vec3(sqrt(pow(2.0 * pos.x, 2.0) + pow(2.0 * pos.y, 2.0) + pow(2.0 * pos.z, 2.0))
		  * tan(ratio * fov * PI / 180.0f) * 2.0 - 4.0,
		  sqrt(pow(2.0 * pos.x, 2.0) + pow(2.0 * pos.y, 2.0) + pow(2.0 * pos.z, 2.0))
		  * tan(fov * PI / 180.0) * 2.0 ,
		  1.0)
	);

  if (_isFront)
    rotate(glm::vec3(0, 1, 0), 180.0);
}

bool Background::initialize(std::string const &textPath)
{
  std::string err;

  if (_texture.load(textPath) == false)
    {
      err = std::string("Cannot load texture (") + textPath + std::string (")");
      throw my_exception(err.c_str());
    }

  _geometry.setColor(glm::vec4(1, 1, 1, 1));

  _geometry.pushVertex(glm::vec3(0.50f, 0.50f, 0.0f));
  _geometry.pushVertex(glm::vec3(0.50f, -0.5f, 0.0f));
  _geometry.pushVertex(glm::vec3(-0.5f, -0.5f, 0.0f));
  _geometry.pushVertex(glm::vec3(-0.5f, 0.50f, 0.0f));

  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  _geometry.build();
  return (true);
}

void Background::updateAnime(gdl::Clock const &clock)
{
  (void)(clock);
}

void Background::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
