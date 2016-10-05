#include "Exception.hpp"
#include "Map.hh"

Map::Map(std::list<ICharacter *> &players)
{
  srand(time(NULL));
  this->width = 30;
  this->height = 10;

  border();

  // B
  setCase(2, 2, Data::CRATE);
  setCase(3, 2, Data::CRATE);
  setCase(4, 2, Data::CRATE);
  setCase(2, 3, Data::CRATE);
  setCase(5, 3, Data::CRATE);
  setCase(2, 4, Data::CRATE);
  setCase(3, 4, Data::CRATE);
  setCase(4, 4, Data::CRATE);
  setCase(2, 5, Data::CRATE);
  setCase(5, 5, Data::CRATE);
  setCase(2, 6, Data::CRATE);
  setCase(5, 6, Data::CRATE);
  setCase(2, 7, Data::CRATE);
  setCase(3, 7, Data::CRATE);
  setCase(4, 7, Data::CRATE);

  // O
  setCase(8, 3, Data::CRATE);
  setCase(9, 3, Data::CRATE);
  setCase(7, 4, Data::CRATE);
  setCase(10, 4, Data::CRATE);
  setCase(7, 5, Data::CRATE);
  setCase(10, 5, Data::CRATE);
  setCase(7, 6, Data::CRATE);
  setCase(10, 6, Data::CRATE);
  setCase(8, 7, Data::CRATE);
  setCase(9, 7, Data::CRATE);

  // M
  setCase(12, 2, Data::CRATE);
  setCase(16, 2, Data::CRATE);
  setCase(12, 3, Data::CRATE);
  setCase(13, 3, Data::CRATE);
  setCase(15, 3, Data::CRATE);
  setCase(16, 3, Data::CRATE);
  setCase(12, 4, Data::CRATE);
  setCase(14, 4, Data::CRATE);
  setCase(16, 4, Data::CRATE);
  setCase(12, 5, Data::CRATE);
  setCase(16, 5, Data::CRATE);
  setCase(12, 6, Data::CRATE);
  setCase(16, 6, Data::CRATE);
  setCase(12, 7, Data::CRATE);
  setCase(16, 7, Data::CRATE);


  // B
  setCase(18, 2, Data::CRATE);
  setCase(19, 2, Data::CRATE);
  setCase(20, 2, Data::CRATE);
  setCase(18, 3, Data::CRATE);
  setCase(21, 3, Data::CRATE);
  setCase(18, 4, Data::CRATE);
  setCase(19, 4, Data::CRATE);
  setCase(20, 4, Data::CRATE);
  setCase(18, 5, Data::CRATE);
  setCase(21, 5, Data::CRATE);
  setCase(18, 6, Data::CRATE);
  setCase(21, 6, Data::CRATE);
  setCase(18, 7, Data::CRATE);
  setCase(19, 7, Data::CRATE);
  setCase(20, 7, Data::CRATE);

  // Y
  setCase(23, 2, Data::CRATE);
  setCase(27, 2, Data::CRATE);
  setCase(23, 3, Data::CRATE);
  setCase(27, 3, Data::CRATE);
  setCase(24, 4, Data::CRATE);
  setCase(26, 4, Data::CRATE);
  setCase(25, 5, Data::CRATE);
  setCase(25, 6, Data::CRATE);
  setCase(25, 7, Data::CRATE);

  std::list<ICharacter *>::iterator it = players.begin();

  (*it)->setPos(1, 1);
  (dynamic_cast<Player *>(*it))->initPos(1.0 - (float)width / 2.0f,
					 1.0 - (float)height / 2.0f);
  it++;
  (*it)->setPos(1, 8);
  (dynamic_cast<Player *>(*it))->initPos(1.0 - (float)width / 2.0f,
					 8.0 - (float)height / 2.0f);
  it++;
  (*it)->setPos(28, 1);
  (dynamic_cast<Player *>(*it))->initPos(28.0 - (float)width / 2.0f,
					 1.0 - (float)height / 2.0f);
  it++;
  (*it)->setPos(28, 8);
  (dynamic_cast<Player *>(*it))->initPos(28.0 - (float)width / 2.0f,
					 8.0 - (float)height / 2.0f);
}

