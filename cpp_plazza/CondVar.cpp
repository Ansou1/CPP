#include "CondVar.hh"

CondVar::CondVar()
{
  if (pthread_cond_init(&(this->condition), NULL) != 0)
    throw exception("ERROR: pthread_cond_init.\n");
  if (pthread_mutex_init(&(this->mutex), NULL) != 0)
    throw exception("ERROR: pthread_mutex_init.\n");
}

CondVar::CondVar(const CondVar &old)
{
  this->condition = old.condition;
  this->mutex = old.mutex;
}

CondVar &CondVar::operator=(const CondVar &old)
{
  this->condition = old.condition;
  this->mutex = old.mutex;
  return (*this);
}

CondVar::~CondVar()
{
  if (pthread_cond_destroy(&(this->condition)) != 0)
    throw exception("ERROR: pthread_cond_destroy.\n");
}

void	CondVar::wait(void)
{
  if (pthread_cond_wait(&(this->condition), &(this->mutex)) != 0)
    throw exception("ERROR: pthread_cond_wait.\n");
}

void	CondVar::signal(void)
{
  if (pthread_cond_signal(&(this->condition)) != 0)
    throw exception("ERROR: pthread_cond_signal.\n");
}

void	CondVar::broadcast(void)
{
  if (pthread_cond_broadcast(&(this->condition)) != 0)
    throw exception("ERROR: pthread_cond_broadcast.\n");
}
