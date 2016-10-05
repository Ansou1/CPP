//
// AObject.hh for lol in /home/lerman_v/Git/C++/cpp_bomberman/BomberGUI
//
// Made by lerman_v
// Login   <lerman_v@epitech.net>
//
// Started on  Fri May 09 12:41:00 2014 lerman_v
// Last update Fri Jun 13 13:40:30 2014 Boulot
//

#ifndef AOBJECT_HH_
#define AOBJECT_HH_

#include <SdlContext.hh>
#include <BasicShader.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include "../Core/Exception.hpp"

class AObject
{
protected:
  glm::vec3  _position;
  glm::vec3  _rotation;
  glm::vec3  _scale;

public:
  AObject();
  virtual ~AObject();

  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock) = 0;
  virtual void updateAnime(gdl::Clock const &clock) = 0;

  void translate(glm::vec3 const &v);
  void rotate(glm::vec3 const& axis, float angle);
  void scale(glm::vec3 const& scale);
  glm::mat4 getTransformation();
};

#endif /* AOBJECT_HH_ */
