//
// Lexer.cpp for  in /home/daguen_s/rendu/cpp_abstractvm
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Wed Feb 26 13:51:33 2014 daguen_s
// Last update Sun Mar  2 12:25:55 2014 florian
//

#include "Lexer.hh"

Lexer::Lexer()
{
  this->_data = new std::vector<std::string *>;
  this->_exit = false;
}

Lexer::~Lexer()
{
  for (std::vector<std::string *>::iterator it = this->_data->begin(); it != this->_data->end(); ++it)
    {
      delete[] *it;
    }
  delete this->_data;
}

bool Lexer::getExit() const
{
  return this->_exit;
}

//replace
void Lexer::replace(std::string &str, const char rep, const char by) const
{
  for (size_t i(0); str[i]; ++i)
    {
      if(str[i] == rep)
	str[i] = by;
    }
}

//recupere une ligne d'arguments
void Lexer::getArguments(std::string const &line)
{
  int i = 0;
  std::string tmp = line;
  replace(tmp, '(', ' ');
  replace(tmp, ')', ' ');
  std::vector<std::string> arg = explode(tmp, ' ');
  std::string *data = new std::string[3];
  while (arg[i].size() == 0) ++i;
  data[0] = arg[i];
  ++i;
  while (arg[i].size() == 0) ++i;
  data[1] = arg[i];
  ++i;
 while (arg[i].size() == 0) ++i;
  data[2] = arg[i];
  this->_data->push_back(data);
}

//recupere une ligne sans agruments
void Lexer::getInstructions(std::string const &line)
{
  if (line[0] == ';') return;
  std::string tmp = line;
  tmp.erase(std::remove(tmp.begin(), tmp.end(), ' '), tmp.end());
  std::string *data = new std::string[1];
  data[0] = tmp;
  this->_data->push_back(data);
  if (tmp == "exit")
    this->_exit = true;
}

std::vector<std::string *> *Lexer::getData() const
{
  return this->_data;
}
