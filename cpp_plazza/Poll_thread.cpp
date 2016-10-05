#include "Pool_thread.h"

Pool_thread::Pool_thread(){

}

Pool_thread::~Pool_thread(){

}

void Pool_thread::push(Task *t){
  this->tasks.push(t);
}

Task *Pool_thread::pop(){
  Task *ret = this->tasks.front();

  this->tasks.pop();
  return ret;
}

bool Pool_thread::empty(){
  return (this->tasks).empty();
}
