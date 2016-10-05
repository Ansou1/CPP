//
// Background.hh for lol in /home/lerman_v/Git/C++/cpp_bomberman/BomberGUI
//
// Made by lerman_v
// Login   <lerman_v@epitech.net>
//
// Started on  Fri May 30 12:38:09 2014 lerman_v
// Last update Thu Jun 12 15:44:59 2014 Alexandre
//

#ifndef BACKGROUND_HH_
#define BACKGROUND_HH_

#include "AObject.hh"
#include <Geometry.hh>
#include <Texture.hh>
#include <string>

class Background : public AObject
{
private:
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;
  bool		_isFront;

public:
  Background(std::string const &textPath, glm::vec3 const &pos, float fov, float ratio, bool front = false);
  ~Background();

  void	resetPos(glm::vec3 const &pos, float fov, float ratio);

  virtual bool initialize(std::string const &textPath);
  virtual void updateAnime(gdl::Clock const &clock);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);

};

#endif /* BACKGROUND_HH_ */
