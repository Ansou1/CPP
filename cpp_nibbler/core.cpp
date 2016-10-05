//
// core.cpp for core in /home/falcon_j/tp/nibbler
//
// Made by jeremy falconnier
// Login   <falcon_j@epitech.net>
//
// Started on  Wed Mar 19 15:26:23 2014 jeremy falconnier
// Last update Sun Apr  6 16:36:02 2014 daguen_s
//

#include "core.hh"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

Core::Core(const std::string &x, const std::string &y)
{
  std::stringstream	xy;
  int			i = -1;
  int			j = -1;
  std::string		str;
  coord			tail;

  xy << x;
  xy >> this->map_size.x;
  xy.clear();
  xy << y;
  xy >> this->map_size.y;
  xy.clear();

  if (this->map_size.x < 20 || this->map_size.y < 20)
    throw exception_param("Invalide map size");
  while (++i < this->map_size.y)
    {
      j = -1;
      while (++j < this->map_size.x)
	{
	  if (i == 0 || i == this->map_size.y - 1 || j == 0 || j == this->map_size.x - 1)
	    xy << "w";
	  else if (i == this->map_size.y / 2 && j == ((this->map_size.x - 2) / 2))
	    {
	      tail.x = j;
	      tail.y = i;
	      xy << "tssh";
	      j = j + 3;
	    }
	  else
	    xy << "v";
	}
      xy >> str;
      xy.clear();
      this->map.push_back(str);
    }
  this->direction = RIGHT;
  this->grow_up = 0;
  this->living = 1;
  this->score = 0;
  i = -1;
  coord *add;
  while (++i < 4)
    {
      add = new coord;
      add->x = tail.x + i;
      add->y = tail.y;
      this->body.push_front(add);
    }
  this->start = clock();
  this->action[KEY_S] = &Core::down;
  this->action[KEY_Z] = &Core::up;
  this->action[KEY_Q] = &Core::left;
  this->action[KEY_D] = &Core::right;
  this->action[NONE] = &Core::none;
  this->action[LEFT] = &Core::left90;
  this->action[RIGHT] = &Core::right90;
  this->score = 0;
  this->old_time = 0;
}

Core::Core(const Core &old)
{
  this->map = old.map;
}

Core &Core::operator=(const Core &old)
{
  this->map = old.map;
  return (*this);
}

Core::~Core()
{
  std::cout << "Your score: " << this->score << std::endl;
  for (std::list<coord *>::iterator it = this->body.begin(); it != this->body.end(); ++it)
    {
      delete *it;
    }
}

void	Core::game(IDisplayModule *obj)
{
  e_key key;

  this->speed = 100000;
  obj->init(this->map_size);
  while (this->living)
    {
      usleep(this->speed);
      if ((key = obj->getKey()) == ESCAPE)
        return ;
      (this->*action[key])();
      put_fruit();
      obj->aff(this->map, this->score, (1.0 / (float)this->speed * 1000000.0));
    }
}

//Moving funcitons

void Core::move_to(coord &go_to, const e_key &key)
{
  char block;
  coord *add;

  this->map[go_to.y][go_to.x] = BODY;
  go_to.y += key == UP ? -1 : 0;
  go_to.y += key == DOWN ? 1 : 0;
  go_to.x += key == RIGHT ? 1 : 0;
  go_to.x += key == LEFT ? -1 : 0;
  this->direction = key;
  block = this->map[go_to.y][go_to.x];
  if (block == WALL || block == BODY)
    {
      this->living = false;
      return ;
    }
  this->speed *= (block == 'h') ? 1.1 : 1;
  this->speed /= (block == 't') ? 1.25 : 1;
  this->score += (block == 'f') ? 10 : 0;
  this->score += (block == 't') ? 100 : 0;
  this->score += (block == 'h') ? 100 : 0;
  this->grow_up += (block == 'f') ? 1 : 0;
  this->grow_up += (block == 'h') ? 10 : 0;
  this->speed = this->speed > 500000 ? 500000 : this->speed;
  if (go_to.x < this->map_size.x && go_to.y < this->map_size.y)
    this->map[go_to.y][go_to.x] = HEAD;
  add = new coord;
  add->x = go_to.x;
  add->y = go_to.y;
  this->body.push_front(add);
}

void Core::remove_tail()
{
  //Si le serpent grossi on ne supprime pas la queue
  if (this->grow_up > 0)
    {
      --(this->grow_up);
      return ;
    }

  std::list<coord *>::iterator it = this->body.end();

  --it;
  --it;
  this->map[(*it)->y][(*it)->x] = 't';
  ++it;
  this->map[(*it)->y][(*it)->x] = 'v';
  delete *it;
  this->body.pop_back();
}

void Core::move_snake(const e_key & key)
{
  coord *head = *(this->body.begin());
  coord go_to;

  go_to.x = head->x;
  go_to.y = head->y;
  if ((key == UP || key == DOWN) && (this->direction == UP || this->direction == DOWN))
    return ;
  else if ((key == LEFT || key == RIGHT) && (this->direction == LEFT || this->direction == RIGHT))
    return ;
  if (key != NONE)
    move_to(go_to, key);
  else
    move_to(go_to, this->direction);
  remove_tail();
}

int  Core::put_at_rand(char type)
{
  for (int y = rand()%this->map_size.y; y < this->map_size.y; ++y)
    {
      for (int x = rand()%this->map_size.x; x < this->map_size.x; ++x)
	{
	  if (this->map[y][x] == FREE)
	    {
	      this->map[y][x] = type;
	      return (0);
	    }
	}
    }
  return (0);
}

void  Core::put_fruit()
{
  bool fruit = false;
  clock_t finish;

  for (int y = 0;y < this->map_size.y;++y)
    {
      for (int x = 0; x < this->map_size.x; ++x)
	{
	  if (this->map[y][x] == FRUIT)
	    fruit = true;
	}
    }
  finish = clock();
  srand(start-finish);
  if (!fruit || rand() % 100 == 0)
    put_at_rand(FRUIT);
  rand() % 100 == 0 ? put_at_rand('h')
    : rand() % 100 == 0 ? put_at_rand('w')
    : rand() % 100 == 0 ? put_at_rand('t')
    : 0;
}

//keys functions
void  Core::down()
{
  move_snake(DOWN);
}

void Core::up()
{
  move_snake(UP);
}

void Core::left()
{
  move_snake(LEFT);
}

void Core::right()
{
  move_snake(RIGHT);
}

void Core::none()
{
  move_snake(NONE);
}

void Core::left90()
{
  if (this->direction == LEFT)
    move_snake(DOWN);
  else if(this->direction == DOWN)
    move_snake(RIGHT);
  else
    this->direction == RIGHT ? move_snake(UP) : move_snake(LEFT);
}

void Core::right90()
{
  if (this->direction == LEFT)
    move_snake(UP);
  else if(this->direction == DOWN)
    move_snake(LEFT);
  else
    this->direction == RIGHT ? move_snake(DOWN) : move_snake(RIGHT);
}
