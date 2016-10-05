#ifndef MAP_HH
#define MAP_HH

#include "Player.hh"
#include "Data.hh"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <stdlib.h>
#include <math.h>

#define RANDOM_PERCENT(x) ((rand() % 100) < x)
#define LINE_SEPARATOR (0x2)

class Map
{
private:
  size_t 			width;
  size_t 			height;
  std::vector<Data::e_case>	map;

public:
  Map(std::list<ICharacter *> &players);
  Map(const size_t x, const size_t y, std::list<ICharacter *> &players, int type = 0);
  Map(const std::string &filename, std::list<ICharacter *> &players);
  Map(const std::string &filename);

  ~Map();
  void			border(void);
  void			generateRandomMap(void);
  void			generateClassicMap(void);
  bool			checkLine(size_t &y, std::list<char> &line);
  bool			check(const std::string &name);
  std::string		&convert_line(const std::string &line);
  void			convert(const std::string &filetoconvert, const std::string &filedest);
  void			save(const std::string &filename) const;
  size_t		getWidth() const;
  size_t		getLength() const;
  Data::e_case		getCase(const size_t x, const size_t y) const;
  void			setCase(const size_t x, const size_t y, const Data::e_case value);
  bool			isAccessible(const size_t x, const size_t y) const;
  bool			player_can_pop(const size_t x, const size_t y) const;
  size_t 		get_free_case_vertical(const size_t x, const size_t y) const;
  size_t 		get_free_case_horizontal(const size_t x, const size_t y) const;
  bool			put_players(std::list<ICharacter *> &players) const;
  void			get_farest_case(const ICharacter *c, size_t &x, size_t &y, size_t &len) const;
  void  		put_player_far(std::list<ICharacter *> &players_put, ICharacter *c) const;

  size_t		getX() const;
  size_t		getY() const;
};

#endif
