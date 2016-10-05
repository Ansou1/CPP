#include "NamedPipe.hh"
#include "Plazza.hh"

NamedPipe::NamedPipe(const std::string & name)
{
  this->_file = "/tmp/" + name;
  mkfifo(this->_file.c_str(), 0644);
  if ((this->_fd = open(this->_file.c_str(), O_RDWR)) == -1)
    std::cerr << "error openning namep pipe" << std::endl;
}

NamedPipe::~NamedPipe()
{
  close(this->_fd);
}

bool			NamedPipe::writes(const std::string &src) const
{
  write(this->_fd, src.c_str(), src.size());
  return (true);
}

bool			NamedPipe::reads(std::string &src) const
{
  int           mode;
  char          buf[4096];
  int           ret;

  mode = fcntl(this->_fd, F_GETFL, 0);
  mode |= O_NONBLOCK;
  fcntl(this->_fd, F_SETFL, mode);
  ret = read(this->_fd, buf, 4096);
  if (ret > 0){
    buf[ret] = 0;
    src = buf;
    return (true);
  }
  else
      return (false);
  return (true);
}

void			NamedPipe::destroy()
{
  unlink(this->_file.c_str());
}

std::string		NamedPipe::getName() const
{
  return (this->_file);
}

int NamedPipe::getFd() const{
  return (this->_fd);
}
