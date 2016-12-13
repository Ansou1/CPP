//
// IMonitorModule.hpp for  in /home/daguen_s/rendu/piscine_cpp_rush3
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sat Jan 25 21:15:19 2014 daguen_s
// Last update Sat Jan 25 21:17:26 2014 daguen_s
//

#ifndef IMONITOR_MODULE_H
#define IMONITOR_MODULE_H

#include <iostream>
#include <fstream>
#include <errno.h>
#include <vector>
#include <iterator>
#include <string>
#include <string.h>
#include <algorithm>

class IMonitorModule
{
public:
  virtual ~IMonitorModule(){}

  virtual std::vector<std::string>	&search_value(const std::string &file_name, const  std::string &to_find) const = 0;
  virtual std::string get_info(std::string const &, std::string const &) const = 0;
};

#endif
