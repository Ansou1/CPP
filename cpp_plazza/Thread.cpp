#include "Thread.h"

Thread::Thread(){
  this->status = NOTYETSTARTED;
}

Thread::~Thread(){
  pthread_exit(NULL);
}

void Thread::start(void *(*start_routine) (void *), void *arg){
  this->status = RUNNING;
  pthread_create(&this->thread, NULL, start_routine, arg);
}

void Thread::wait_end(){
  pthread_join(this->thread, NULL);
  this->status = DEAD;
}

Thread::thread_status Thread::getStatus() const{
  return this->status;
}
