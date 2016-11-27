//
// Parts.cpp for  in /home/daguen_s/rendu/piscine_cpp_d07a/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Tue Jan 14 21:47:36 2014 daguen_s
// Last update Wed Jan 15 00:38:01 2014 daguen_s
//

#include <iostream>
#include <string>
#include "Parts.h"

Arms::Arms(std::string serial, bool functionnal)
{
  this->_serial = serial;
  this->_functionnal = functionnal;
}

Arms::~Arms()
{
}

std::string Arms::serial() const
{
  return this->_serial;
}

bool Arms::isFunctionnal() const
{
  return this->_functionnal;
}

void	Arms::informations() const
{
  std::cout << "\t[Parts] Arms " << this->_serial << " status : " << (this->_functionnal ? "OK" : "KO") << std::endl;
}


Legs::Legs(std::string serial, bool functionnal)
{
  this->_serial = serial;
  this->_functionnal = functionnal;
}

Legs::~Legs()
{
}

std::string Legs::serial() const
{
  return this->_serial;
}

bool Legs::isFunctionnal() const
{
  return this->_functionnal;
}

void	Legs::informations() const
{
  std::cout << "\t[Parts] Legs " << this->_serial << " status : " << (this->_functionnal ? "OK" : "KO") << std::endl;
}


Head::Head(std::string serial, bool functionnal)
{
  this->_serial = serial;
  this->_functionnal = functionnal;
}

Head::~Head()
{
}

std::string Head::serial() const
{
  return this->_serial;
}

bool Head::isFunctionnal() const
{
  return this->_functionnal;
}

void	Head::informations() const
{
  std::cout << "\t[Parts] Head " << this->_serial << " status : " << (this->_functionnal ? "OK" : "KO") << std::endl;
}
