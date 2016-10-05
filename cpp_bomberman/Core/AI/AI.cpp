#include "AI.hh"

AI::AI(size_t id, std::vector<int> *imgMap, size_t x, size_t y,
       const std::string &script) : Player(id, NULL, glm::vec4(1.0f, 0.0f, 0.0f, 1.0f))
{
  ls = luaL_newstate();
  luaL_openlibs(ls);

  _eq[0] = Data::GO_UP;
  _eq[1] = Data::GO_RIGHT;
  _eq[2] = Data::GO_DOWN;
  _eq[3] = Data::GO_LEFT;
  _eq[4] = Data::DROP_BOMB;
  _eq[5] = Data::WAIT;

  _type = Data::AI;

  _imageMap = imgMap;
  _imgX = x;
  _imgY = y;

  _script = script;
  _dir = Data::GO_LEFT;
}

AI::~AI()
{
  lua_close(ls);
}

void			AI::setMapInfo(size_t x, size_t y)
{
  _imgX = x;
  _imgY = y;
}

Data::e_action		AI::update(gdl::Input *input)
{
  (void)(input);
  if (!isAnimated())
    {
      loadMap();
      loadExtra();
      return (think());
    }
  return (Data::WAIT);
}

void			AI::loadMap()
{
  lua_createtable(ls, _imageMap->size(), 0);
  for (size_t i = 0; i < _imageMap->size(); i++)
    {
      lua_pushnumber(ls, i + 1);
      lua_pushnumber(ls, (*_imageMap)[i]);
      lua_settable(ls, -3);
    }
  lua_setglobal(ls, "map");
}

void			AI::loadExtra()
{
  lua_pushnumber(ls, _x + 1);
  lua_setglobal(ls, "posX");

  lua_pushnumber(ls, _y + 1);
  lua_setglobal(ls, "posY");

  lua_pushnumber(ls, _imgX);
  lua_setglobal(ls, "width");

  lua_pushnumber(ls, _imgY);
  lua_setglobal(ls, "length");

  lua_pushnumber(ls, (int)_dir);
  lua_setglobal(ls, "dir");

  lua_pushnumber(ls, _range);
  lua_setglobal(ls, "range");
}

Data::e_action		AI::think()
{
  _dir = Data::WAIT;
  if (luaL_loadfile(ls, _script.c_str()) == LUA_OK)
    {
      lua_pcall(ls, 0, 1, 0);
    }
  else
    throw my_exception("AI.lua introuvable ou corrompu. Impossible jouer avec les AI");

  _dir = _eq[lua_tointeger(ls, lua_gettop(ls))];
  lua_pop(ls, 1);
  return (_dir);
}

void        AI::setType(const Data::e_type t){
  this->_type = t;
}
