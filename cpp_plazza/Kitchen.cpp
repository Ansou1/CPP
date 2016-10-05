#include "Kitchen.h"

Kitchen::Kitchen(const unsigned short nb_cooks, const unsigned int time_powerfull_ms, const unsigned int time_recup_ingredient, const int id) : nb_cooks(nb_cooks), multiplier(time_powerfull_ms), repop(time_recup_ingredient){
  pizza_recipe *tmp;
  this->fridge = new Fridge;
  this->fridge->pasta = 500;
  this->fridge->tomato = 500;
  this->fridge->swiss_cheese = 500;
  this->fridge->ham = 500;
  this->fridge->mushroom = 500;
  this->fridge->steak = 500;
  this->fridge->goat_cheese = 500;
  this->fridge->eggplant = 500;
  tmp = new pizza_recipe;
  tmp->baked = 1000;
  tmp->tomato = 1;
  tmp->swiss_cheese = 1;
  tmp->pasta = 1;
  tmp->ham = 0;
  tmp->mushroom = 0;
  tmp->steak = 0;
  tmp->goat_cheese = 0;
  tmp->eggplant = 0;
  this->list[MARGARITA] = tmp;
  tmp = new pizza_recipe;
  tmp->baked = 2000;
  tmp->eggplant = 0;
  tmp->tomato = 1;
  tmp->swiss_cheese = 1;
  tmp->pasta = 1;
  tmp->ham = 1;
  tmp->mushroom = 1;
  tmp->steak = 0;
  tmp->goat_cheese = 1;
  this->list[REGINA] = tmp;
  tmp = new pizza_recipe;
  tmp->baked = 2000;
  tmp->eggplant = 0;
  tmp->tomato = 1;
  tmp->swiss_cheese = 1;
  tmp->pasta = 1;
  tmp->ham = 0;
  tmp->mushroom = 0;
  tmp->steak = 1;
  tmp->goat_cheese = 0;
  this->list[AMERICAINE] = tmp;
  tmp = new pizza_recipe;
  tmp->eggplant = 1;
  tmp->baked = 4000;
  tmp->tomato = 1;
  tmp->swiss_cheese = 1;
  tmp->pasta = 1;
  tmp->ham = 0;
  tmp->mushroom = 0;
  tmp->steak = 0;
  tmp->goat_cheese = 0;
  this->list[FANTASIA] = tmp;
  for (unsigned short i = 0; i < nb_cooks; ++i){
    this->cookers.push_back(new Thread);
  }
  this->mutex = new Mutex;
  this->alive = true;
  this->recipe[MARGARITA] = &Kitchen::cook_margarita;
  this->recipe[AMERICAINE] = &Kitchen::cook_americaine;
  this->recipe[FANTASIA] = &Kitchen::cook_fantasia;
  this->recipe[REGINA] = &Kitchen::cook_regina;
  this->actions = 0;
  this->message = new Message(id);
  this->id = id;
  this->tasks = new Pool_thread;
}

Kitchen::Kitchen(const Kitchen &c){
  this->nb_cooks = c.nb_cooks;
  this->multiplier = c.multiplier;
  this->repop = c.repop;
  pizza_recipe *tmp;

  tmp = new pizza_recipe;
  tmp->baked = 1000;
  tmp->tomato = 1;
  tmp->swiss_cheese = 1;
  tmp->pasta = 1;
  tmp->ham = 0;
  tmp->mushroom = 0;
  tmp->steak = 0;
  tmp->goat_cheese = 0;
  tmp->eggplant = 0;
  this->list[MARGARITA] = tmp;
  tmp = new pizza_recipe;
  tmp->baked = 2000;
  tmp->eggplant = 0;
  tmp->tomato = 1;
  tmp->swiss_cheese = 1;
  tmp->pasta = 1;
  tmp->ham = 1;
  tmp->mushroom = 1;
  tmp->steak = 0;
  tmp->goat_cheese = 1;
  this->list[REGINA] = tmp;
  tmp = new pizza_recipe;
  tmp->baked = 2000;
  tmp->eggplant = 0;
  tmp->tomato = 1;
  tmp->swiss_cheese = 1;
  tmp->pasta = 1;
  tmp->ham = 0;
  tmp->mushroom = 0;
  tmp->steak = 1;
  tmp->goat_cheese = 0;
  this->list[AMERICAINE] = tmp;
  tmp = new pizza_recipe;
  tmp->eggplant = 1;
  tmp->baked = 4000;
  tmp->tomato = 1;
  tmp->swiss_cheese = 1;
  tmp->pasta = 1;
  tmp->ham = 0;
  tmp->mushroom = 0;
  tmp->steak = 0;
  tmp->goat_cheese = 0;
  this->list[FANTASIA] = tmp;
}

