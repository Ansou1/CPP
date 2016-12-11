/*
** Cesar.h for  in /home/daguen_s/rendu/piscine_cpp_d17/ex02
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Fri Jan 24 10:00:29 2014 daguen_s
** Last update Fri Jan 24 10:20:39 2014 daguen_s
*/

#ifndef _CESAR_H_
# define _CESAR_H_

#include <iostream>
#include <string>
#include "IEncryptionMethod.h"

class Cesar : public IEncryptionMethod
{
 protected:
  int		shift;

 public:
  Cesar();
  virtual	~Cesar();

  void encryptChar(char plainchar);
  void decryptChar(char cipherchar);
  void reset();
};

#endif /* _CESAR_H_ */
