#include "Plazza.hh"
#include "gui.hh"

float                   str_to_float(std::string const &str){
  std::istringstream    buffer(str);
  float                 stock;

  buffer >> stock;
  return stock;
}

int                  str_to_int(std::string const &str){
  std::istringstream    buffer(str);
  int                 stock;

  buffer >> stock;
  return stock;
}

int main(int ac, char const *av[])
{
  float multiplier;
  int cook_per_kitchen;
  int time;
  std::string s;

  if (ac != 4){
    std::cerr << "USAGE: ./plazza [multiplier >= 0] [number of cooks > 0] [time ingredients >= 0]" << std::endl;
    return (1);
  }
  Gui g;
  multiplier = str_to_float(av[1]);
  cook_per_kitchen = str_to_int(av[2]);
  time = str_to_int(av[3]);
  Manage_kitchen acceuil(cook_per_kitchen, multiplier, time);
  while (1)
    {
      s = g.get_input();
      usleep(1000);
      std::cout << "e" << "\r\n";
      g.reload(acceuil);
      if (s != "")
	acceuil.add_command(s);
      if (s == "quit")
	return (0);
    }
  return 0;
}
