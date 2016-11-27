//
// Borg.hh for borg in /home/daguen_s/rendu/piscine_cpp_d07m/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Tue Jan 14 11:20:56 2014 daguen_s
// Last update Tue Jan 14 15:13:41 2014 daguen_s
//

#ifndef _BORG_H_
# define _BORG_H_

#include "Warpsystem.hh"
#include "Destination.hh"
#include "Federation.hh"

namespace Federation
{
    namespace Starfleet
    {
      class Ensign;
      class Captain;
      class Ship;
    }
  class Ship;
}

namespace Borg
{
  class Ship
  {
    int			_side;
    short		_maxWarp;
    WarpSystem::Core	*core;
    Destination		_location;
    Destination		_home;
    int			_shield;
    int			_weaponFrequency;
    short		_repair;

  public:
    Ship(int wF, short repair = 3);
    ~Ship();

    void		setupCore(WarpSystem::Core *);
    void		checkCore();

    bool		move(int warp, Destination d);
    bool		move(int warp);
    bool		move(Destination d);
    bool		move();

    int			getShield();
    void		setShield(int);
    int			getWeaponFrequency();
    void		setWeaponFrequency(int);
    short		getRepair();
    void		setRepair(short);

    void		fire(Federation::Starfleet::Ship*);
    void		fire(Federation::Ship*);
    void		repair();
  };
}

#endif /* _BORG_H_ */
