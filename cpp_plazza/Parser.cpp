#include "Parser.h"
#include "Plazza.hh"

#define SSTR( x ) dynamic_cast< std::ostringstream & >(( std::ostringstream() << std::dec << x ) ).str()

void	Parser::parse(const std::string &commande)
{
  std::string tmps;
  std::string nbr;
  std::string *s;
  unsigned int i1 = 0;
  unsigned int i2 = 0;
  int tmp;

  while (i2 < commande.size())
    {
      if ((i2 = commande.find(";", i2)) == (unsigned int)std::string::npos)
	i2 = commande.size();
      s = new std::string;
      tmps = commande.substr(i1, i2 - i1);
      nbr = tmps.substr(tmps.find("x", 0) + 1, tmps.size() - tmps.find("x", 0));
      std::stringstream concat;
      concat << nbr;
      concat >> tmp;
      while (tmp > 0)
	{
	  s = new std::string;
	  *s = tmps.substr(0, tmps.find("x") - 1);
	  *s += ";";
	  this->command.push_back(s);
	  --tmp;
	}
      ++i2;
      i1 = i2;
    }
}

void 	Parser::commands(const std::string &commande){
  unsigned int i1 = 0;
  unsigned int i2 = 0;
  std::string *tmps;

  while (i2 < commande.size()){
    if ((i2 = commande.find(";", i2)) == (unsigned int)std::string::npos)
      i2 = commande.size();
    tmps = new std::string;
    *tmps = (commande.substr(i1, i2 - i1));
    this->command.push_back(tmps);
    int fd;
    fd = open("log", O_WRONLY | O_CREAT | O_APPEND, 0777);
    write(fd, SSTR(this->command.size()).c_str(), 1);
    write(fd, "\n", 1);
    close(fd);
    ++i2;
    i1 = i2;
  }
}

std::string *Parser::get_command(void)
{
  std::string *ret = *(this->command.begin());

  if (this->command.empty())
    return NULL;
  this->command.pop_front();
  return (ret);
}

unsigned int Parser::getSize(void) const{
  return this->command.size();
}

Parser::Parser(){}

Parser::~Parser(){}
