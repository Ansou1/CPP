//
// Bonus.hh for lol in /home/lerman_v/Git/C++/cpp_bomberman/BomberGUI
// 
// Made by lerman_v
// Login   <lerman_v@epitech.net>
// 
// Started on  Mon Jun  2 15:35:16 2014 lerman_v
// Last update Mon Jun  2 19:00:47 2014 lerman_v
//

#ifndef BONUS_HH_
#define BONUS_HH_

#include "Cube.hh"

class Bonus : public Cube
{
private:
  bool	_down;

public:
  Bonus(std::string const &textPath);
  virtual ~Bonus();
  virtual void updateAnime(gdl::Clock const &clock);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif /* BONUS_HH_ */
