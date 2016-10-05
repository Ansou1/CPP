#ifndef AI_HH
#define AI_HH

#include "../Player.hh"
#include <vector>

extern "C"
{
  #include "lua.h"
  #include "lualib.h"
  #include "lauxlib.h"
}

class				AI : public Player
{
private:
  std::string			_script;

  std::vector<int>		*_imageMap;

  size_t			_imgX;
  size_t			_imgY;
  std::map<int, Data::e_action>	_eq;

  lua_State			*ls;

  Data::e_action		_dir;

  void				loadMap();
  void				loadExtra();
  Data::e_action		think();

public:
  AI(size_t id, std::vector<int> *imgMap, size_t x, size_t y, const std::string &script);
  virtual ~AI();

  virtual Data::e_action	update(gdl::Input *input);
  void				setMapInfo(size_t x, size_t y);
  virtual void        setType(const Data::e_type t);
};

#endif
