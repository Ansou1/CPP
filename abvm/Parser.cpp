//
// Parser.cpp for  in /home/daguen_s/rendu/cpp_abstractvm
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Wed Feb 26 13:58:42 2014 daguen_s
// Last update Sun Mar  2 12:25:40 2014 florian
//

#include "Parser.hh"

bool Parser::match_nbr(const std::string &nbr) const
{
  register unsigned int i = 0;
  int8_t c;
  int8_t point = 0;

  if (nbr.size() == 0)
    return false;
  c = nbr[0];
  if ((c >= '0' && c <= '9') || c == '-')
    ++i;
  else
    return false;
  while ((c = nbr[i]))
    {
      ++i;
      if (c == '.') ++point;
      if (!(c >= '0' && c <= '9') && (c != '.' || point > 1))
	return false;
    }
  return true;
}

bool Parser::match_nbr2(const std::string &nbr) const
{
  register unsigned int i = 0;
  int8_t c;

  if (nbr.size() == 0)
    return false;
  c = nbr[0];
  if ((c >= '0' && c <= '9') || c == '-')
    ++i;
  else
    return false;
  while ((c = nbr[i]))
    {
      ++i;
      if (!(c >= '0' && c <= '9'))
	return false;
    }
  return true;
}

template <>
void Parser::get_offset<float>(float &min, float &max) const
{
  max = std::numeric_limits<float>::max();
  min -= max;
}

template <>
void Parser::get_offset<double>(double &min, double &max) const
{
  max = std::numeric_limits<double>::max();
  min -= max;
}

template<>
std::string Parser::nbr_to_str<int8_t>(int8_t const &nbr) const
{
  std::ostringstream convert;
  std::string ret;

  convert << (int)nbr;
  ret = convert.str();
  return ret;
}

template<>
int8_t Parser::str_to_nbr<int8_t>(std::string const &value) const
{
  std::istringstream buffer(value);
  int stock;

  buffer >> stock;
  return (int8_t)stock;
}

void Parser::checkLimitint8(std::string const & type, std::string const & val, unsigned int const &num) const
{
  int8_t max, min;
  long comp = str_to_nbr<long>(val);

  if (!match_nbr2(val))
    throw exception_lexical(("Invalid number on " + type).c_str(), num);
  get_offset(min, max);
  if (comp > max)
    throw exception_lexical(("Overflow on " + type).c_str(), num);
  else if (comp < min)
    throw exception_lexical(("Underflow on " + type).c_str(), num);
}

void Parser::checkLimitint16(std::string const & type, std::string const & val, unsigned int const &num) const
{
  int16_t max, min;
  long comp = str_to_nbr<long>(val);

  if (!match_nbr2(val))
    throw exception_lexical(("Invalid number on " + type).c_str(), num);
  get_offset(min, max);
  if (comp > max)
    throw exception_lexical(("Overflow on " + type).c_str(), num);
  else if (comp < min)
    throw exception_lexical(("Underflow on " + type).c_str(), num);
}

void Parser::checkLimitint32(std::string const & type, std::string const & val, unsigned int const &num) const
{
  int32_t max, min;
  long comp = str_to_nbr<long>(val);

  if (!match_nbr2(val))
    throw exception_lexical(("Invalid number on " + type).c_str(), num);
  get_offset(min, max);
  if (comp > max)
    throw exception_lexical(("Overflow on " + type).c_str(), num);
  else if (comp < min)
    throw exception_lexical(("Underflow on " + type).c_str(), num);
}

void Parser::checkLimitfloat(std::string const & type, std::string const & val, unsigned int const &num) const
{
  float max, min;
  double comp = str_to_nbr<double>(val);

  get_offset(min, max);
  if (comp > max)
    throw exception_lexical(("Overflow on " + type).c_str(), num);
  else if (comp < min)
    throw exception_lexical(("Underflow on " + type).c_str(), num);
}

void Parser::checkLimitdouble(std::string const & type, std::string const & val, unsigned int const &num) const
{
  double max, min;
  double comp = str_to_nbr<double>(val);

  get_offset(min, max);
  if (comp >= max)
    throw exception_lexical(("Overflow on " + type).c_str(), num);
  else if (comp <= min)
    throw exception_lexical(("Underflow on " + type).c_str(), num);
}

void Parser::checkLimit(std::string const & type, std::string const & val, unsigned int const &num) const
{
  std::map<std::string, void (Parser::*)(std::string const &, std::string const &, unsigned int const &) const>::const_iterator it = this->_flow.find(type);
  (this->*(*it).second)(type, val, num);
}

void Parser::checkType(std::string const &str, unsigned int const &num) const
{
  if (!is_in(this->type.begin(), this->type.end(), str))
    throw exception_lexical("Unknown type", num);
}

void Parser::checkArguments(std::istringstream &split, std::string each, unsigned int const &num) const
{
  if (!getline(split, each, '('))
    throw exception_lexical("Missing open paranthesis", num);
  each.erase(each.find_last_not_of("\t ")+1).erase(0,each.erase(each.find_last_not_of("\t ")+1).find_first_not_of("\t "));
  const std::string type(each);
  checkType(each, num);
  if (!getline(split, each, ')'))
    throw exception_lexical("Missing closed paranthesis", num);
  const std::string nbr(each);
  if (!match_nbr(each))
    throw exception_lexical("Invalide number passed as parameter", num);
  checkLimit(type, nbr, num);
  while (getline(split, each, ' '));
}

bool Parser::cleanStr(std::string &clean) const
{
  size_t len = clean.find(';');
  if (len != std::string::npos)
    clean = clean.erase(len, clean.size() - len);
  if (!clean.size())
    return false;
  return true;
}

//check the grammar of the line
void Parser::checkLine(std::string const &line, unsigned int const &num, Lexer &l) const
{
  std::string each;
  std::string clean = line;

  if (!cleanStr(clean))
    return ;
  std::istringstream split(clean);
  std::getline(split, each, ' ');
  std::remove(each.begin(), each.end(), ' ');
  if (each == "push" || each == "assert")
    {
      checkArguments(split, each, num);
      l.getArguments(clean);
    }
  else if (!is_in(this->label.begin(), this->label.end(), each))
    throw exception_lexical("Unknown instruction", num);
  else
    {
      l.getInstructions(each);
    }
}

void Parser::parse(Lexer &l) const
{
  std::ifstream file(this->_fileName.c_str(), std::ios::in);
  unsigned int num = 0;
  std::vector<std::string> v;

  if (file)
    {
      std::string line;
      while (getline(file, line))
	{
	  ++num;
	  if (line.size() > 0 && line[0] != ';'){
	    std::replace(line.begin(), line.end(), '\t', ' ');
	    checkLine(line, num, l);
	  }
	}
    }
  else
    std::cout << " Error cannot open " << this->_fileName << std::endl;
}

Parser::Parser(std::string const &fileName) : VirtualMachine(), _fileName(fileName)
{
  this->_flow["int8"] = &Parser::checkLimitint8;
  this->_flow["int16"] = &Parser::checkLimitint16;
  this->_flow["int32"] = &Parser::checkLimitint32;
  this->_flow["float"] = &Parser::checkLimitfloat;
  this->_flow["double"] = &Parser::checkLimitdouble;
}

Parser::~Parser(){}

