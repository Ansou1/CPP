//
// Admiral.hh for admiral.hh in /home/daguen_s/rendu/piscine_cpp_d07m/ex04
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Tue Jan 14 15:34:37 2014 daguen_s
// Last update Tue Jan 14 21:17:32 2014 daguen_s
//

#ifndef _ADMIRAL_H_
# define _ADMIRAL_H_

#include <iostream>
#include <string>

namespace Federation
{
    namespace Starfleet
    {
      class Admiral;
    }
}

#include "Borg.hh"
#include "Federation.hh"
#include "Warpsystem.hh"

namespace Federation
{
  namespace Starfleet
  {
    class Admiral
    {
      std::string		_name;

    public:
      Admiral(std::string name);
      ~Admiral();

      bool		(Federation::Starfleet::Ship::*movePtr)(Destination);
      void		(Federation::Starfleet::Ship::*firePtr)(Borg::Ship*);

      void		fire(Federation::Starfleet::Ship*, Borg::Ship*);
      bool		move(Federation::Starfleet::Ship*, Destination);
    };
  }
}

#endif /* _ADMIRAL_H_ */
