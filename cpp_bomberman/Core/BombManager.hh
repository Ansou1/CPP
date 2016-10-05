#ifndef BOMBMANAGER_HH
#define BOMBMANAGER_HH

#include <sys/types.h>

class				BombManager
{
protected:
  size_t			_range;
  size_t			_nbBombMax;
  size_t			_nbBomb;
  bool				_hasDrop;

public:
  BombManager();
  ~BombManager();

  bool				hasDropBomb() const;
  bool				canDropBomb() const;
  void				dropBomb();
  void				reload();
  size_t			getRange() const;
};

#endif
