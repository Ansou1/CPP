//
// BF_Translator.cpp for  in /home/daguen_s/rendu/piscine_cpp_d16/ex03
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Thu Jan 23 19:41:25 2014 daguen_s
// Last update Thu Jan 23 21:54:41 2014 daguen_s
//

#include "BF_Translator.h"

BF_Translator::BF_Translator()
{
  commands['+'] = "memory[cursor]++;\n";
  commands['-'] = "memory[cursor]--;\n";
  commands['>'] = "cursor++;\n";
  commands['<'] = "cursor--;\n";
  commands['.'] = "write(1, &memory[cursor], 1);\n";
  commands[','] = "read(0, &memory[cursor], 1);\n";
  commands['['] = "while (memory[cursor]) {\n";
  commands[']'] = "}\n";
}

BF_Translator::~BF_Translator()
{
}

int			BF_Translator::translate(std::string in, std::string out)
{
  std::ifstream		my_in(in.c_str());
  std::ofstream		my_out(out.c_str());

  if (!my_in.is_open() || !my_out.is_open())
    return 1;
  if (!my_in.good() || !my_out.good())
    return 1;
  my_out << "#include <stdlib.h>\n#include <string.h>\n#define MEMORY_MAX 60*1024\n\nint main() {\n char memory[MEMORY_MAX];\n unsigned int cursor = 0;\nmemset(memory, 0, MEMORY_MAX);\n\n";
  while (!my_in.eof())
    {
      char c = my_in.get();
      my_out << commands[c];
    }
  my_out << "}\n";
  my_in.close();
  my_out.close();
  return 0;
}
