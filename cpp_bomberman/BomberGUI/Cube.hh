//
// Cube.hh for lol in /home/lerman_v/Git/C++/cpp_bomberman/BomberGUI
//
// Made by lerman_v
// Login   <lerman_v@epitech.net>
//
// Started on  Fri May 09 12:40:54 2014 lerman_v
// Last update Mon Jun  2 15:38:38 2014 lerman_v
//

#ifndef CUBE_HH_
#define CUBE_HH_

#include "AObject.hh"
#include <Geometry.hh>
#include <Texture.hh>
#include <string>

class Cube : public AObject
{
protected:
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;

public:
  Cube(std::string const &textPath);
  virtual ~Cube();
  virtual bool initialize(std::string const &textPath);
  virtual void updateAnime(gdl::Clock const &clock);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif /* CUBE_HH_ */
