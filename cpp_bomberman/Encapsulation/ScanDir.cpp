//
// ScanDir.cpp for lol in /home/lerman_v/Git/C++/cpp_bomberman
// 
// Made by lerman_v
// Login   <lerman_v@epitech.net>
// 
// Started on  Wed Jun 11 18:10:27 2014 lerman_v
// Last update Thu Jun 12 04:06:55 2014 lerman_v
//

#include "ScanDir.hh"

ScanDir::ScanDir(std::string const & dir, std::string const & filter)
{
  struct dirent	**namelist;
  int		i, n;
  std::string	tmp;

  if ((n = scandir(dir.c_str(), &namelist, NULL, alphasort)) == -1)
    return ;

  for (i = 0; i < n; i++)
    {
      tmp.clear();
      tmp = namelist[i]->d_name;
      if (filter == "" || tmp.substr(tmp.rfind(".")) == filter)
	_files.push_back(tmp);
      free(namelist[i]);
    }
  free(namelist);
}

ScanDir::~ScanDir()
{
  
}

size_t		ScanDir::getNbFiles() const
{
  return _files.size();
}

std::string	ScanDir::getFile(size_t i) const
{
  return _files[i];
}
