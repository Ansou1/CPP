#include	"../headers/Core.hh"

Core::Connection::Connection()
{

}

Core::Connection::~Connection()
{

}

void	Core::Connection::connect_serveur(Core *c)
{
  
  this->_sock = socket(AF_INET, SOCK_STREAM, 0);
  this->_sin.sin_addr.s_addr = inet_addr(c->getIp().c_str());
  this->_sin.sin_family = AF_INET;
  this->_sin.sin_port = htons(c->getPort());
  if (connect(this->_sock, (SOCKADDR*)&(this->_sin), sizeof(this->_sin)) != -1)
    this->_error = 0;
  else
    this->_error = -1;
}

int	Core::Connection::getError() const
{
  return (this->_error);
}


SOCKET	Core::Connection::getSocket() const
{
  return (this->_sock);
}

SOCKADDR_IN Core::Connection::getSin() const
{
  return (this->_sin);
}
