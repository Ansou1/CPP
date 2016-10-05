#ifndef	_NAMEDPIPE_HH_
# define _NAMEDPIPE_HH_

#include <unistd.h>
#include <iostream>
#include <string>
#include <fstream>
#include <strings.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

class NamedPipe
{
private:
  std::string		_file;
  int				    _fd;

public:
  NamedPipe(const std::string &);
  ~NamedPipe();

  bool			writes(const std::string &) const;
  bool			reads(std::string &) const;
  void			destroy();
  int 			getFd() const;

  std::string		getName() const;
};

#endif /* !_NAMEDPIPE_HH_ */
