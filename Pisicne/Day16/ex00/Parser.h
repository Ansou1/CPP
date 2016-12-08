/*
** Parser.h for  in /home/daguen_s/rendu/piscine_cpp_d16/ex00
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Thu Jan 23 09:59:32 2014 daguen_s
** Last update Thu Jan 23 11:23:59 2014 daguen_s
*/

#ifndef _PARSER_H_
# define _PARSER_H_

#include <iostream>
#include <string>
#include <stack>

class Parser
{
  std::stack<int>	operands;
  std::stack<char>	operateur;
  int			_result;

 public:
  Parser();
  Parser(Parser const &);
  Parser		&operator=(Parser const &);
  ~Parser();

  void			feed(const std::string &);
  int			result() const;
  void			reset();
};

#endif /* _PARSER_H_ */
