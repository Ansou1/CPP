#ifndef BOMB_HH
#define BOMB_HH

#include "IItem.hh"
#include "../BomberGUI/BombGUI.hh"
#include <map>

class				Bomb : public IItem, public BombGUI
{
private:
  size_t			_idPlayer;
  size_t			_range;
  size_t			_x;
  size_t			_y;

  std::map<int, int>		&_score;

  bool				_done;

  typedef bool (Bomb::*fct1)(Map *, size_t, size_t);

  typedef bool (Bomb::*fct2)(fct1, Map *, size_t);
  std::vector<fct2>		_myAlterMapSwitch;

  bool				explode(Map *map, size_t x, size_t y);
  bool				clear(Map *map, size_t x, size_t y);

  void				alterMap(Map *map, bool (Bomb::*fct)(Map *, size_t, size_t));

  bool				fctUp(fct1 fct, Map *map, size_t i);
  bool				fctDown(fct1 fct, Map *map, size_t i);
  bool				fctRight(fct1 fct, Map *map, size_t i);
  bool				fctLeft(fct1 fct, Map *map, size_t i);

public:
  Bomb(size_t id, size_t range, size_t x, size_t y, std::map<int, int> &score);
  virtual ~Bomb();

  virtual Data::e_bombState	update(Map *map);
  virtual size_t		getId() const;
  size_t			getIdPlayer() const;
  size_t			getRange() const;
  size_t			getX() const;
  size_t			getY() const;
  bool				getDone() const;
  Data::e_item			getType(void) const;
  void				setDone(bool);
};

#endif
