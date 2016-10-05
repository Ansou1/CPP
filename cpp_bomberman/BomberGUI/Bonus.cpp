//
// Bonus.cpp for lol in /home/lerman_v/Git/C++/cpp_bomberman/BomberGUI
// 
// Made by lerman_v
// Login   <lerman_v@epitech.net>
// 
// Started on  Mon Jun  2 15:39:50 2014 lerman_v
// Last update Tue Jun  3 22:59:28 2014 lerman_v
//

#include "Bonus.hh"

Bonus::Bonus(std::string const &textPath) : Cube(textPath)
{
  scale(glm::vec3(0.75, 0.75, 0.75));
}

Bonus::~Bonus()
{

}


void	Bonus::updateAnime(gdl::Clock const &clock)
{
  if (_rotation.x > 360)
    _rotation = glm::vec3(_rotation.x - 360.0, _rotation.y - 360.0, _rotation.z - 360.0);
  if (_position.y > 0.5)
    _down = true;
  if (_position.y < 0.0)
    _down = false;
  rotate(glm::vec3(1, 1, 1), clock.getElapsed() * 100.0);
  translate(glm::vec3(0.0, clock.getElapsed() * (_down ? -1.0 : 1.0) / 2.0, 0.0));
}
  
void	Bonus::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)(clock);
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
