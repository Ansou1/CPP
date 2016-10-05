#ifndef _THREAD_
#define _THREAD_ (1)

#include <pthread.h>

class Thread{
 public:
  enum thread_status{NOTYETSTARTED, RUNNING, DEAD};

 private:
  pthread_t 		thread;
  thread_status 	status;

 public:
  Thread();
  ~Thread();
  void start(void *(*start_routine) (void *), void *arg);
  void wait_end();
  thread_status getStatus() const;
};

#endif
