//
// cpuinfo.hpp for cpuinfo in /home/falcon_j/piscine_cpp_rush3
//
// Made by jeremy falconnier
// Login   <falcon_j@epitech.net>
//
// Started on  Sat Jan 25 13:44:39 2014 jeremy falconnier
// Last update Sat Jan 25 19:39:35 2014 daguen_s
//

#ifndef	__CPUINFO_HPP__
#define	__CPUINFO_HPP__

#include	<vector>
#include	<sstream>
#include	<iostream>
#include	<string>
#include	"Machine.hh"

class	Cpu
{
protected:
  double	_pourc;
  std::string	_name;
  std::string	_mhZ;

public:
  Cpu(const std::string &, const std::string &, double);
  ~Cpu();
  void setPourc(double);
  void setCpumhz(const std::string &);
  const	std::string &getMhz() const;
  double	getPourc() const;
  std::string getName() const;
};

class CpuInfo : public Machine
{
protected:
  int			nb;
  std::vector<Cpu>	lcpu;
  std::string		_model;
public:
  CpuInfo();
  ~CpuInfo();
  double calc(std::string ) const;
  const std::vector<double> &getveccpu() const;
  void	setModel(const std::string &);
  void	setLcpu(const std::vector<Cpu> &);
  int	getNb() const;
  const std::vector<Cpu>	&getLcpu() const;
  const std::string	&getModel() const;
  void	update();
};


#endif
