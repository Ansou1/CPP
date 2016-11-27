//
// Federation.hh for Federation.hh in /home/daguen_s/rendu/piscine_cpp_d07m/ex00
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Tue Jan 14 09:06:16 2014 daguen_s
// Last update Tue Jan 14 15:26:35 2014 daguen_s
//

#ifndef _FEDERATION_H_
# define _FEDERATION_H_

#include <string>
#include "Warpsystem.hh"
#include "Destination.hh"
#include "Borg.hh"

namespace Borg
{
  class Ship;
}

namespace Federation
{
  namespace Starfleet
  {
    class Ensign
    {
      std::string	_name;

    public:
      Ensign(std::string name);
      ~Ensign();
    };

    class Captain
    {
      std::string	_name;
      int		_age;
    public:
      Captain(std::string name);
      ~Captain();

      std::string	getName();
      int		getAge();
      void		setAge(int age);
    };

    class Ship
    {
      int		_length;
      int		_width;
      std::string	_name;
      short		_maxWarp;
      WarpSystem::Core	*core;
      Captain		*captain;
      Destination	_location;
      Destination	_home;
      int		_shield;
      int		_photonTorpedo;

    public:
      Ship(int length = 289, int width = 132, std::string name = "Entreprise" , short maxWarp = 6, int torpedo = 20);
      ~Ship();

      void		setupCore(WarpSystem::Core *core);
      void		checkCore();
      void		promote(Captain *);

      bool		move(int warp, Destination d);
      bool		move(int warp);
      bool		move(Destination d);
      bool		move();

      int		getShield();
      void		setShield(int);
      int		getTorpedo();
      void		setTorpedo(int);

      void		fire(Borg::Ship*);
      void		fire(int torpedoes, Borg::Ship*);
    };

  }

    class Ship
    {
      int		_length;
      int		_width;
      std::string	_name;
      short		_maxWarp;
      WarpSystem::Core	*core;
      Destination	_location;
      Destination	_home;

    public:
      Ship(int length, int width, std::string name);
      ~Ship();

      void		setupCore(WarpSystem::Core *core);
      void		checkCore();

      bool		move(int warp, Destination d);
      bool		move(int warp);
      bool		move(Destination d);
      bool		move();

      WarpSystem::Core	*getCore();
    };
}

#endif /* _FEDERATION_H_ */


