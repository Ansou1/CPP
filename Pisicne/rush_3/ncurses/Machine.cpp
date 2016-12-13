#include "Machine.hh"
#include <unistd.h>
#include <sstream>

Machine::Machine(){
  init();
}

void Machine::init(){
  char host[32];
  FILE *f;
  char buff[256];

  gethostname(host, 32);
  this->_name = host;
  f = popen("whoami", "r");
  fgets(buff, sizeof(buff), f);
  pclose(f);
  this->_uname = buff;
  f = popen("date", "r");
  fgets(buff, sizeof(buff), f);
  pclose(f);
  this->_date = buff;
  this->_current_battery = get_info("/proc/acpi/battery/BAT0/state", "remaining capacity");
  this->_present_battery = get_info("/proc/acpi/battery/BAT0/state", "charging state");
  this->_full_battery = get_info("/proc/acpi/battery/BAT0/info", "last full capacity");
  std::ostringstream tmp;
  tmp << ((std::stoi(_current_battery) * 100)/ std::stoi(_full_battery));
  this->_percent = tmp.str() + " %";
  std::ifstream file("/proc/version");
  getline(file, this->_kernel);
  size_t i = 0;
  if ((i = (this->_kernel.find("(") - 1)) != std::string::npos)
    this->_kernel = this->_kernel.substr(0, i);
  else
    this->_kernel = "This kernel is not found!!!";
}

std::string Machine::get_info(std::string const &file, std::string const &to_find) const
{
  std::string str =  "";
  std::ifstream fichier(file.c_str());
  std::string line;
  unsigned int	a = 1;

  if (fichier)
    {
      while (getline(fichier, line))
	{
	  if (line.compare(0, to_find.size(), to_find) == 0)
	    {
	      a += line.find(":");
	      str = line.substr(a, line.size() - 1);
	      a = 0;
	      while (str.c_str()[a++] == ' ' || str.c_str()[a] == '\t');
	      a--;
	      str = str.substr(a, str.size());
	      return (str);
	    }
	}
    }
  return (str);

}

std::vector<std::string>	&Machine::search_value(const std::string &file_name, const std::string &to_find) const
{
  std::ifstream			fichier(file_name.c_str());
  std::vector<std::string>	*t = new std::vector<std::string>();

  if (fichier)
    {
      std::string		line;
      std::string		str;
      unsigned int		a = 1;

      while (getline(fichier, line))
	{
	  if (line.compare(0, to_find.size(), to_find) == 0)
	    {
	      a = 1;
	      a += line.find(":");
	      while (line.c_str()[a++] == ' ' || line.c_str()[a] == '\t');
	      a--;
	      str = line.substr(a, line.size());
	      t->push_back(str);
	    }
	}
      fichier.close();
    }
  else
    std::cerr << "File: <" << file_name << ">: " << strerror(errno) << std::endl;
  return *t;
}


std::string		Machine::getName() const
{
  return this->_name;
}

std::string		Machine::getUname() const
{
  return this->_uname;
}

std::string		Machine::getDate() const
{
  return this->_date;
}

std::string		Machine::getCurrent_Battery() const
{
  return this->_current_battery;
}

std::string		Machine::getFull_Battery() const
{
  return this->_full_battery;
}

std::string		Machine::getPresent_Battery() const
{
  return this->_present_battery;
}

std::string		Machine::getKernel() const
{
  return this->_kernel;
}

std::string		Machine::getPer() const
{
  return this->_percent;
}

void			Machine::setPer()
{
  std::ostringstream tmp;
  tmp << ((std::stoi(_current_battery) * 100)/ std::stoi(_full_battery));
  this->_percent = tmp.str() + " %";
}

void			Machine::setPresentBaterry()
{
  this->_present_battery = get_info("/proc/acpi/battery/BAT0/state", "charging state");
}

void			Machine::setCurrentBaterry()
{
  this->_current_battery = get_info("/proc/acpi/battery/BAT0/state", "remaining capacity");
}

void			Machine::setFullBaterry()
{
  this->_full_battery = get_info("/proc/acpi/battery/BAT0/info", "last full capacity");
}

void			Machine::update()
{
  setPer();
  setPresentBaterry();
  setFullBaterry();
  setCurrentBaterry();
  init();
}
