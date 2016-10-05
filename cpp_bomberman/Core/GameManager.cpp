#include <sys/mman.h>
#include <fcntl.h>
#include "Exception.hpp"
#include "GameManager.hh"

GameManager::GameManager(gdl::Input *input, gdl::Clock *clock, gdl::AShader *shader, std::map<int, Data::e_action> *p1, std::map<int, Data::e_action> *p2)
{
  _id = 0;
  _input = input;
  _clock = clock;
  _shader = shader;
  _backup_path = "./backup";

  _sound = new Sound();
  _sound->playMusic(Sound::GAME);
  _sound->pauseChan(Sound::GAME);
  _sound->playMusic(Sound::INTRO);
  _sound->pauseChan(Sound::INTRO);

  _p1 = p1;
  _p2 = p2;

  _mySwitch[Data::GO_UP] = &GameManager::switchUp;
  _mySwitch[Data::GO_DOWN] = &GameManager::switchDown;
  _mySwitch[Data::GO_LEFT] = &GameManager::switchLeft;
  _mySwitch[Data::GO_RIGHT] = &GameManager::switchRight;
}

GameManager::~GameManager()
{
  delete (_sound);
  reset();
}

Sound	*GameManager::getSound() const
{
  return (_sound);
}

void GameManager::load(const std::string & name)
{
  loadBackup(name);
  for (size_t i = 0; i < _map->getX() * _map->getY(); i++)
    _imgMap.push_back(0);
  for (std::list<ICharacter *>::iterator it = _characters.begin(); it != _characters.end(); ++it)
  {
    if ((*it)->getType() == Data::AI)
      (dynamic_cast<AI *>(*it))->setMapInfo(_map->getX(), _map->getY());
  }
}

void			GameManager::initIntro()
{
  _nbPlayer = 0;
  initAI(4);

  _map = new Map(_characters);

  for (size_t i = 0; i < _map->getX() * _map->getY(); i++)
    _imgMap.push_back(0);
  for (std::list<ICharacter *>::iterator it = _characters.begin(); it != _characters.end(); ++it)
    {
      if ((*it)->getType() == Data::AI)
	(dynamic_cast<AI *>(*it))->setMapInfo(_map->getX(), _map->getY());
    }
}

void			GameManager::initMap(size_t x, size_t y, int type)
{
  _map = new Map(x, y, _characters, type);
  for (size_t i = 0; i < _map->getX() * _map->getY(); i++)
    _imgMap.push_back(0);
  for (std::list<ICharacter *>::iterator it = _characters.begin(); it != _characters.end(); ++it)
  {
    if ((*it)->getType() == Data::AI)
      (dynamic_cast<AI *>(*it))->setMapInfo(_map->getX(), _map->getY());
  }
}

void			GameManager::initMap(const std::string &name)
{
  _map = new Map(name, _characters);
  for (size_t i = 0; i < _map->getX() * _map->getY(); i++)
    _imgMap.push_back(0);
  for (std::list<ICharacter *>::iterator it = _characters.begin(); it != _characters.end(); ++it)
    if ((*it)->getType() == Data::AI)
      (dynamic_cast<AI *>(*it))->setMapInfo(_map->getX(), _map->getY());
}

void			GameManager::initPlayers(size_t nbPlayer)
{
  _nbPlayer = nbPlayer;
  _score[_id] = 0;
  _characters.push_back(new Player(_id++, _p1, glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)));
  if (nbPlayer > 1)
    {
      _score[_id] = 0;
      _characters.push_back(new Player(_id++, _p2, glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)));
    }
}

void			GameManager::initAI(size_t nbAI)
{
  _nbAI = nbAI;
  for (size_t i = 0; i < nbAI; i++)
    {
      _score[_id] = 0;
      _characters.push_back(new AI(_id++, &_imgMap, 0, 0, "Core/AI/AI.lua"));
    }
}


bool			GameManager::gameOver() const
{
  return (!((_nbPlayer == 1 && _nbAI == 0) || _nbPlayer == 0));
}

void    GameManager::score() const
{
  std::fstream in;
  std::fstream out;
  std::map<int, int> s;
  std::string tmp;

  s = _score;
  in.open("score", std::fstream::in);
  if (!in.is_open())
    throw my_exception("Score file not found");
  while (getline(in, tmp))
  {
    int id, sc, f;
    if ((size_t)(f = tmp.find(":", 0)) == std::string::npos)
    {
      in.close();
      return ;
    }
    else
    {
      std::istringstream bufid(tmp.substr(0, tmp.size() - f - 1));
      std::istringstream bufs(tmp.substr(f + 1, tmp.size()));
      bufid >> id;
      bufs >> sc;
      s[id] = sc;
    }
  }
  for (std::map<int, int>::iterator i = s.begin(); i != s.end(); ++i)
  {
    for (std::map<int, int>::const_iterator j = _score.begin(); j != _score.end(); ++j)
    {
      if ((*i).first == (*j).first && (*i).second < (*j).second)
        (*i).second = (*j).second;
    }
  }
  in.close();
  out.open("score", std::fstream::out | std::fstream::trunc);
  if (!out.is_open())
    throw my_exception("Score file not found");
  for (std::map<int, int>::iterator i = s.begin(); i != s.end(); ++i)
  {
    out << (*i).first << ":" << (*i).second << std::endl;
  }
  out.close();
}

