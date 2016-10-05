#include "IMutex.h"

#include <iostream>

class Mutex : public IMutex{
private:
	pthread_mutex_t	mutex;

public:
					Mutex(void);
	virtual 		~Mutex(void);
	virtual void 	lock(void);
	virtual void 	unlock(void);
	virtual bool 	trylock(void);
};