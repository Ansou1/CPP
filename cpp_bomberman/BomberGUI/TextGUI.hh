//
// TextGUI.hh for bomberman in /home/plourd_b/rendu/cpp_bomberman/BomberGUI
//
// Made by Alexandre
// Login   <plourd_b@epitech.net>
//
// Started on  Tue May 27 17:10:37 2014 Alexandre
// Last update Wed Jun 11 23:27:47 2014 lerman_v
//

#ifndef TEXTGUI_HH_
# define TEXTGUI_HH_

#include <string>
#include <vector>
#include "Square.hh"

class TextGUI : public AObject
{
  gdl::Texture		_texture;
  std::string	 	_str;
  std::vector<Square *>	_items;
  float			_duration;

public:
  TextGUI(std::string const &str, std::string const &font,
	  glm::vec3 const &camPos, float fov, float ratio,
	  float posX, float posY, float size, float distance,
	  bool rota = false, float duration = 0.0);
  ~TextGUI();

  virtual void	updateAnime(gdl::Clock const &clock);
  virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock);

  bool		outOfDate() const;
  float		getPeriod() const;
  std::string	getStr() const;
};

#endif /* TEXTGUI_HH_ */
