#ifndef DATA_HH
#define DATA_HH

namespace Data
{
  enum e_case
    {
      OUT = 0,
      EMPTY = 10,
      WALL = 20,
      CRATE = 30,
      BONUS = 40,
      BOOM = 50,
      BOOM2 = 80,
      BOMB = 60
    };

  enum e_direction
    {
      DOWN,
      RIGHT,
      UP,
      LEFT
    };

  enum e_action
    {
      GO_DOWN,
      GO_RIGHT,
      GO_UP,
      GO_LEFT,
      DROP_BOMB,
      WAIT
    };

  enum e_type
    {
      HUMAN,
      AI
    };

  enum e_bombState
    {
      BOMB_END,
      BOMB_EXPLODE,
      BOMB_DEFAULT
    };

  enum e_item
    {
      BOMBE
    };
}

#endif
