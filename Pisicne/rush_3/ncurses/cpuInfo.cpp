//
// cpuInfo.cpp for cpuinfo in /home/falcon_j/piscine_cpp_rush3
//
// Made by jeremy falconnier
// Login   <falcon_j@epitech.net>
//
// Started on  Sat Jan 25 14:00:04 2014 jeremy falconnier
// Last update Sun Jan 26 09:07:24 2014 daguen_s
//

#include	"Machine.hh"
#include	"cpuinfo.hh"


///////////////////////////////// classe CPU ///////////////////////////////////////////////


/////////////////constructeur

Cpu::Cpu(const std::string &name, const std::string &mhz, double pourc)
{
  this->_name = name;
  this->_pourc = pourc;
  this->_mhZ = mhz;
}

Cpu::~Cpu()
{

}


//////////////// methode get et set

void	Cpu::setPourc(double toset)
{
  this->_pourc = toset;
}

void	Cpu::setCpumhz(const std::string &mhz)
{
  this->_mhZ = mhz;
}

double	Cpu::getPourc() const
{
  return (this->_pourc);
}

const	std::string &Cpu::getMhz() const
{
  return (this->_mhZ);
}

const std::string &Cpu::getName() const
{
  return (this->_name);
}



///////////////////////////////// classe CPUINFO ///////////////////////////////////////////


////////////////constructeur

CpuInfo::CpuInfo()
{
std::vector<std::string> nproc;
  std::vector<std::string> cpumhz;
  std::vector<double> pourc;
  unsigned int	a = 0;
  std::string file = "/proc/cpuinfo";
  std::string tosearch;

  tosearch = "processor";
  nproc = search_value(file, tosearch);
  tosearch = "cpu MHz";
  cpumhz = search_value(file, tosearch);
  tosearch = "model name";
  this->_model = get_info(file, tosearch);
  this->nb = nproc.size();
  pourc = this->getveccpu();
  while (a < nproc.size())
    {
      this->lcpu.push_back(Cpu(nproc[a], cpumhz[a], pourc[a]));
      a++;
    }
}


////////////////destructeur

CpuInfo::~CpuInfo()
{

}


/////////////////fonctions de calcul

double CpuInfo::calc(std::string str) const
{
  double res = 0;
  size_t pos = 0;
  std::vector<int> token;

  while ((pos = str.find(" ")) != std::string::npos)
    {
      std::stringstream ss(str.substr(0, pos));
      int tmp;
      ss >> tmp;
      token.push_back(tmp);
      str.erase(0, pos + 1);
    }

  for (unsigned int i = 0; i < token.size(); i++)
    {
      res += token[i];
    }
  return (res);
}

const std::vector<double> &CpuInfo::getveccpu() const
{
  std::string my_info;
  int	a = 0;
  std::string b = "0";
  double	util;
  std::vector<double>	*t = new std::vector<double>();

  my_info = get_info("/proc/stat", "cpu");
  double total = this->calc(my_info);
  while (a <= this->nb)
    {
      my_info = get_info("/proc/stat", "cpu" + b);
      a++;
      b[0] = b[0] + 1;
      util = this->calc(my_info);
      t->push_back(util / total * 100);
    }
  return (*t);
}


/////////////////////update de lobjet pour ne pas construire detruire en boucle

void	CpuInfo::update()
{
  int	a = 0;
  std::vector<std::string> nproc;
  std::vector<std::string> cpumhz;
  std::vector<double> pourc;

  nproc = this->search_value("/proc/cpuinfo", "processor");
  cpumhz = this->search_value("/proc/cpuinfo", "cpu MHz");
  this->_model = get_info("/proc/cpuinfo", "model name");
  pourc = this->getveccpu();
  this->lcpu.clear();
  while (a < this->nb)
    {
      this->lcpu[a].setPourc(pourc[a]);
      this->lcpu[a].setCpumhz(cpumhz[a]);
      a++;
    }
}


///////////////////// methode get et set

int	CpuInfo::getNb() const
{
  return (this->nb);
}

const std::vector<Cpu>	&CpuInfo::getLcpu() const
{
  return (this->lcpu);
}

const std::string	&CpuInfo::getModel() const
{
  return (this->_model);
}
