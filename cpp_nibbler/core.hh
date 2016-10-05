//
// core.hh for  in /home/daguen_s/rendu/cpp_nibbler
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Thu Apr  3 20:02:52 2014 daguen_s
// Last update Fri Apr  4 17:40:11 2014 corrad_f
//

#ifndef _CORE_HH_
# define _CORE_HH_

#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <vector>
#include <iterator>
#include <time.h>
#include <map>
#include "displaymodule.h"

class Core
{
private:
  std::vector<std::string>              map;
  std::list<coord*>                     body;
  coord                                 map_size;   //la taille de la catre
  e_key                                 direction;  //la direction du serpent
  unsigned char                         grow_up;    //contient le nombre de case qui restent à ajouter au serpent
  unsigned long                         score;      //le score
  unsigned int                          speed;
  unsigned int                          old_time;   //ancien temps
  bool                                  living;     //mort ou vivant
  clock_t                               start;      //processor time
  std::map<e_key, void (Core::*)(void)> action;     //les actions à effectuer

public:

  ///////////////////////////////////////////////forme colpienne //////////////////////////////

  Core(const std::string &, const std::string &);
  Core(const Core &old);
  Core &operator=(const Core &old);
  ~Core();

  ////////////////////////////////////////////// methodes de l objet core /////////////////////

  void	modif_map(const e_key &);
  void	game(IDisplayModule *obj);
  void  move_snake(const e_key & key);
  void  remove_tail();
  void  move_to(coord &go_to, const e_key &key);
  void  put_fruit();
  int  put_at_rand(char type);

  void down();
  void up();
  void left();
  void right();
  void none();
  void left90();
  void right90();
};

#endif /* _CORE_HH_ */
