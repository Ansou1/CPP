//
// Arrow.hh for lol in /home/lerman_v/Git/C++/cpp_bomberman/BomberGUI
// 
// Made by lerman_v
// Login   <lerman_v@epitech.net>
// 
// Started on  Mon Jun  9 07:26:00 2014 lerman_v
// Last update Fri Jun 13 13:36:06 2014 Boulot
//

#ifndef ARROW_HH_
#define ARROW_HH_

#include "AObject.hh"
#include "../Core/Exception.hpp"
#include <Geometry.hh>
#include <Texture.hh>
#include <string>

class Arrow : public AObject
{
protected:
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;

public:
  Arrow(std::string const &textPath);
  virtual ~Arrow();
  virtual bool initialize(std::string const &textPath);
  virtual void updateAnime(gdl::Clock const &clock);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif /* ARROW_HH_ */
