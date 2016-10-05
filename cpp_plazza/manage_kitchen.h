#ifndef MANAGE_KITCHEN
#define MANAGE_KITCHEN

#include <list>
#include "Kitchen.h"
#include "Parser.h"
#include "Plazza.hh"
#include "message.h"

struct Data_kitchen{
	int 	id;
	int 	cookers_action;
	Fridge  f;
	Message *m;
};

class Manage_kitchen{
private:
	int 						cooker_by_kitchen;
	float						multiplier;
	int 						time;
	Parser						p;
	std::list<Data_kitchen 	*> 	*kitchens;
	std::list<std::string 	*> 	*wait_list;
	std::list<std::string   *> 	*finish_list;

public:
	Manage_kitchen(const int cooker_by_kitchen, const float multiplier, const int time);
	std::list<Data_kitchen 	*> *getKitchens() const;
	std::list<std::string 	*> *getWait() const;
	std::list<std::string 	*> *getFinish() const;
	void setKitchens(const Data_kitchen &, int id);
	void setFridge(const Fridge &f, const int id);
	void add_command(const std::string &command);
	void setFinish(const std::string & str, const int id);
	void addKichen(Data_kitchen *);
	void launch_kitchen(const unsigned short nb_cooks, const unsigned int time_powerfull_ms, const unsigned int time_recup_ingredient, const int id);
	void addKichen();
	void update(void);
};

#endif