int			GameManager::whoIsWin() const
{
  _sound->pauseChan(Sound::GAME);
  if (_nbPlayer == 0)
    {
      if (_nbAI == 0)
	{
	  _sound->playMusic(Sound::DEFEAT);
	  return -2;
	}
      _sound->playMusic(Sound::DEFEAT);
      return -1;
    }
   score();
   _sound->playMusic(Sound::VICTORY);
  return (int)(*_characters.begin())->getId();
}

void			GameManager::updateCharacters()
{
  Player		*tmp;
  Data::e_action	action;

  updateImgMap();
  _msg = "";
  for (std::list<ICharacter *>::iterator it = _characters.begin(); it != _characters.end(); ++it)
    {
      tmp = dynamic_cast<Player *>(*it);
      if (isAlive(*it))
	{
	  action = (*it)->update(_input);
	  if (!tmp->isAnimated() && (action == Data::GO_UP ||
				     action == Data::GO_DOWN ||
				     action == Data::GO_LEFT ||
				     action == Data::GO_RIGHT))
	    (this->*_mySwitch[action])(tmp);
	  if (action == Data::DROP_BOMB && tmp->canDropBomb() &&
	      _map->getCase(tmp->getX(), tmp->getY()) != Data::BOMB)
	    {
	      tmp->dropBomb();
	      _map->setCase(tmp->getX(), tmp->getY(), Data::BOMB);
	      _items.push_back(new Bomb(tmp->getId(), tmp->getRange(), tmp->getX(), tmp->getY(), _score));
	      dynamic_cast<Bomb *>(_items.back())
		->initPos((float)tmp->getX() - (float)_map->getWidth() / 2.0f,
			  (float)tmp->getY() - (float)_map->getLength() / 2.0f);
	    }
	  tmp->draw(*_shader, *_clock);
	}
      else
	{
	  if (_characters.size() > 2)
	    _sound->playMusic(Sound::KILL);
	  _score[(*it)->getId()] -= 1000;
	  it = _characters.erase(it);
	  it--;
	}
    }
}

void			GameManager::switchLeft(Player *tmp)
{
  tmp->setDir(Data::LEFT);
  if (_map->isAccessible(tmp->getX() - 1, tmp->getY()))
    move(tmp, &ICharacter::goLeft);
}

void			GameManager::switchRight(Player *tmp)
{
  tmp->setDir(Data::RIGHT);
  if (_map->isAccessible(tmp->getX() + 1, tmp->getY()))
    move(tmp, &ICharacter::goRight);
}

void			GameManager::switchUp(Player *tmp)
{
  tmp->setDir(Data::DOWN);
  if (_map->isAccessible(tmp->getX(), tmp->getY() - 1))
    move(tmp, &ICharacter::goUp);
}

void			GameManager::switchDown(Player *tmp)
{
  tmp->setDir(Data::UP);
  if (_map->isAccessible(tmp->getX(), tmp->getY() + 1))
    move(tmp, &ICharacter::goDown);
}

void			GameManager::updateItems()
{
  Bomb			*tmp;
  Data::e_bombState	state;

  for (std::list<IItem *>::iterator it = _items.begin(); it != _items.end(); ++it)
    {
      tmp = dynamic_cast<Bomb *>(*it);
      state = tmp->update(_map);
      if (state == Data::BOMB_END)
	it = _items.erase(it);
      else if (state == Data::BOMB_EXPLODE)
	{
	  _sound->playMusic(Sound::BOMB);
	  reloadBomb(tmp->getId());
	}
      else
	tmp->draw(*_shader, *_clock);
    }
}

void			GameManager::reset(bool del)
{
  _id = 0;
  if (del)
    delete (_map);
  while (!_characters.empty())
    {
      if (del)
	delete (_characters.back());
      _characters.pop_back();
    }
  while (!_items.empty())
    {
      if (del)
	delete (_items.back());
      _items.pop_back();
    }
  _score.erase(_score.begin(), _score.end());

}

const std::list<ICharacter *>   &GameManager::getCharacters() const
{
  return (_characters);
}

const std::list<IItem *>        &GameManager::getItems() const
{
  return (_items);
}

Map				*GameManager::getMap() const
{
  return (_map);
}



