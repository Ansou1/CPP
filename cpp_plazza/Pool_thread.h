#ifndef _POOL_THREAD_
#define _POOL_THREAD_ 1

#include <queue>
#include "Plazza.hh"

typedef struct 		Task
{
	TypePizza 		type;
	TaillePizza		size;
}					Task;

class Pool_thread
{
	std::queue<Task *>	tasks;

public:
	Pool_thread();
	~Pool_thread();
	void push(Task *);
	Task *pop();
	bool empty();
};
#endif
