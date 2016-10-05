//
// Lexer.hh for  in /home/daguen_s/rendu/cpp_abstractvm
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Wed Feb 26 13:52:40 2014 daguen_s
// Last update Wed Feb 26 13:52:52 2014 daguen_s
//

#ifndef LEXER_HH
# define LEXER_HH

#include "VirtualMachine.hh"

class Lexer : public VirtualMachine
{
private:
  std::vector<std::string *> *_data;
  bool _exit;

public:
  Lexer();
  ~Lexer();
  bool getExit() const;
  std::vector<std::string *> *getData() const;
  void replace(std::string &str, const char, const char) const;
  void getArguments(std::string const &);
  void getInstructions(std::string const &);
};

#endif
