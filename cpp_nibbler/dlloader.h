/*
** dlloader.h for  in /home/daguen_s/rendu/cpp_nibbler
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Thu Apr  3 20:12:41 2014 daguen_s
** Last update Thu Apr  3 20:13:16 2014 daguen_s
*/

#ifndef _DLLOADER_H
#define _DLLOADER_H

#include "displaymodule.h"
#if defined(__WIN32)
#include <windows.h>
#endif

class Dlloader
{
 private:
  IDisplayModule *obj;
  void *handle;
   #if defined(__WIN32)
    HMODULE whandle;
  #endif

 public:
  Dlloader();
  ~Dlloader();
  Dlloader(const Dlloader &);
  Dlloader		&operator=(const Dlloader &);
  void			load(const std::string &name);
  IDisplayModule	*getObj() const;
};

#endif
