/*
** OneTime.h for  in /home/daguen_s/rendu/piscine_cpp_d17/ex02
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Fri Jan 24 11:18:21 2014 daguen_s
** Last update Fri Jan 24 11:35:46 2014 daguen_s
*/

#ifndef _ONETIME_H_
# define _ONETIME_H_

#include <iostream>
#include <string>
#include "IEncryptionMethod.h"

class OneTime : public IEncryptionMethod
{
 protected:
  std::string		_key;
  int			shift;

 public:
  OneTime(std::string const &);
  virtual ~OneTime();

  void encryptChar(char plainchar);
  void decryptChar(char cipherchar);
  void reset();
};

#endif /* _ONETIME_H_ */

