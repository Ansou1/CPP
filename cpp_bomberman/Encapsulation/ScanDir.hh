//
// ScanDir.hh for lol in /home/lerman_v/Git/C++/cpp_bomberman
//
// Made by lerman_v
// Login   <lerman_v@epitech.net>
//
// Started on  Wed Jun 11 15:21:22 2014 lerman_v
// Last update Thu Jun 12 03:57:55 2014 lerman_v
//

#ifndef SCANDIR_HH_
#define SCANDIR_HH_

#include <vector>
#include <string>
#include <dirent.h>
#include <stdlib.h>

#include <iostream>

class ScanDir
{
private:
  std::vector<std::string>	_files;

public:
  ScanDir(std::string const & dir, std::string const & filter = "");
  ~ScanDir();
  size_t	getNbFiles() const;
  std::string	getFile(size_t) const;
};

#endif /* SCANDIR_HH_ */