Map::Map(const size_t x, const size_t y, std::list<ICharacter *> &players, int type)
{
  int ctr = 0;
  srand(time(NULL));
  this->width = x;
  this->height = y;
  if (type == 0)
    generateRandomMap();
  else
    generateClassicMap();
  while (!put_players(players))
    {
      for (size_t yy = 1; yy < height - 1; ++yy){
	for (size_t xx = 1; xx < width - 1; ++xx){
	  setCase(xx, yy, Data::EMPTY);
	}
      }
      generateRandomMap();
      if (ctr == 50)
	throw my_exception("Met de bon parametre abruttit");
      ++ctr;
    }
}

Map::Map(const std::string &filename, std::list<ICharacter *> &players)
{
  this->width = 0;
  this->height = 0;
  check(filename);
  put_players(players);
}

Map::Map(const std::string &filename)
{
  this->width = 0;
  this->height = 0;
  check(filename);
}

void Map::border(void)
{
  for (size_t y = 0; y < height; ++y){
    for (size_t x = 0; x < width; ++x){
      if (y == 0 || x == 0 || x == width - 1 || y == height - 1)
        map.push_back(Data::WALL);
      else
        map.push_back(Data::EMPTY);
    }
  }
}

void		Map::generateClassicMap(void)
{
  border();
  for (size_t y = 1; y < height - 1; ++y){
    for (size_t x = 1; x < width - 1; ++x){
      if (y % 2 == 0 && x % 2 == 0)
	setCase(x, y, Data::WALL);
      else if (RANDOM_PERCENT(60))
       	setCase(x, y, Data::CRATE);
	}
  }
}

void		Map::generateRandomMap(void)
{
  border();
  for (size_t y = 1; y < height - 1; ++y){
    for (size_t x = 1; x < width - 1; ++x){
      if (RANDOM_PERCENT(15))
	setCase(x, y, Data::WALL);
      else if (RANDOM_PERCENT(60))
       	setCase(x, y, Data::CRATE);
	}
  }
}

bool Map::checkLine(size_t &y, std::list<char> &line)
{
  if (y == 0)
    {
      width = line.size();
    }
  else
    {
      if (line.size() != width)
	{
	  throw my_exception("Invalide map.");
	  return (false);
	}
    }
  for (std::list<char>::iterator it = line.begin(); it != line.end(); ++it)
    {
      map.push_back(static_cast<Data::e_case>(*it));
    }
  ++y;
  return (true);
}

bool Map::check(const std::string &name)
{
  std::ifstream file(name.c_str(), std::ios::in);
  char 				c;
  std::list<char> 	line;
  size_t 			y;

  y = 0;
  if (!file)
    {
      throw my_exception("file format not reconized");
      return (false);
    }
  while (file.get(c))
    {
      if (c == (char)LINE_SEPARATOR)
	{
	  if (!checkLine(y, line))
	    return (false);
	  line.clear();
	}
      else
	{
	  line.push_back(c);
	}
    }
  height = y;
  return (true);
}

std::string &Map::convert_line(const std::string &line)
{
  std::string *file = new std::string;
  std::map<unsigned char, Data::e_case> sym;

  *file = line;
  sym[' '] = Data::EMPTY;
  sym['w'] = Data::WALL;
  sym['c'] = Data::CRATE;
  std::string::iterator it2 = file->begin();
  for (std::string::const_iterator it = line.begin(); it != line.end(); ++it){
    if (sym.find(*it) == sym.end())
      *it2 = Data::EMPTY;
    else
      *it2 = sym[*it];
    ++it2;
  }
  return (*file);
}

void Map::convert(const std::string &filetoconvert, const std::string &filedest)
{
  std::ifstream file(filetoconvert.c_str(), std::ios::in);
  std::ofstream fileto(filedest.c_str(), std::ios::out | std::ios::trunc);
  std::string line;

  if (!(file))
    {
      std::cerr << "convert map failed" << std::endl;
      return ;
    }
  while (getline(file, line))
    fileto << convert_line(line) << (char)LINE_SEPARATOR;
  file.close();
  fileto.close();
}

//export la map dans un fichier
void Map::save(const std::string &filename) const
{
  std::ofstream file(filename.c_str(), std::ios::out | std::ios::trunc);
  if (!file)
    throw my_exception("save is not possible");
  for (size_t y = 0; y < height; ++y){
    for (size_t x = 0; x < width; ++x){
      file << (char)getCase(x, y);
    }
    file << (char)LINE_SEPARATOR;
  }
}

size_t			Map::getWidth() const
{
  return (width);
}

size_t			Map::getLength() const
{
  return (height);
}

