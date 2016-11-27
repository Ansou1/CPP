//
// Federation.hh for Federation.hh in /home/daguen_s/rendu/piscine_cpp_d07m/ex00
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Tue Jan 14 09:06:16 2014 daguen_s
// Last update Tue Jan 14 13:52:55 2014 daguen_s
//

#ifndef _FEDERATION_H_
# define _FEDERATION_H_

#include <string>
#include "Warpsystem.hh"

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

    public:
      Ship(int length, int width, std::string name, short maxWarp);
        ~Ship();

      void		setupCore(WarpSystem::Core *core);
      void		checkCore();
      void		promote(Captain *);
    };

  }

    class Ship
    {
      int		_length;
      int		_width;
      std::string	_name;
      short		_maxWarp;
      WarpSystem::Core	*core;

    public:
      Ship(int length, int width, std::string name);
      ~Ship();

      void		setupCore(WarpSystem::Core *core);
      void		checkCore();
    };
}

#endif /* _FEDERATION_H_ */


