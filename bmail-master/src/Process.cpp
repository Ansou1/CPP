#include	"../headers/Core.hh"

Core::Process::Process()
{

}

Core::Process::~Process()
{

}

bool	Core::Process::helo(char buff[1024]) const
{
  send(this->_ssock, "HELO CLIENT\n", 12, 0);
  recv(this->_ssock, buff, 1024, 0);
  bzero(buff, 1024);
  return (true);
}

bool	Core::Process::peoples(char buff[1024], const std::string &From, const std::string &To) const
{
  std::string	f;
  std::string	t;

  f = f + "MAIL FROM: <";
  f = f + From;
  f = f + ">\n";
  t = t + "RCPT TO: <";
  t = t + To;
  t = t + ">\n";
  send(this->_ssock, f.c_str(), f.size(), 0);
  recv(this->_ssock, buff, 1024, 0);
  bzero(buff, 1024);
  send(this->_ssock, t.c_str(), t.size(), 0);
  recv(this->_ssock, buff, 1024, 0);
  bzero(buff, 1024);
  return (true);
}

bool	Core::Process::data(char buff[1024], const std::string &Subject, const std::string &Text)
{
  std::string	t;
  std::string	s;

  s = "Subject: ";
  s = s + Subject;
  s = s + "\n";
  send(this->_ssock, "DATA\n", 5, 0);
  recv(this->_ssock, buff, 1024, 0);
  bzero(buff, 1024);
  send(this->_ssock, s.c_str(), s.size(), 0);
  recv(this->_ssock, buff, 1024, 0);
  bzero(buff, 1024);
  t = Text + "\n.\n";
  send(this->_ssock, t.c_str(), t.size(), 0);
  recv(this->_ssock, buff, 1024, 0);
  bzero(buff, 1024);
  return (true);
}

bool	Core::Process::sendMail(const std::string &addr, const unsigned short port, const std::string &From, const std::string &To, const std::string &Subject, const std::string &Text)
{
  char	buff[1024];

  bzero(buff, 1024);
  this->_ssock = socket(AF_INET, SOCK_STREAM, 0);  
  this->_ssin.sin_addr.s_addr = inet_addr(addr.c_str());
  this->_ssin.sin_family = AF_INET;
  this->_ssin.sin_port = htons(port);
  if(connect(this->_ssock, (SOCKADDR*)&this->_ssin, sizeof(this->_ssin)) != -1)
    {
      this->helo(buff);
      this->peoples(buff, From, To);
      this->data(buff, Subject, Text);
      return (true);
    }
  else
    return (false);
}


int	Core::Process::nbr_mail(char *buffer) const 
{
  int	i;
  int	j;
  char	cpy[SIZE];

  i = 0;
  j = 0;
  cpy[0] = 0;
  while (buffer[i] && buffer[i] != ' ')
    i++;
  i++;
  while (buffer[i] && buffer[i] != ' ')
    cpy[j++] = buffer[i++];
  j = atoi(cpy);
  return (j);
}

bool	Core::Process::receiveMail(Core	*c)
{
  int	nb;
  int	i = 1;
  std::string		retr;
  std::ostringstream	oss;
  std::string		str;
  std::string		in;
  
  retr[0] = 0;
  this->p.connect_serveur(c);
  if (this->p.getError() != -1)
    {
      if (c->getPort() == 110)
      	{
	  read_server(this->p.getSocket(), this->buffer);
	  bzero(this->buffer, SIZE);	  
	  write_server(this->p.getSocket(), "USER epitech@dualabs.com\n");
	  read_server(this->p.getSocket(), this->buffer);
	  bzero(this->buffer, SIZE);
	  write_server(this->p.getSocket(), "PASS epitech\n");
	  read_server(this->p.getSocket(), this->buffer);
	  bzero(this->buffer, SIZE);	  
	  write_server(this->p.getSocket(), "stat\n");
	  read_server(this->p.getSocket(), this->buffer);
	  nb = this->nbr_mail(this->buffer);
	  bzero(this->buffer, SIZE);
	  while (i < nb )
	    {
	      oss << i;
	      str = oss.str();
	      retr = "retr " + str + "\n";
	      write_server(this->p.getSocket(), retr.c_str());
	      read_server(this->p.getSocket(), this->buffer);
	      in.insert(0, this->buffer);
	      this->mail.push_back(in);
	      bzero(this->buffer, SIZE);
	      oss.str("");
	      retr.erase(0, retr.size());
	      in.erase(0, in.size());
	      i++;
	    }
	  write_server(this->p.getSocket(), "quit\n");
	  read_server(this->p.getSocket(), this->buffer);
	  bzero(this->buffer, SIZE);
	  close(this->p.getSocket());
	}
    }
  return (true);
}

bool	Core::Process::deleteMail() const
{
  return (true);
}

int	Core::Process::read_server(const SOCKET &sock, char *buffer) const
{
  int	n = 0;

  while (buffer[strlen(buffer) -1] != '\n')
    {
      if (recv(sock, buffer, SIZE - 1, 0) < 0)
	{
	  std::cerr << "Erreur on recv" << std::endl;
	  exit(EXIT_FAILURE);
	}
    }
  return (n);
}

void	Core::Process::write_server(const SOCKET &sock, const char *buffer) const
{
  if (send(sock, buffer, strlen(buffer), 0) < 0)
    {
      std::cerr << "Erreur on send()" << std::endl;
      exit(EXIT_FAILURE);
    }
}

std::list<std::string>	Core::Process::getMail() const
{
  return (this->mail);
}
