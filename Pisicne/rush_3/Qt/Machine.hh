//
// Machine.hh for  in /home/daguen_s/rendu/piscine_cpp_rush3
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sat Jan 25 21:15:10 2014 daguen_s
// Last update Sat Jan 25 21:16:34 2014 daguen_s
//

#ifndef MACHINE_HPP
#define MACHINE_HPP
#include "IMonitorModule.hpp"
#include	<string>
#include	<iostream>
#include	<fstream>

class Machine : public IMonitorModule
{
protected:
  std::string _name;
  std::string _uname;
  std::string _date;
  std::string _current_battery;
  std::string _full_battery;
  std::string _present_battery;
  std::string _kernel;

public:
  std::vector<std::string>	&search_value(const std::string &file_name, const  std::string &to_find) const;
  std::string get_info(std::string const &, std::string const &) const;

  Machine();
  void init();
};
#endif
