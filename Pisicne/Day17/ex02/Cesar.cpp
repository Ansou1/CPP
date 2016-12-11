//
// Cesar.cpp for  in /home/daguen_s/rendu/piscine_cpp_d17/ex02
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Fri Jan 24 10:00:02 2014 daguen_s
// Last update Fri Jan 24 12:24:18 2014 daguen_s
//

#include "Cesar.h"

Cesar::Cesar()
{
  reset();
}

Cesar::~Cesar()
{
}

void			Cesar::encryptChar(char plainchar)
{
  if ((plainchar >= 'a' && plainchar <= 'z') || (plainchar >= 'A' && plainchar <= 'Z'))
    {
      int index;

      if (plainchar > 96)
	index = 97;
      else
	index = 65;
      plainchar = (plainchar - index + shift) % 26 + index;
    }
  shift = (shift + 1) % 26;
  std::cout << plainchar;
}

void			Cesar::decryptChar(char cipherchar)
{
  if ((cipherchar >= 'a' && cipherchar <= 'z') || (cipherchar >= 'A' && cipherchar <= 'Z'))
  {
    int index;

    if (cipherchar > 96)
      index = 122;
    else
      index = 90;
    cipherchar = (cipherchar - index - shift) % 26 + index;
  }
  shift = (shift + 1) % 26;
  std::cout << cipherchar;
}

void			Cesar::reset()
{
  shift = 3;
}
