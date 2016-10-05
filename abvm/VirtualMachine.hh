//
// VirtualMachine.hh for  in /home/daguen_s/rendu/cpp_abstractvm
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Wed Feb 26 15:19:23 2014 daguen_s
// Last update Sun Mar  2 12:14:58 2014 florian
//

#ifndef VIRTUALMACHINE_HH
# define VIRTUALMACHINE_HH

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "Exception.hpp"
#include "IOperand.hh"

class  VirtualMachine
{
protected:
  std::vector<std::string> label;//represent the labels for the instructions
  std::vector<std::string> type;//represent the types for the numbers

public:
  /*
  **split une chaine en vector de chaine entre chaque separateur
  **spécifés par sep.
  */
  std::vector<std::string> explode(const std::string &str, const char &sep) const
  {
    std::istringstream split(str);
    std::vector<std::string> tokens;
    std::string each;
    while (std::getline(split, each, sep))
      {
	tokens.push_back(each);
      }
    return tokens;
  }


  /*
  ** check if the value str is in the vector
  */
  bool	is_in(std::vector<std::string>::const_iterator first, std::vector<std::string>::const_iterator last, const std::string &str) const
  {
    while (first!=last)
      {
	if (*first == str)
	  return true;
	++first;
      }
    return false;
  }

  VirtualMachine()
  {
    this->label = explode("add,mul,dump,pop,exit,sub,div,mod,print,;;", ',');
    this->type = explode("int8,int16,int32,float,double", ',');
  }

  ~VirtualMachine(){}
};

#endif
