/*
** Encryption.h for  in /home/daguen_s/rendu/piscine_cpp_d17/ex03
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Fri Jan 24 12:37:59 2014 daguen_s
** Last update Fri Jan 24 13:06:56 2014 daguen_s
*/

#ifndef _ENCRYPTION_H_
# define _ENCRYPTION_H_

#include <iostream>
#include <string>
#include "IEncryptionMethod.h"

class Encryption
{
  IEncryptionMethod	*method;
  void (IEncryptionMethod::*action)(char);
 public:
  Encryption(const IEncryptionMethod &, void (IEncryptionMethod::*fct)(char));
  ~Encryption();

  Encryption		&operator()(char);

  static void encryptString(IEncryptionMethod & encryptionMethod, std::string const & toEncrypt);
  static void decryptString(IEncryptionMethod & encryptionMethod, std::string const & toDecrypt);
};

#endif /* _ENCRYPTION_H_ */
