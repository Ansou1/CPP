//
// OneTime.cpp for  in /home/daguen_s/rendu/piscine_cpp_d17/ex02
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 24 11:18:24 2014 daguen_s
// Last update Fri Jan 24 12:24:00 2014 daguen_s
//

#include "OneTime.h"

OneTime::OneTime(std::string const &key)
{
  this->_key = key;
  this->shift = 0;
}

OneTime::~OneTime()
{
}

void			OneTime::encryptChar(char plainchar)
{
  if ((plainchar >= 'a' && plainchar <= 'z') || (plainchar >= 'A' && plainchar <= 'Z'))
    {
      int index;
      int index_key;

      if (plainchar > 96)
	index = 97;
      else
	index = 65;
      if (_key[shift] > 96)
	index_key = 97;
      else
	index_key = 65;
      plainchar = (plainchar - index + (_key[shift]- index_key)) % 26 + index;
    }
  shift = (shift + 1) % _key.size();
  std::cout << plainchar;
}

void			OneTime::decryptChar(char cipherchar)
{
  if ((cipherchar >= 'a' && cipherchar <= 'z') || (cipherchar >= 'A' && cipherchar <= 'Z'))
    {
      int index;
      int index_key;

      if (cipherchar > 96)
	index = 122;
      else
	index = 90;
      if (_key[shift] > 96)
	index_key = 97;
      else
	index_key = 65;
      cipherchar = (cipherchar - index - (_key[shift]- index_key)) % 26 + index;
    }
  shift = (shift + 1) % _key.size();
  std::cout << cipherchar;
}

void			OneTime::reset()
{
  shift = 0;
}
