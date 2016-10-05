#include "Bomb.hh"

Bomb::Bomb(size_t id, size_t range, size_t x, size_t y, std::map<int, int> &score)
  : BombGUI(), _idPlayer(id), _range(range), _x(x), _y(y), _score(score), _done(false)
{
  _myAlterMapSwitch.push_back(&Bomb::fctUp);
  _myAlterMapSwitch.push_back(&Bomb::fctDown);
  _myAlterMapSwitch.push_back(&Bomb::fctRight);
  _myAlterMapSwitch.push_back(&Bomb::fctLeft);
}

Bomb::~Bomb()
{
}

Data::e_bombState	Bomb::update(Map *map)
{
  if (!_done && (hasBoom() || map->getCase(_x, _y) == Data::BOOM || map->getCase(_x, _y) == Data::BOOM2))
    {
      _done = true;
      alterMap(map, &Bomb::explode);
      setBoom();
      return (Data::BOMB_EXPLODE);
    }
  if (boomEnd())
    {
      alterMap(map, &Bomb::clear);
      return (Data::BOMB_END);
    }
  return (Data::BOMB_DEFAULT);
}

size_t			Bomb::getId() const
{
  return (_idPlayer);
}

bool			Bomb::explode(Map *map, size_t x, size_t y)
{
  Data::e_case		tmp;

  tmp = map->getCase(x, y);
  if (tmp == Data::CRATE)
    {
      _score[_idPlayer] += 100;
      map->setCase(x, y, Data::BOOM2);
      return (false);
    }
  else if (tmp == Data::WALL)
    return (false);
  else
    map->setCase(x, y, Data::BOOM);
  return (true);
}

bool			Bomb::clear(Map *map, size_t x, size_t y)
{
  Data::e_case		tmp;

  tmp = map->getCase(x, y);
  if (tmp == Data::BOOM2)
    {
      if (rand() % 5 == 3)
  	map->setCase(x, y, Data::BONUS);
      else
  	map->setCase(x, y, Data::EMPTY);
      return (false);
    }
  else if (tmp == Data::BOOM)
    {
      map->setCase(x, y, Data::EMPTY);
      return (true);
    }
  return (true);
}

void			Bomb::alterMap(Map *map, fct1 fct)
{
  bool			tab[4];

  for (int i = 0; i < 4; i++)
    tab[i] = true;
  (this->*fct)(map, _x, _y);
  for (size_t i = 1; i <= _range; i++)
    for (int j = 0; j < 4; j++)
      if (tab[j])
	tab[j] = (this->*_myAlterMapSwitch[j])(fct, map, i);
}

bool			Bomb::fctUp(fct1 fct, Map *map, size_t i)
{
  return ((this->*fct)(map, _x + i, _y));
}

bool			Bomb::fctDown(fct1 fct, Map *map, size_t i)
{
  return ((this->*fct)(map, _x - i, _y));
}

bool			Bomb::fctLeft(fct1 fct, Map *map, size_t i)
{
  return ((this->*fct)(map, _x, _y - i));
}

bool			Bomb::fctRight(fct1 fct, Map *map, size_t i)
{
  return ((this->*fct)(map, _x, _y + i));
}

Data::e_item		Bomb::getType(void) const
{
  return (Data::BOMBE);
}

size_t			Bomb::getIdPlayer() const{
  return this->_idPlayer;
}

size_t			Bomb::getRange() const{
  return this->_range;
}

size_t			Bomb::getX() const{
  return this->_x;
}

size_t			Bomb::getY() const{
  return this->_y;
}

bool			Bomb::getDone() const{
  return this->_done;
}

void			Bomb::setDone(bool src)
{
  this->_done = src;
}
