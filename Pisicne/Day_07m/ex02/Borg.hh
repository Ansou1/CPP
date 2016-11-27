//
// Borg.hh for borg in /home/daguen_s/rendu/piscine_cpp_d07m/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Tue Jan 14 11:20:56 2014 daguen_s
// Last update Tue Jan 14 13:24:10 2014 daguen_s
//

#ifndef _BORG_H_
# define _BORG_H_

#include "Warpsystem.hh"
#include "Destination.hh"

namespace Borg
{
  class Ship
  {
    int			_side;
    short		_maxWarp;
    WarpSystem::Core	*core;
    Destination		_location;
    Destination		_home;

  public:
    Ship();
    ~Ship();

    void		setupCore(WarpSystem::Core *);
    void		checkCore();

    bool		move(int warp, Destination d);
    bool		move(int warp);
    bool		move(Destination d);
    bool		move();
  };
}

#endif /* _BORG_H_ */