Data::e_case		Map::getCase(const size_t x, const size_t y) const
{
  if (x >= width || y >= height)
    return Data::OUT;
  return (map[y * width + x]);
}

void Map::setCase(const size_t x, const size_t y, const Data::e_case value)
{
  map[y * width + x] = value;
}

bool Map::isAccessible(const size_t x, const size_t y) const
{
  if (x >= width || y >= height)
    return false;
  Data::e_case s = map[y * width + x];
  return (s == Data::EMPTY || s == Data::BONUS || s == Data::BOOM || s == Data::BOOM2);
}

Map::~Map()
{

}

size_t Map::get_free_case_vertical(const size_t x, const size_t y) const
{
  size_t ctr = 1;

  for (size_t i = y-1; getCase(x, i) == Data::EMPTY; --i)
    ++ctr;
  for (size_t i = y+1; getCase(x, i) == Data::EMPTY; ++i)
    ++ctr;

  return ctr;
}

size_t Map::get_free_case_horizontal(const size_t x, const size_t y) const
{
  size_t ctr = 1;

  for (size_t i = x-1; getCase(i, y) == Data::EMPTY; --i)
    ++ctr;
  for (size_t i = x+1; getCase(i, y) == Data::EMPTY; ++i)
    ++ctr;

  return ctr;
}

bool Map::player_can_pop(const size_t x, const size_t y) const
{
  Data::e_case c[4];

  if (getCase(x, y) != Data::EMPTY)
    return false;
  c[Data::UP] = getCase(x, y-1);
  c[Data::RIGHT] = getCase(x+1, y);
  c[Data::DOWN] = getCase(x, y+1);
  c[Data::LEFT] = getCase(x-1, y);
  if ((c[Data::UP] == Data::EMPTY || c[Data::DOWN] == Data::EMPTY) && (c[Data::RIGHT] == Data::EMPTY || c[Data::LEFT] == Data::EMPTY))
    return true;
  if (get_free_case_horizontal(x, y) >= 4 || get_free_case_vertical(x, y) >= 4)
    return true;
  return false;
}

float get_distance(const size_t x1, const size_t y1, const size_t x2, const size_t y2)
{
  size_t A = x1 - x2;
  size_t B = y1 - y2;

  A *= A;
  B *= B;
  return (sqrtf(A + B));
}

//positionne le joueur le plus loin possible des autres joueurs
void  Map::put_player_far(std::list<ICharacter *> &players_put, ICharacter *c) const
{
  size_t x, y, tmplen;//position finale
  tmplen = 0;
  x = y = 0;

  for (size_t ii = 0; ii < height; ++ii){
    for (size_t jj = 0; jj < width; ++jj){
      if (player_can_pop(jj, ii)){
	size_t l;
	size_t tmp = 1000000;
	for(std::list<ICharacter *>::iterator i = players_put.begin(); i != players_put.end(); ++i)
	  {
	    l = get_distance(jj, ii, (*i)->getX(), (*i)->getY());
	    if (l < tmp)
	      tmp = l;
	  }
	if (tmplen < tmp)
	  {
	    x = jj;
	    y = ii;
	    tmplen = tmp;
	  }
      }
    }
  }
  c->setPos(x, y);
  (dynamic_cast<Player *>(c))->initPos((float)x - (float)width / 2.0f,
				       (float)y - (float)height / 2.0f);
  if (x != 0 && y != 0)
    players_put.push_back(c);
}

bool Map::put_players(std::list<ICharacter *> &players) const
{
  if (players.size() == 0)
    return false;

  std::list<ICharacter *>::iterator i = players.begin();
  std::list<ICharacter *> players_put;

  for (size_t y = 0; y < height; ++y){
    for (size_t x = 0; x < width; ++x){
       if (player_can_pop(x, y))
       	{
       	  (*i)->setPos(x, y);
       	  (dynamic_cast<Player *>(*i))->initPos((float)x - (float)width / 2.0f,
       						(float)y - (float)height / 2.0f);
       	  players_put.push_back(*i);
       	  ++i;
       	  if (i == players.end())
       	    return true;
       	  y = height;
      	  x = width;
       	}
    }
  }

  if (players_put.size() == 0)
    return false;
  for(std::list<ICharacter *>::iterator i = ++(players.begin()); i != players.end(); ++i)
    put_player_far(players_put, *i);
  return players_put.size() != players.size() ? false : true;
}

size_t		Map::getX() const
{
  return (width);
}

size_t		Map::getY() const
{
  return (height);
}
