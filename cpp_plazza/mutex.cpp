#include "mutex.h"

Mutex::Mutex(void){
	pthread_mutex_init(&(this->mutex), NULL);
}

Mutex::~Mutex(void){

}

void Mutex::lock(void){
	pthread_mutex_lock(&this->mutex);
}

void Mutex::unlock(void){
	pthread_mutex_unlock(&this->mutex);
}

bool Mutex::trylock(void){
	return pthread_mutex_trylock(&this->mutex);
}
