//
// Square.hh for lol in /home/lerman_v/Git/C++/cpp_bomberman/BomberGUI
// 
// Made by lerman_v
// Login   <lerman_v@epitech.net>
// 
// Started on  Sat May 31 01:10:55 2014 lerman_v
// Last update Sat May 31 04:42:36 2014 lerman_v
//

#ifndef SQUARE_HH_
#define SQUARE_HH_

#include "AObject.hh"
#include <Geometry.hh>
#include <Texture.hh>
#include <string>

class Square : public AObject
{
private:
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;

public:
  Square(const gdl::Texture &text, glm::vec2 const &texPos,
	 glm::vec3 const &pos, glm::vec3 const &rot, glm::vec3 const &scale);
  ~Square();

  virtual void updateAnime(gdl::Clock const &clock);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);

};

#endif /* SQUARE_HH_ */
