//
// Memory.cpp for  in /home/daguen_s/rendu/piscine_cpp_rush3
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sat Jan 25 13:50:44 2014 daguen_s
// Last update Sat Jan 25 21:39:30 2014 florian
//

#include "Memory.hh"

Memory::Memory()
{
  this->_memory_max = get_info("/proc/meminfo", "MemTotal");
  this->_memory_free = get_info("/proc/meminfo", "MemFree");
  this->_memory_swap = get_info("/proc/meminfo", "SwapTotal");
  this->_memory_cached = get_info("/proc/meminfo", "Cached");
}


Memory::Memory(const Memory &src)
{
  this->_memory_max = src._memory_max;
  this->_memory_free = src._memory_free;
  this->_memory_swap = src._memory_swap;
  this->_memory_cached = src._memory_cached;
}


Memory::~Memory()
{
}


Memory			&Memory::operator=(Memory const &src)
{
  this->_memory_max = src._memory_max;
  this->_memory_free = src._memory_free;
  this->_memory_swap = src._memory_swap;
  this->_memory_cached = src._memory_cached;
  return *this;
}


std::string	Memory::getM() const
{
  return this->_memory_max;
}

std::string	Memory::getF() const
{
  return this->_memory_free;
}

std::string	Memory::getS() const
{
  return this->_memory_swap;
}

std::string	Memory::getC() const
{
  return this->_memory_cached;
}

void		Memory::setM()
{
  this->_memory_max = get_info("/proc/meminfo", "MemTotal");
}

void		Memory::setF()
{
  this->_memory_free = get_info("/proc/meminfo", "MemFree");
}

void		Memory::setS()
{
  this->_memory_swap = get_info("/proc/meminfo", "SwapTotal");
}

void		Memory::setC()
{
  this->_memory_cached = get_info("/proc/meminfo", "Cached");
}

void		Memory::update()
{
  setM();
  setF();
  setS();
  setC();
}
