#ifndef PLAYER_HH
#define PLAYER_HH

#define NB_BONUS 3
#define RANGE_MAX 5
#define NB_BOMB_MAX 3

#include "ICharacter.hh"
#include "BombManager.hh"
#include "../BomberGUI/PlayerGUI.hh"
#include <map>

class				Player : public ICharacter, public BombManager, public PlayerGUI
{
protected:
  size_t			 _x;
  size_t		         _y;

  size_t			 _id;
  Data::e_type		         _type;

  std::map<int, Data::e_action> *_action;

  typedef void (Player::*mySwitch)(std::string &msg);
  std::map<int, mySwitch>	_mySwitch;

  void				getRangeBonus(std::string &msg);
  void				getBombBonus(std::string &msg);
  void				getSpeedBonus(std::string &msg);
  void				getMalus(std::string &msg);

public:
  Player(size_t id, std::map<int, Data::e_action> *action, glm::vec4 const &color);
  virtual ~Player();

  virtual void			goUp();
  virtual void			goDown();
  virtual void			goLeft();
  virtual void			goRight();

  virtual size_t		getId() const;
  virtual size_t		getX() const;
  virtual size_t		getY() const;
  virtual void			setPos(size_t x, size_t y);
  virtual void			setType(const Data::e_type);

  virtual void			getRandomBonus(std::string &msg);

  virtual Data::e_action	update(gdl::Input *input);
  virtual Data::e_type		getType() const;
};

#endif
