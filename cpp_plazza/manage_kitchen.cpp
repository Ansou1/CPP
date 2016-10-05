#include "manage_kitchen.h"

Manage_kitchen::Manage_kitchen(const int cooker_by_kitchen, const float multiplier, const int time){
  this->cooker_by_kitchen = cooker_by_kitchen;
  this->kitchens = new std::list<Data_kitchen *>;
  this->wait_list = new std::list<std::string *>;
  this->finish_list = new std::list<std::string *>;
  this->multiplier = multiplier;
  this->time = time;
}

std::list<Data_kitchen 	*>  *Manage_kitchen::getKitchens() const{
  return (this->kitchens);
}

std::list<std::string 	*> *Manage_kitchen::getWait() const{
  return (this->wait_list);
}

std::list<std::string 	*> *Manage_kitchen::getFinish() const{
  return (this->finish_list);
}

void Manage_kitchen::setKitchens(const Data_kitchen &k, int id){
  int i = 0;

  for (std::list<Data_kitchen *>::iterator it = this->kitchens->begin(); it != this->kitchens->end(); ++it){

    if (i == id){
      (*it)->cookers_action = k.cookers_action;
      (*it)->f = k.f;
    }
    ++i;
  }
}

void Manage_kitchen::addKichen(){
  Data_kitchen *k = new Data_kitchen;
  const int id = this->kitchens->size();

  k->m = new Message(id);
  k->id = id;
  k->cookers_action = 0;
  this->kitchens->push_back(k);
}

void Manage_kitchen::add_command(const std::string &command){
  std::string *add;

  this->p.parse(command);
  while ((add = this->p.get_command()) != NULL)
    {
      this->wait_list->push_back(add);
      std::cout << "add = " << *add << "\r\n";
      if (this->kitchens->size() * cooker_by_kitchen * 2 < this->wait_list->size()){
	addKichen();
	launch_kitchen(this->cooker_by_kitchen, this->multiplier, this->time, this->kitchens->size() - 1);
	std::cout << "launch kitchen:" << this->kitchens->size() << "\r\n";
      }
      std::list<Data_kitchen *>::iterator i = this->kitchens->begin();
      while (i != this->kitchens->end())
	{
	  if ((*i)->cookers_action != this->cooker_by_kitchen){
	    int fd;
	    fd = open("log", O_WRONLY | O_CREAT | O_APPEND, 0777);
	    write(fd, "envoie", 6);
	    close(fd);
	    (*i)->m->send_kitchen_command(*add);
	    i = this->kitchens->end();
	  }
	  else
	    ++i;
	}
    }
  std::cout << "exit" << "\r\n";
}

void Manage_kitchen::setFinish(const std::string &str, const int id){
  std::string *add = new std::string;
  std::list<std::string *>::iterator it1 = this->wait_list->begin();
  int i = 0;

  for (std::list<Data_kitchen *>::iterator it = this->kitchens->begin(); it != this->kitchens->end(); ++it){
    if (i == id)
      --((*it)->id);
    ++i;
  }
  *add = str;
  this->finish_list->push_back(add);
  this->wait_list->pop_front();
}

void Manage_kitchen::setFridge(const Fridge &f, const int id){
  int i = 0;
  for (std::list<Data_kitchen *>::iterator it = this->kitchens->begin(); it != this->kitchens->end(); ++it){
    if (i == id){
      (*it)->f = f;
    }
    ++i;
  }
}

void	Manage_kitchen::launch_kitchen(const unsigned short nb_cooks, const unsigned int time_powerfull_ms, const unsigned int time_recup_ingredient, const int id){
  pid_t	pid;

  printf("coucou\n");
  Kitchen *kit = new Kitchen(nb_cooks, time_powerfull_ms, time_recup_ingredient, id);
  if ((pid = fork()) == -1)
    {
      throw exception(strerror(errno));
    }
  if (pid == 0)
    {
      kit->start_cooking();
    }
  delete kit;
}

//actualise les données des cuisines à chaque appel
//les données sont ensuite recuperable par les getters
void Manage_kitchen::update(void){
  for (std::list<Data_kitchen *>::iterator it = this->kitchens->begin(); it != this->kitchens->end(); ++it){
    Fridge *f = NULL;
    std::string *s = NULL;
    bool cook_start = false;

    (*it)->m->receive_recpetion(&f, &s, cook_start);
    if (f != NULL){
      (*it)->f = *f;
      delete f;
    }
    if (s != NULL){
      (*it)->cookers_action -= 1;
      this->finish_list->push_back(s);
    }
    if (cook_start){
      (*it)->cookers_action += 1;
    }
  }
}
