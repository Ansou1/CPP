#ifndef IMUTEX
#define IMUTEX

#include <pthread.h>

class IMutex
{
public:
  virtual ~IMutex(void){}
  virtual void lock(void) = 0;
  virtual void unlock(void) = 0;
  virtual bool trylock(void) = 0;
};

#endif