Kitchen &Kitchen::operator=(const Kitchen &c){
  this->nb_cooks = c.nb_cooks;
  this->multiplier = c.multiplier;
  this->repop = c.repop;
  pizza_recipe *tmp;

  tmp = new pizza_recipe;
  tmp->baked = 1000;
  tmp->tomato = 1;
  tmp->swiss_cheese = 1;
  tmp->pasta = 1;
  tmp->ham = 0;
  tmp->mushroom = 0;
  tmp->steak = 0;
  tmp->goat_cheese = 0;
  tmp->eggplant = 0;
  this->list[MARGARITA] = tmp;
  tmp = new pizza_recipe;
  tmp->baked = 2000;
  tmp->eggplant = 0;
  tmp->tomato = 1;
  tmp->swiss_cheese = 1;
  tmp->pasta = 1;
  tmp->ham = 1;
  tmp->mushroom = 1;
  tmp->steak = 0;
  tmp->goat_cheese = 1;
  this->list[REGINA] = tmp;
  tmp = new pizza_recipe;
  tmp->baked = 2000;
  tmp->eggplant = 0;
  tmp->tomato = 1;
  tmp->swiss_cheese = 1;
  tmp->pasta = 1;
  tmp->ham = 0;
  tmp->mushroom = 0;
  tmp->steak = 1;
  tmp->goat_cheese = 0;
  this->list[AMERICAINE] = tmp;
  tmp = new pizza_recipe;
  tmp->eggplant = 1;
  tmp->baked = 4000;
  tmp->tomato = 1;
  tmp->swiss_cheese = 1;
  tmp->pasta = 1;
  tmp->ham = 0;
  tmp->mushroom = 0;
  tmp->steak = 0;
  tmp->goat_cheese = 0;
  this->list[FANTASIA] = tmp;
  return *this;
}

void *cook(void *obj){
  Kitchen *k = (Kitchen *)obj;
  while (k->is_alive())
    {
      usleep(1000);
      if (!k->tasks_empty())
	{
	  int fd;
	  fd = open("log", O_WRONLY | O_CREAT | O_APPEND, 0777);
	  write(fd, "passe4\n", 7);
	  k->mutex->lock();
	  Task *tmp = k->tasks->pop();
	  k->mutex->unlock();
	  k->cook_pizza(tmp);
	}
    }
  return NULL;
}

void 	*timer(void *obj)
{
  Kitchen *k = (Kitchen *)obj;
  int 	time = 0;

  while (k->is_alive())
    {
      usleep(1000);
      ++time;
      if (k->actions != 0)
	time = 0;
      if (time == 5000)
	k->close_kitchen();
    }
  return (NULL);
}

void Kitchen::start_cooking()
{
  Task *tmp;
  int fd;

  fd = open("log", O_WRONLY | O_CREAT | O_APPEND, 0777);

  //lancement des cuisiniers
  for (std::list<Thread *>::iterator it = this->cookers.begin();it != this->cookers.end();++it){
    (*it)->start(cook, this);
  }
  for (;;)
    {
      if (this->message->receive_kitchen(this->p))
	{
	  write(fd, "-", 1);
	  write(fd, SSTR(this->p.getSize()).c_str(), 1);
	  write(fd, "-", 1);
	  write(fd, "\n", 1);
	  while (this->p.getSize() != 0)
	    {
	      std::string *str;
	      write(fd, "1-\n", 3);
	      str = this->p.get_command();
	      write(fd, "2-\n", 3);
	      tmp = this->pack.unpackCommand(*str);
	      write(fd, "3-\n", 3);
	      this->tasks->push(tmp);
	      write(fd, "4-\n", 3);
	      delete str;
	      write(fd, "passe3\n", 7);
	      close(fd);
	    }
	  close(fd);
	  this->mutex->lock();
	  ++(this->actions);
	  this->mutex->unlock();
	}
      if (!this->alive)
	{
	  return ;
	}
    }
}

