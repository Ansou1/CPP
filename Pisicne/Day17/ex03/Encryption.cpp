//
// Encryption.cpp for  in /home/daguen_s/rendu/piscine_cpp_d17/ex03
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 24 12:37:57 2014 daguen_s
// Last update Fri Jan 24 13:12:35 2014 daguen_s
//

#include <algorithm>
#include "Encryption.h"

Encryption::Encryption(const IEncryptionMethod & encryptionMethod, void (IEncryptionMethod::*fct)(char))
{
  method = const_cast<IEncryptionMethod *>(&encryptionMethod);
  action = fct;
}

Encryption::~Encryption()
{
}

Encryption		&Encryption::operator()(char c)
{
  (method->*action)(c);
  return *this;
}

void			Encryption::encryptString(IEncryptionMethod & encryptionMethod, std::string const & toEncrypt)
{
  encryptionMethod.reset();
  std::for_each(toEncrypt.begin(), toEncrypt.end(), Encryption(encryptionMethod, &IEncryptionMethod::encryptChar));
  std::cout << std::endl;
}

void			Encryption::decryptString(IEncryptionMethod & encryptionMethod, std::string const & toDecrypt)
{
  encryptionMethod.reset();
  std::for_each(toDecrypt.begin(), toDecrypt.end(), Encryption(encryptionMethod, &IEncryptionMethod::decryptChar));
  std::cout << std::endl;
}
