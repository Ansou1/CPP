#ifndef _ICONDVAR_H_
# define _ICONDVAR_H_

#include <iostream>
#include <string>

class ICondVar
{
public:
  virtual ~ICondVar() {};
  virtual void	wait(void) = 0;
  virtual void	signal(void) = 0;
  virtual void	broadcast(void) = 0;
};

#endif /* _ICONDVAR_H_ */
