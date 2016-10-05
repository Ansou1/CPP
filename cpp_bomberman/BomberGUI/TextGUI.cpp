//
// TextGUI.cpp for bomberman in /home/plourd_b/rendu/cpp_bomberman/BomberGUI
//
// Made by Alexandre
// Login   <plourd_b@epitech.net>
//
// Started on  Tue May 27 16:55:54 2014 Alexandre
// Last update Fri Jun 13 14:07:47 2014 Boulot
//

#include "TextGUI.hh"

#define PI 3.14159265

TextGUI::TextGUI(std::string const &str, std::string const &font,
		 glm::vec3 const &camPos, float fov, float ratio,
		 float posX, float posY, float size, float distance,
		 bool rota, float duration) :
  _str(str), _duration(duration)
{
  float		Thales;
  float		hypotenuse;
  float		angle;

  float		alpha = -(atan(camPos.y / camPos.z));
  float		beta = -atan(camPos.x / camPos.z);

  /// Data Square
  glm::vec3	pos(0, 0, 0);
  glm::vec3	rot(0, 0, 0);
  glm::vec3	scale(size, size, size);
  glm::vec2	c(0, 0);

  /// Calcul Taille Plan XY
  float		sizeX = distance * tan(ratio * fov * PI / 180.0) * 2.0;
  float		sizeY = distance * tan(fov * PI / 180.0) * 2.0;

  if (_texture.load(font) == false)
    {
      std::string err;
      err = std::string("Cannot load the texture : ") + font;
      throw my_exception(err.c_str());
    }

  /// Rotation Rad
  rot.x = alpha * 180 / PI;
  rot.y = beta * 180 / PI + (rota ? 180 : 0);

  /// Calcul Coef Thales
  Thales = distance / sqrt(pow(camPos.x, 2.0) + pow(camPos.y, 2.0) + pow(camPos.z, 2.0));

  for (size_t i = 0; i < str.length(); ++i)
    {
      if (str[i] == ' ')
	continue;

      /// Placement Sur Plan XY
      pos.x = -(posX * sizeX - sizeX / 2.0 + i * scale.x) * (rota ? -1.0 : 1.0);
      pos.y = -(posY * sizeY - sizeY / 2.0);
      pos.z = 0.0;

      if (alpha)
	{
	  /// Rotation X
	  pos.z = pos.y * sin(alpha);
	  pos.y = pos.y * cos(alpha);
	}

      if (beta)
	{
	  /// Rotation Y
	  hypotenuse = sqrt(pow(pos.x, 2.0) + pow(pos.z, 2.0));
	  angle = atan(pos.z / pos.x) + beta;
 
	  pos.x = hypotenuse * cos(angle);
	  pos.z = hypotenuse * sin(angle);
	}

      /// Translation a [distance] de [camPos]
      pos.x += camPos.x - (camPos.x * Thales);
      pos.y += camPos.y - (camPos.y * Thales);
      pos.z += camPos.z - (camPos.z * Thales);

      c.x = (1.0 / 26.0)
	* ('a' <= str[i] && str[i] <= 'z' ? str[i] - 'a' : 1.0)
	* ('A' <= str[i] && str[i] <= 'Z' ? str[i] - 'A' : 1.0)
	* ('0' <= str[i] && str[i] <= '9' ? str[i] - '0' : 1.0)
	* ('.' == str[i] ? 10.0 : 1.0)
	* ('-' == str[i] ? 11.0 : 1.0)
	* ('_' == str[i] ? 12.0 : 1.0);
      c.y = (1.0 / 3.0)
	* (('a' <= str[i] && str[i] <= 'z' ? 1.0 : 0.0)
	   + ('A' <= str[i] && str[i] <= 'Z' ? 2.0 : 0.0));

      _items.push_back(new Square(_texture, c, pos, rot, scale));
    }
}

TextGUI::~TextGUI()
{
  for (std::vector<Square *>::iterator it = _items.begin() ; it != _items.end(); ++it)
    delete((*it));
}

void	TextGUI::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  for (std::vector<Square *>::iterator it = _items.begin() ; it != _items.end(); ++it)
    (*it)->draw(shader, clock);
}
void	TextGUI::updateAnime(gdl::Clock const &clock)
{
  _duration -= clock.getElapsed();
}

bool	TextGUI::outOfDate() const
{
  return _duration <= 0.0;
}

float	TextGUI::getPeriod() const
{
  return _duration;
}

std::string	TextGUI::getStr() const
{
  return _str;
}