void			GameManager::move(ICharacter *charac, void (ICharacter::*fct)())
{
  (charac->*fct)();
  dynamic_cast<Player *>(charac)->setAnim("RUN");
  if (_map->getCase(charac->getX(), charac->getY()) == Data::BONUS)
    {
      _sound->playMusic(Sound::BONUS);
      std::stringstream ss;
      ss << charac->getId();
      _msg = std::string("Player ") + ss.str() + " ";
      charac->getRandomBonus(_msg);
      _map->setCase(charac->getX(), charac->getY(), Data::EMPTY);
      _score[charac->getId()] += 100;
    }
}

bool			GameManager::isAlive(ICharacter *player)

{
  if (_map->getCase(player->getX(), player->getY()) == Data::BOOM ||
      _map->getCase(player->getX(), player->getY()) == Data::BOOM2)
    {
      if (player->getType() == Data::HUMAN)
	{
	  _nbPlayer--;
	}
      else if (player->getType() == Data::AI)
	_nbAI--;
      return false;
    }
  return true;
}

const std::string	&GameManager::getMessage() const
{
  return (_msg);
}

const std::map<int, int> &GameManager::getScore() const
{
  return (_score);
}

void			GameManager::reloadBomb(size_t id)
{
  for (std::list<ICharacter *>::iterator it = _characters.begin(); it != _characters.end(); ++it)
    if ((*it)->getId() == id)
      {
	(dynamic_cast<Player *>(*it))->reload();
	break;
      }
}

struct s_bonus		GameManager::getSaveBonus(__attribute__((unused))const ICharacter *p)
{
  struct s_bonus *ret = new struct s_bonus;
  return *ret;
}

void			GameManager::getPlayerData(std::list<struct s_player *> &listplayer)
{
  for (std::list<ICharacter *>::iterator i = this->_characters.begin(); i != this->_characters.end(); ++i){
    struct s_player *tmp  = new struct s_player;
    tmp->bonus = getSaveBonus(*i);
    tmp->x = (*i)->getX();
    tmp->y = (*i)->getY();
    tmp->id = (*i)->getId();
    tmp->type = (*i)->getType();
    listplayer.push_back(tmp);
  }
}

void			GameManager::getBombeData(std::list<struct s_bombe *> &listbombe)
{
  for (std::list<IItem *>::iterator i = this->_items.begin(); i != this->_items.end(); ++i){
    struct s_bombe *tmp  = new struct s_bombe;
    if ((*i)->getType() == Data::BOMBE)
      {
	Bomb *b = dynamic_cast<Bomb *>(*i);
	tmp->idPlayer = b->getIdPlayer();
	tmp->range = b->getRange();
	tmp->x = b->getX();
	tmp->y = b->getY();
	tmp->done = b->getDone();
	listbombe.push_back(tmp);
      }
  }
}

int			GameManager::backup(const std::string &backup_name)
{
  DIR		*dir;

  dir = opendir(this->_backup_path.c_str());
  if (dir == NULL)
    if (mkdir(this->_backup_path.c_str(), 0755) == -1)
      return -1;
  closedir(dir);

  std::ofstream file;

  file.open((this->_backup_path + "/" + backup_name + ".game").c_str(), std::ofstream::trunc | std::ofstream::binary);
  if (!file.is_open())
    return -1;
  this->_map->save((this->_backup_path +"/"+ backup_name + ".map").c_str());
  std::list<struct s_bombe *> listbombe;
  std::list<struct s_player *> listplayer;
  getBombeData(listbombe);
  getPlayerData(listplayer);
  struct s_backup_header header;
  header.addr_player = sizeof(struct s_backup_header);
  header.addr_bombe = listplayer.size() * sizeof(struct s_player) + header.addr_player;
  file.write(((char *)(&header)), sizeof(struct s_backup_header));
  for (std::list<struct s_player *>::iterator i = listplayer.begin(); i != listplayer.end(); ++i)
    file.write((char *)(*i), sizeof(struct s_player));
  for (std::list<struct s_bombe *>::iterator i = listbombe.begin(); i != listbombe.end(); ++i)
  file.write((char *)(*i), sizeof(struct s_bombe));
  file.close();
  return (0);
}

void		*GameManager::map_memory(const std::string &name, const size_t size)
{
  std::ifstream file(name.c_str(), std::ios::in);
  char          *data = new char[size];
  char          c;

  if (!data)
    return (NULL);
  for (size_t i = 0; i < size; ++i)
  {
    file.get(c);
    data[i] = c;
  }
  return (data);
}

