#ifndef _PACKAGE_H_
# define _PACKAGE_H_

#include	<string>
#include	<sstream>
#include	<iostream>
#include	<map>
#include	<list>
#include "Pool_thread.h"
#include	"Plazza.hh"
#define   FRIDGE ('0')
#define   START_COOK ('1')
#define   COMMAND ('2')

class Package
{
private:
  std::map<std::string, int>	pizza;
  std::map<std::string, int>	size;

public:
  Package();
  Package(const Package &old);
  virtual ~Package();
  Task *unpackCommand(std::string str);
  std::string &getCommandByType(const TypePizza pizza, const TaillePizza size) const;
  std::string pack_fridge(const Fridge &f) const;
  const std::string &packCommand(TypePizza pizza, TaillePizza size) const;
  std::string &packCook();
  void unpack(const std::string &str, Fridge **f, std::string **s, bool &cook_start);
  std::string &getstrtype_pizza(const TypePizza pizza) const;
  std::string &getstrtype_size(const TaillePizza size) const;
};


#endif /* _PACKAGE_H_ */
