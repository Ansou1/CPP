//
// main.cpp for  in /home/daguen_s/rendu/cpp_abstractvm
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Wed Feb 26 13:52:59 2014 daguen_s
// Last update Sun Mar  2 08:52:30 2014 daguen_s
//

#include "Parser.hh"
#include "Executor.hh"

std::string     setFilename()
{
  time_t        date;
  struct tm     timeInfo;
  char          filename[32];
  std::string   name;

  time(&date);
  timeInfo = *localtime(&date);
  strftime(filename, 32, "%Y-%m-%d_%Hh%Mm%S", &timeInfo);
  name.assign(filename);
  name.append(".avm");
  return (name);
}

bool            reading(std::string const &filename)
{
  std::string   line = "";
  std::fstream  file;
  bool		test = true;

  file.open(filename.c_str(), std::fstream::out | std::fstream::trunc);
  if (file.is_open() && file.good())
    {
      while (line.compare(";;") && test)
	{
          file << line << std::endl;
	  getline(std::cin, line);
	  if (std::cin.eof() == 1)
	    test = false;
	}
      file.close();
      return (true);
    }
  return (false);
}

int main(const int ac, char const * const *av)
{
  std::string   filename;

  if (ac == 1)
    {
      filename = setFilename();
      if (!reading(filename))
	std::cerr << "Error while opening file." << std::endl;
    }
  else if (ac == 2)
    filename.assign(av[1]);
  else
    {
      std::cerr << "Usage: ./avm [file_name]" << std::endl;
      return 0;
    }
  try
    {
      Parser p(filename);
      Lexer l;
      p.parse(l);
      if (!l.getExit())
	throw exception_syntax("End of file reach whithout instruction exit");
      Executor e(l);
      e.execute();
    }
  catch(const std::exception & e)
    {
      std::cerr << e.what() << std::endl;
    }
  return 0;
}



