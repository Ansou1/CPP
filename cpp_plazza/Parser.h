#ifndef PARSER
#define PARSER

#include	<string>
#include	<sstream>
#include	<iostream>
#include	<map>
#include	<list>
#include	"Plazza.hh"

class Parser
{
private:
	std::list<std::string *> command;

public:
	Parser();
	~Parser();
	void	parse(const std::string &commande);
	std::string *get_command(void);
	unsigned int getSize(void) const;
	void commands(const std::string &commande);
};
#endif