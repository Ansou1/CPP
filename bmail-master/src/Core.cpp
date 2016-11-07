//
// Core.cpp for rush in /home/dell-a_f//projets/suicide
// 
// Made by florian dell-aiera
// Login   <dell-a_f@epitech.net>
// 
// Started on  Sun Mar 10 10:50:33 2013 florian dell-aiera
// Last update Sun Mar 10 18:11:47 2013 florian dell-aiera
//


#include	"../headers/Core.hh"

Core::Core()
{

}


Core::~Core()
{
}

bool	Core::sendMail(Core *core, const std::string &addr, const unsigned short port, const std::string &From, const std::string &To, const std::string &Subject, const std::string &Text)
{
  core->_process.sendMail(addr, port, From, To, Subject, Text);
  return (true);
}

void	display(const std::string &e)
{
  std::cout << e << std::endl;
}

bool	Core::receiveMail()
{
  std::list<std::string>	tmp;

  this->_process.receiveMail(this);
  tmp = this->_process.getMail();
  std::cout << "mylist contains:";
  for_each(tmp.begin(), tmp.end(), display);
  return (true);
}

bool	Core::deleteMail() const
{
  return (true);
}

void	Core::parsing_core()
{
  this->_parser.parsing(this);
}
