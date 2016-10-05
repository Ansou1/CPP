#include "mutex.h"

class ScopedLock{
private:
	Mutex *mutex;

public:
	ScopedLock(Mutex *m);
	~ScopedLock();
};
