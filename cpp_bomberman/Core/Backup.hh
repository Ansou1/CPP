#include "Player.hh"

struct s_bonus
{
  bool speed;
};

struct s_player
{
  struct s_bonus bonus;
  size_t x;
  size_t y;
  size_t id;
  int    type;
};

struct s_bombe
{
  size_t idPlayer;
  size_t range;
  size_t x;
  size_t y;
  bool done;
};

struct s_backup_header
{
  size_t addr_player;
  size_t addr_bombe;
};