int		  GameManager::loadBackup(const std::string & backup_name)
{
  const std::string mapfile = (this->_backup_path + "/" + backup_name + ".map");
  const std::string datafile = (this->_backup_path + "/" + backup_name + ".game");
  void	*data;

  //on charge la map
  this->_map = new Map(this->_backup_path + "/" + backup_name + ".map");

  struct s_backup_header *header;
  struct stat buf;
  std::list<ICharacter *> players;
  std::list<IItem *> items;
  std::list<struct s_bombe *> listbombe;
  std::list<struct s_player *> listplayer;

  //on recupere les info sur le fichier
  if (stat(datafile.c_str(), &buf) == -1)
  {
    throw exception_load("Cannot stat the file");
    return -1;
  }
  if ((data = map_memory(datafile, buf.st_size)) == NULL)
    throw exception_load("Cannot map the data in memory");
  header = (struct s_backup_header *)data;

  if (buf.st_size < (int)sizeof(struct s_backup_header) || buf.st_size < (int)header->addr_bombe)
    throw my_exception("File format not recognized");

  //on charge les données sur les joueurs
  loadPlayerData(listplayer, data, header->addr_player, (size_t)header->addr_bombe - (size_t)header->addr_player);
  loadBombeData(listbombe, data, header->addr_bombe, buf.st_size - header->addr_bombe);
  for (size_t i = 0; i < _map->getX() * _map->getY(); i++)
    _imgMap.push_back(0);
  for (std::list<ICharacter *>::iterator it = _characters.begin(); it != _characters.end(); ++it)
  {
    if ((*it)->getType() == Data::AI)
	   (dynamic_cast<AI *>(*it))->setMapInfo(_map->getX(), _map->getY());
  }
  return (0);
}

void		GameManager::loadPlayerData(std::list<struct s_player *> &listplayer, const void *data, const size_t addr, const size_t lenght)
{
  int unsigned i = 0;
  while (i < lenght)
    {
      listplayer.push_back((struct s_player *)((char *)data + addr + i));
      i += sizeof(struct s_player);
    }
    ICharacter *tmp;
    this->_nbAI = 0;
    this->_nbPlayer = 0;
    for (std::list<struct s_player *>::const_iterator j = listplayer.begin(); j != listplayer.end(); ++j){
      if ((*j)->type == 0)
      {
        if ((*j)->id == 0)
          tmp = new Player((*j)->id, _p1, glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
        else
          tmp = new Player((*j)->id, _p2, glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
        if ((*j)->x >= this->_map->getX() || (*j)->y >= this->_map->getY())
          throw my_exception("Player is outside of the map");
        tmp->setPos((*j)->x, (*j)->y);
        tmp->setType(static_cast<Data::e_type>((*j)->type));
        (dynamic_cast<Player *>(tmp))->initPos((float)((*j)->x) - (float)(this->_map->getX()) / 2.0f,
             (float)((*j)->y) - (float)(this->_map->getY()) / 2.0f);
        this->_nbPlayer += 1;
        this->_score[(*j)->id] = 0;
      }
      else
      {
        tmp = new AI((*j)->id, &_imgMap, 0, 0, "Core/AI/AI.lua");
        if ((*j)->x >= this->_map->getX() || (*j)->y >= this->_map->getY())
          throw my_exception("Player is outside of the map");
        tmp->setPos((*j)->x, (*j)->y);
        tmp->setType(static_cast<Data::e_type>((*j)->type));
         (dynamic_cast<AI *>(tmp))->initPos((float)((*j)->x) - (float)(this->_map->getX()) / 2.0f,
             (float)((*j)->y) - (float)(this->_map->getY()) / 2.0f);
        this->_nbAI += 1;
        this->_score[(*j)->id] = 0;
      }
      this->_characters.push_back(tmp);
    }
}

void            GameManager::loadBombeData(std::list<struct s_bombe *> &listbombe, const void *data, const size_t addr, const size_t lenght)
{
  unsigned int i = 0;

  while (i < lenght)
    {
      listbombe.push_back((struct s_bombe *)((char *)data + addr + i));
      i += sizeof(struct s_bombe);
    }
  for (std::list<struct s_bombe *>::const_iterator i = listbombe.begin(); i != listbombe.end(); ++i){
    Bomb * tmp = new Bomb((*i)->idPlayer, (*i)->range, (*i)->x, (*i)->y, _score);
    tmp->setDone((*i)->done);
    this->_items.push_back(tmp);
  }
}

void			GameManager::updateImgMap()
{
  Data::e_case		currentCase;

  for (size_t i = 0; i < _map->getX() * _map->getY(); i++)
    {
      currentCase = _map->getCase(i % _map->getY(), i / _map->getY());
      if (currentCase == Data::BOOM2)
	_imgMap[i] = (int)Data::BOOM;
      else
	_imgMap[i] = (int)currentCase;
    }
  for (std::list<ICharacter *>::iterator it = _characters.begin(); it != _characters.end(); ++it)
    if (_imgMap[(*it)->getX() + (*it)->getY() * _map->getX()] != 60)
      _imgMap[(*it)->getX() + (*it)->getY() * _map->getX()] = 70;
}
