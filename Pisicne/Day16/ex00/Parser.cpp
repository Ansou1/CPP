//
// Parser.cpp for  in /home/daguen_s/rendu/piscine_cpp_d16/ex00
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Thu Jan 23 09:59:30 2014 daguen_s
// Last update Thu Jan 23 14:47:17 2014 daguen_s
//

#include <stdlib.h>
#include "Parser.h"

Parser::Parser()
{
  this->_result = 0;
}

Parser::Parser(Parser const &src)
{
  this->_result = src._result;
  this->operateur = src.operateur;
  this->operands = src.operands;
}

Parser			&Parser::operator=(Parser const &src)
{
  this->_result = src._result;
  this->operateur = src.operateur;
  this->operands = src.operands;
  return (*this);
}

Parser::~Parser()
{
}

void			Parser::reset()
{
  while (!this->operands.empty())
    this->operands.pop();
  while (!this->operateur.empty())
    this->operateur.pop();
  this->_result = 0;
}

int			Parser::result() const
{
  return this->_result;
}

void			Parser::feed(const std::string &calcul)
{
  unsigned int		i = 0;
  int			val1;
  int			val2;
  char			operation;
  std::string		nbr_to_push;

  while (i < calcul.size())
    {
      if (calcul[i] == '+' || calcul[i] == '-' || calcul[i] == '*' || calcul[i] == '/' || calcul[i] == '%')
	this->operateur.push(calcul[i]);
      else if (calcul[i] >= '0' && calcul[i] <= '9')
	{
	  nbr_to_push.clear();
	  while (calcul[i] >= '0' && calcul[i] <= '9' && i < calcul.size())
	    {
	      nbr_to_push.push_back(calcul[i]);
	      i++;
	    }
	  this->operands.push(atoi(nbr_to_push.c_str()));
	  i--;
	}
      else if (calcul[i] == ')')
	{
	  val2 = this->operands.top();
	  this->operands.pop();
	  val1 = this->operands.top();
	  this->operands.pop();
	  operation = this->operateur.top();
	  this->operateur.pop();
	  if (operation == '+')
	    this->operands.push(val1 + val2);
	  else if (operation == '-')
	    this->operands.push(val1 - val2);
	  else if (operation == '*')
	    this->operands.push(val1 * val2);
	  else if (operation == '/')
	    this->operands.push(val1 / val2);
	  else if (operation == '%')
	    this->operands.push(val1 % val2);
	}
      i++;
    }
  if (!(this->operateur.empty()))
    {
      val2 = this->operands.top();
      this->operands.pop();
      if (!(this->operands.empty()))
	{
	  val1 = this->operands.top();
	}
      else
	{
	  this->_result += val2;
	  return;
	}
      this->operands.pop();
      operation = this->operateur.top();
      this->operateur.pop();
      if (operation == '+')
	this->operands.push(val1 + val2);
      else if (operation == '-')
	this->operands.push(val1 - val2);
      else if (operation == '*')
	this->operands.push(val1 * val2);
      else if (operation == '/')
	this->operands.push(val1 / val2);
      else if (operation == '%')
	this->operands.push(val1 % val2);
    }
  this->_result += this->operands.top();
}
