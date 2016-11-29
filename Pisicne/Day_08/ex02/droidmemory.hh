//
// droidmemory.hh for droidmemory.hh in /home/daguen_s/rendu/piscine_cpp_d08/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Wed Jan 15 12:50:30 2014 daguen_s
// Last update Wed Jan 15 15:32:24 2014 daguen_s
//

#ifndef _DROIDMEMORY_H_
# define _DROIDMEMORY_H_

#include <string>
#include <iostream>

class DroidMemory
{
  size_t	FingerPrint;
  size_t	Exp;

public:
    DroidMemory();
    DroidMemory(DroidMemory const &src);
    ~DroidMemory();

  void		setFingerPrint(size_t);
  void		setExp(size_t);

  size_t	getFingerPrint() const;
  size_t	getExp() const;

  DroidMemory	&operator<<(DroidMemory const &src);
  DroidMemory	&operator>>(DroidMemory &src);
  DroidMemory	&operator+=(DroidMemory const &src);
  DroidMemory	&operator+=(size_t const &src);
  DroidMemory	&operator+(DroidMemory const &src) const;
  DroidMemory	&operator+(size_t const &src) const;

  bool		operator!=(DroidMemory const &src) const;
  bool		operator==(DroidMemory const &src) const;

  bool		operator<(DroidMemory const &src) const;
  bool		operator>(DroidMemory const &src) const;
  bool		operator<=(DroidMemory const &src) const;
  bool		operator>=(DroidMemory const &src) const;

  bool		operator<(size_t const &src) const;
  bool		operator>(size_t const &src) const;
  bool		operator<=(size_t const &src) const;
  bool		operator>=(size_t const &src) const;
};

std::ostream	&operator<<(std::ostream &os, DroidMemory const &src);

#endif /* _DROIDMEMORY_H_ */
