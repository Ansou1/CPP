#ifndef GAME_MANAGER_HH
#define GAME_MANAGER_HH

#include <string>
#include <list>
#include <map>
#include <Clock.hh>
#include <AShader.hh>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
#include "Backup.hh"
#include "AI/AI.hh"
#include "Bomb.hh"
#include "Map.hh"
#include "Sound.hh"

class				GameManager
{
private:
  std::list<ICharacter *>	_characters;
  std::list<IItem *>		_items;
  std::string			_backup_path;
  std::map<int, int>		_score;

  Map				*_map;

  gdl::Input			*_input;
  gdl::Clock			*_clock;
  gdl::AShader			*_shader;

  size_t			_nbPlayer;
  size_t			_nbAI;
  size_t			_id;

  std::vector<int>		_imgMap;

  std::map<int, Data::e_action> *_p1;
  std::map<int, Data::e_action> *_p2;

  std::string			_msg;

  void				move(ICharacter *charac, void (ICharacter::*fct)());
  bool				isAlive(ICharacter *player);
  void				reloadBomb(size_t id);
  void				updateImgMap();

  Sound				*_sound;


  typedef void (GameManager::*fct)(Player *);
  std::map<Data::e_action, fct>	_mySwitch;

  void				switchUp(Player *);
  void				switchDown(Player *);
  void				switchLeft(Player *);
  void				switchRight(Player *);

public:
  GameManager(gdl::Input *input, gdl::Clock *clock, gdl::AShader *shader, std::map<int, Data::e_action> *p1, std::map<int, Data::e_action> *p2);
  ~GameManager();

  void				updateCharacters();
  void				updateItems();
  void        score() const;

  bool				gameOver() const;
  int				whoIsWin() const;

  void				initIntro();
  void				initMap(size_t x, size_t y, int type = 0);
  void				initMap(const std::string &name);
  void				initPlayers(size_t nbPlayer);
  void				initAI(size_t nbAI);

  int				backup(const std::string &);
  int				loadBackup(const std::string&);
  void      load(const std::string & name);

  const std::list<ICharacter *>	&getCharacters() const;
  const std::list<IItem *>	&getItems() const;
  Map				*getMap() const;

  const std::string		&getMessage() const;
  const std::map<int, int>	&getScore() const;

  void				reset(bool del = true);

  struct s_bonus		getSaveBonus(const ICharacter *p);
  void				getPlayerData(std::list<struct s_player *> &listplayer);
  void				getBombeData(std::list<struct s_bombe *> &listbombe);
  void				loadPlayerData(std::list<struct s_player *> &listplayer,
  					       const void *data, const size_t addr, const size_t lenght);
  void				loadBombeData(std::list<struct s_bombe *> &listbombe, const void *data,
					      const size_t addr, const size_t lenght);
  void				*map_memory(const std::string &name, const size_t size);
  Sound				*getSound() const;
};


#endif
