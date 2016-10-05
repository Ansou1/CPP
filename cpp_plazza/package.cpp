#include	"package.hh"

Package::Package()
{
  pizza["Margarita"] = 1;
  pizza["Regina"] = 2;
  pizza["Americana"] = 4;
  pizza["Fantasia"] = 8;
  size["S"] = 1;
  size["M"] = 2;
  size["L"] = 4;
  size["XL"] = 8;
  size["XXL"] = 16;
}

int str_to_nbr(const std::string &n)
{
  std::stringstream concat;
  int tmp;

  concat << n;
  concat >> tmp;
  return (tmp);
}

std::string Package::pack_fridge(const Fridge &f) const{
  std::string *ret = new std::string;

  *ret = FRIDGE;
  *ret += "," + SSTR(f.pasta) + "," + SSTR(f.tomato) + "," + SSTR(f.swiss_cheese) + "," + SSTR(f.ham) + "," + SSTR(f.mushroom) + "," + SSTR(f.steak) + "," + SSTR(f.goat_cheese) + "," + SSTR(f.eggplant);
  return (*ret);
}

Package::Package(const Package &old)
{
  this->pizza = old.pizza;
}

Package::~Package()
{
}

std::string &Package::getstrtype_pizza(const TypePizza pizza) const
{
  std::map<std::string, int>::const_iterator it = this->pizza.begin();
  std::string *ret = new std::string;

  while ((*it).second != pizza)
    ++it;
  *ret = (*it).first;
  return *ret;
}

std::string &Package::getstrtype_size(const TaillePizza size) const
{
  std::map<std::string, int>::const_iterator it = this->size.begin();
  std::string *ret = new std::string;

  while ((*it).second != size)
    ++it;
  *ret = (*it).first;
  return *ret;
}

std::string &Package::getCommandByType(const TypePizza pizza, const TaillePizza size) const{
  std::string *ret = new std::string;

  *ret = COMMAND;
  *ret += "," + getstrtype_pizza(pizza) + "," + getstrtype_size(size);
  return (*ret);
}

Task *Package::unpackCommand(std::string str)
{
  Task *ret = new Task;
  int p1 = str.find(" ", 0);

  std::string t = str.substr(0, p1);
  std::string s = str.substr(p1 + 1, str.size() - p1 - 1);
  std::map<std::string, int>::iterator it = this->pizza.begin();
   std::map<std::string, int>::iterator it2 = this->size.begin();
  while ((*it).first != t) ++it;
  while ((*it2).first != s) ++it2;

  ret->size = (TaillePizza)((*it).second);
  ret->type = (TypePizza)((*it2).second);
  return (ret);
}

std::string &Package::packCook()
{
  std::string *ret = new std::string;

  *ret = START_COOK;
  return (*ret);
}

void Package::unpack(const std::string &str, Fridge **f, std::string **s, bool &cook_start)
{
  int p1 = 0;
  int p2 = 0;

  if (str[0] == FRIDGE){
    *f = new Fridge;
    p1 = p2 = 2;
    p2 = str.find(",", p1);
    (*f)->pasta = str_to_nbr(str.substr(p1, p2 - p1));
    p1 = p2;
    p2 = str.find(",", p1);
    (*f)->tomato = str_to_nbr(str.substr(p1, p2 - p1));
    p1 = p2;
    p2 = str.find(",", p1);
    (*f)->swiss_cheese = str_to_nbr(str.substr(p1, p2 - p1));
    p1 = p2;
    p2 = str.find(",", p1);
    (*f)->ham = str_to_nbr(str.substr(p1, p2 - p1));
    p1 = p2;
    p2 = str.find(",", p1);
    (*f)->mushroom = str_to_nbr(str.substr(p1, p2 - p1));
    p1 = p2;
    p2 = str.find(",", p1);
    (*f)->steak = str_to_nbr(str.substr(p1, p2 - p1));
    p1 = p2;
    p2 = str.find(",", p1);
    (*f)->goat_cheese = str_to_nbr(str.substr(p1, p2 - p1));
    p1 = p2;
    p2 = str.find(",", p1);
    (*f)->eggplant = str_to_nbr(str.substr(p1, p2 - p1));
  }
  else if (str[0] == START_COOK){
    *s = new std::string;
    **s = str.substr(2, str.size() - 2);
  }
  else{
    cook_start = true;
  }
}