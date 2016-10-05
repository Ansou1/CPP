#ifndef _SAFEQUEUE_
#define _SAFEQUEUE_ (1)

#include <queue>
#include "Thread.h"

class SafeQueue {
 private:
  std::queue<int> queue;

 public:
  ~ISafeQueue(void);
  void push(int value);
  bool tryPop(int* value);
  bool isFinished(void);
  void setFinished(void);
};

#endif

SafeQueue::~ISafeQueue(void){

}

void SafeQueue::push(int value){
this->queue
}

bool SafeQueue::tryPop(int* value){

}

bool SafeQueue::isFinished(void){

}

void SafeQueue::setFinished(void){

}
