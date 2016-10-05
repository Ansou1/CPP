//
// Parser.hh for  in /home/daguen_s/rendu/cpp_abstractvm
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Wed Feb 26 15:19:10 2014 daguen_s
// Last update Thu Feb 27 10:04:32 2014 daguen_s
//

#ifndef PARSER_HH
# define PARSER_HH

#include <stdint.h>
#include <fstream>
#include "Lexer.hh"
#include "VirtualMachine.hh"
#include <limits>
#include <map>

class Parser : public VirtualMachine
{
private:
  const std::string _fileName;
  std::map<std::string, void (Parser::*)(std::string const &, std::string const &, unsigned int const &) const> _flow;

public:
  template <typename T>
  void get_offset(T &min, T &max) const
  {
    min = std::numeric_limits<T>::min();
    max = std::numeric_limits<T>::max();
  }

  template <typename T>
  std::string nbr_to_str(T const &nbr) const
  {
    std::ostringstream convert;
    std::string ret;

    convert << nbr;
    ret = convert.str();
    return ret;
  }

  template<typename T>
  T str_to_nbr(std::string const &value) const
  {
    std::istringstream buffer(value);
    T stock;

    buffer >> stock;
    return stock;
  }

  //const std::map<std::basic_string<char>, void (Parser::*)(const std::basic_string<char>&, const std::basic_string<char>&, const unsigned int&)const>
  bool match_nbr2(const std::string &nbr) const;
  bool cleanStr(std::string &clean) const;
  void checkLimitint8(std::string const & type, std::string const & val, unsigned int const &num) const;
  void checkLimitint16(std::string const & type, std::string const & val, unsigned int const &num) const;
  void checkLimitint32(std::string const & type, std::string const & val, unsigned int const &num) const;
  void checkLimitfloat(std::string const & type, std::string const & val, unsigned int const &num) const;
  void checkLimitdouble(std::string const & type, std::string const & val, unsigned int const &num) const;
  void checkLimit(std::string const & type, std::string const & val, unsigned int const &num) const;
  bool match_nbr(const std::string &) const;
  void checkType(std::string const &, unsigned int const &) const;
  void checkArguments(std::istringstream &, std::string, unsigned int const &) const;
  void parse(Lexer &) const;
  void checkLine(std::string const &, unsigned int const &, Lexer &) const;
  Parser(std::string const &);
  ~Parser();
};

#endif
