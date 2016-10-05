#include "ScopedLock.h"

ScopedLock::ScopedLock(Mutex *m){
  this->mutex = m;
  m->lock();
}

ScopedLock::~ScopedLock(){
  this->mutex->unlock();
}
