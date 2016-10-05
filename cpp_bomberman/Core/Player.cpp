#include "Player.hh"

Player::Player(size_t id, std::map<int, Data::e_action> *action, glm::vec4 const &color)
  : BombManager(), PlayerGUI(color)
{
  _x = 0;
  _y = 0;
  _id = id;

  _action = action;

  _type = Data::HUMAN;

  for (int i = 0; i < 3; i++)
    _mySwitch[i] = &Player::getRangeBonus;
  for (int i = 3; i < 6; i++)
    _mySwitch[i] = &Player::getBombBonus;
  for (int i = 6; i < 9; i++)
    _mySwitch[i] = &Player::getSpeedBonus;
  _mySwitch[9] = &Player::getMalus;
}

Player::~Player()
{
}

void			Player::goUp()
{
  _y--;
}

void			Player::goDown()
{
  _y++;
}

void			Player::goLeft()
{
  _x--;
}

void			Player::goRight()
{
  _x++;
}

size_t			Player::getId() const
{
  return (_id);
}

size_t			Player::getX() const
{
  return (_x);
}

size_t			Player::getY() const
{
  return (_y);
}

void			Player::setPos(size_t x, size_t y)
{
  _x = x;
  _y = y;
}

void			Player::getRandomBonus(std::string &msg)
{
  (this->*_mySwitch[rand() % 10])(msg);
}

Data::e_action		Player::update(gdl::Input *input)
{
  Data::e_action	ret = Data::WAIT;

  for (std::map<int, Data::e_action>::iterator it = _action->begin(); it != _action->end(); ++it){
    if (input->getKey(it->first))
      {
	if (it->second == Data::DROP_BOMB)
	  return (Data::DROP_BOMB);
	else
	  ret = it->second;
      }
    }
  return (ret);
}

Data::e_type		Player::getType() const
{
  return (_type);
}

void			Player::setType(const Data::e_type t)
{
  this->_type = t;
}

void			Player::getRangeBonus(std::string &msg)
{
  msg += "got a range booster !";
  _range++;
}

void			Player::getBombBonus(std::string &msg)
{
  msg += "can drop more bombs !";
  _nbBombMax++;
  _nbBomb++;
}

void			Player::getSpeedBonus(std::string &msg)
{
  msg += "run faster now !";
  _speed += 0.5;
}

void			Player::getMalus(std::string &msg)
{
  msg += "has lost all his bonuses !";
  _range = 2;
  _nbBombMax = 1;
  _nbBomb = 1;
  _speed = 1;
}