void	Kitchen::pick_ingredient(const unsigned int pasta, const unsigned int tomato, const unsigned int swiss_cheese, const unsigned int ham, const unsigned int mushroom, const unsigned int steak, const unsigned int goat_cheese, const unsigned int eggplant)
{
  this->mutex->lock();
  this->fridge->pasta -= pasta;
  this->fridge->tomato -= tomato;
  this->fridge->swiss_cheese -= swiss_cheese;
  this->fridge->ham -= ham;
  this->fridge->mushroom -= mushroom;
  this->fridge->steak -= steak;
  this->fridge->goat_cheese -= goat_cheese;
  this->fridge->eggplant -= eggplant;
  this->mutex->unlock();
}

void 	Kitchen::cook_regina(const TaillePizza s)
{
  pizza_recipe *p;
  int fd;

  fd = open("log", O_WRONLY | O_CREAT| O_APPEND, 0777);
  write(fd, "regina\n", 7);
  p = this->list[REGINA];
  write(fd, "regina1\n", 8);
  pick_ingredient(p->pasta, p->tomato, p->swiss_cheese, p->ham, p->mushroom, p->steak, p->goat_cheese, p->eggplant);
  usleep(this->list[REGINA]->baked * this->multiplier);
  write(fd, "regina2\n", 8);
  this->mutex->lock();
  --(this->actions);
  this->mutex->unlock();
  write(fd, "regina3\n", 8);
  this->message->send_reception_command(REGINA, s);
  write(fd, "regina4\n", 8);
  close(fd);
}

void 	Kitchen::cook_margarita(const TaillePizza s)
{
  pizza_recipe *p;
  int fd;

  fd = open("log", O_WRONLY | O_CREAT| O_APPEND, 0777);
  write(fd, "margar\n", 7);
  close(fd);
  p = this->list[MARGARITA];
  pick_ingredient(p->pasta, p->tomato, p->swiss_cheese, p->ham, p->mushroom, p->steak, p->goat_cheese, p->eggplant);
  usleep(this->list[MARGARITA]->baked * this->multiplier);
  this->mutex->lock();
  --(this->actions);
  this->mutex->unlock();
  this->message->send_reception_command(MARGARITA, s);
}

void 	Kitchen::cook_americaine(const TaillePizza s)
{
  pizza_recipe *p;
  int fd;

  fd = open("log", O_WRONLY | O_CREAT| O_APPEND, 0777);
  write(fd, "americ\n", 7);
  close(fd);
  p = this->list[AMERICAINE];
  pick_ingredient(p->pasta, p->tomato, p->swiss_cheese, p->ham, p->mushroom, p->steak, p->goat_cheese, p->eggplant);
  usleep(this->list[AMERICAINE]->baked * this->multiplier);
  this->mutex->lock();
  --(this->actions);
  this->mutex->unlock();
  this->message->send_reception_command(AMERICAINE, s);
}

void 	Kitchen::cook_fantasia(const TaillePizza s)
{
  pizza_recipe *p;

  int fd;

  fd = open("log", O_WRONLY | O_CREAT| O_APPEND, 0777);
  write(fd, "fantas\n", 7);
  close(fd);
  p = this->list[FANTASIA];
  pick_ingredient(p->pasta, p->tomato, p->swiss_cheese, p->ham, p->mushroom, p->steak, p->goat_cheese, p->eggplant);
  usleep(this->list[FANTASIA]->baked * this->multiplier);
  this->mutex->lock();
  --(this->actions);
  this->mutex->unlock();
  this->message->send_reception_command(FANTASIA, s);
}

bool 	Kitchen::is_alive(void) const
{
	return this->alive;
}

bool	Kitchen::tasks_empty() const
{
	return this->tasks->empty();
}

void 	Kitchen::cook_pizza(Task *task)
{
  int fd;

  fd = open("log", O_WRONLY | O_CREAT | O_APPEND, 0777);
  write(fd, SSTR(task->type).c_str(), 1);
  write(fd, "\n", 1);
  write(fd, SSTR(task->size).c_str(), 2);
  write(fd, "\n", 1);
  close(fd);
  this->cook_regina(task->size);
  fd = open("log", O_WRONLY | O_CREAT | O_APPEND, 0777);
  write(fd, "exit\n", 5);
  close (fd);
}

void 	Kitchen::action_finished(void)
{
  this->mutex->lock();
  --(this->actions);
  this->mutex->unlock();
}

void 	Kitchen::close_kitchen()
{
  this->alive = false;
}
