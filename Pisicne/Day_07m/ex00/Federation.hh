//
// Federation.hh for Federation.hh in /home/daguen_s/rendu/piscine_cpp_d07m/ex00
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Tue Jan 14 09:06:16 2014 daguen_s
// Last update Tue Jan 14 11:06:58 2014 daguen_s
//

#ifndef _FEDERATION_H_
# define _FEDERATION_H_

#include <string>
#include "Warpsystem.hh"

namespace Federation
{
  namespace Starfleet
  {
    class Ship
    {
      int		_length;
      int		_width;
      std::string	_name;
      short		_maxWarp;
      WarpSystem::Core	*core;

    public:
      Ship(int length, int width, std::string name, short maxWarp);
        ~Ship();

      void		setupCore(WarpSystem::Core *core);
      void		checkCore();
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


