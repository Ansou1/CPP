#ifndef _CONDVAR_H_
# define _CONDVAR_H_

#include <pthread.h>
#include "ICondVar.hh"
#include "Exception.hpp"

class CondVar : public ICondVar
{
    pthread_cond_t	condition;
    pthread_mutex_t	mutex;

public:
    CondVar();
    CondVar(const CondVar &old);
    CondVar &operator=(const CondVar &old);
    virtual ~CondVar();

    virtual void	wait(void);
    virtual void	signal(void);
    virtual void	broadcast(void);
};

#endif /* _CONDVAR_H_ */
