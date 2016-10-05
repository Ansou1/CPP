//
// dlloader.cpp for  in /home/daguen_s/rendu/cpp_nibbler
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Thu Apr  3 20:10:18 2014 daguen_s
// Last update Thu Apr  3 20:12:13 2014 daguen_s
//

#include "dlloader.h"
#include <stdlib.h>
#include <iostream>

#if defined(_WIN32)

#include <windows.h>

#elif defined(__unix__)

#include <dlfcn.h>

#endif

typedef IDisplayModule *(*fct)(void);

void	Dlloader::load(const std::string &name)
{
  IDisplayModule *(*get)(void);
  char *error;

#if defined(_WIN32)

  this->whandle = LoadLibrary(name.c_str());

  if (NULL == this->whandle)
    {
      std::cerr << "Error open library" << " [" << name.c_str() << "]" << std::endl;
      exit(1);
    }

  get = (fct) GetProcAddress(this->whandle, "getInstance");

  if (get == NULL)
    {
      throw exception_loader("Error cannot load symbol getInstance");
    }

#elif defined(__unix__)

  this->handle = dlopen(name.c_str(), RTLD_LAZY); //load the library

  if (!this->handle)
    {
      throw exception_loader("Error open library\n");
    }

  dlerror();    /* Clear any existing error */

  //load the symbol of the function
  *(void **) (&get) = dlsym(this->handle, "getInstance");
  if ((error = dlerror()) != NULL)
    {
      throw exception_loader(error);
    }

#endif

  this->obj = (*get)();
}

IDisplayModule *Dlloader::getObj() const
{
  return this->obj;
}

Dlloader::Dlloader()
{
  this->handle = NULL;
}

Dlloader::~Dlloader()
{
#if defined(_WIN32)

  if (this->whandle)
    FreeLibrary(this->whandle);

#elif defined(__unix__)

  if (this->handle)
    dlclose(this->handle);

#endif
}

Dlloader::Dlloader(const Dlloader &){}

Dlloader &Dlloader::operator=(const Dlloader &)
{
  return (*this);
}
