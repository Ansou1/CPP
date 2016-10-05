#ifndef KITCHEN
#define KITCHEN 1

#include <pthread.h>
#include <map>
#include <string>
#include <list>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "Exception.hpp"
#include "Thread.h"
#include "Plazza.hh"
#include "mutex.h"
#include "Pool_thread.h"
#include "Parser.h"
#include "message.h"

enum ingredient_type{PASTA, TOMATO, SWISS_CHEESE, HAM, MUSHROOM, STEAK, GOAT_CHEESE};

typedef struct 		pizza_recipe
{
	unsigned int  	baked;
	unsigned char 	pasta;
	unsigned char 	tomato;
	unsigned char 	swiss_cheese;
	unsigned char 	ham;
	unsigned char 	mushroom;
	unsigned char 	steak;
	unsigned char 	goat_cheese;
	unsigned char 	eggplant;
}					pizza_recipe;

class Kitchen
{
 private:
  unsigned short 	nb_cooks;
  unsigned int 		multiplier;
  unsigned int 		repop;
  Fridge 		*fridge;
  std::map<TypePizza, pizza_recipe *> 	list;
  std::list<Thread *>			cookers;
  std::map<TypePizza, void (Kitchen::*)(const TaillePizza)> 	recipe;
  bool					alive;
  Message				*message;
  Kitchen(const Kitchen &);
  Kitchen &operator=(const Kitchen &);

 public:
  Kitchen(const unsigned short nb_cooks, const unsigned int time_powerfull_ms, const unsigned int time_recup_ingredient, const int id);
  void	pick_ingredient(const unsigned int pasta, const unsigned int tomato, const unsigned int swiss_cheese, const unsigned int ham, const unsigned int mushroom, const unsigned int steak, const unsigned int goat_cheese, const unsigned int eggplant);
  void 	cook_pizza(Task *task);
  void 	cook_regina(const TaillePizza s);
  void 	cook_margarita(const TaillePizza s);
  void 	cook_americaine(const TaillePizza s);
  void 	cook_fantasia(const TaillePizza s);
  bool 	is_alive(void) const;
  bool	tasks_empty() const;
  void 	action_finished(void);
  void 	start_cooking();
  Pool_thread				*tasks;
  Mutex					*mutex;
  unsigned int 				actions;
  int 					id;
  Parser 				p;
  Package 				pack;
  void 	close_kitchen();
};

#endif
