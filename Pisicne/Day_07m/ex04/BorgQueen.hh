//
// BorgQueen.hh for BorgQueen.hh in /home/daguen_s/rendu/piscine_cpp_d07m/ex04
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Tue Jan 14 16:13:06 2014 daguen_s
// Last update Tue Jan 14 17:48:06 2014 daguen_s
//

#ifndef _BORGQUEEN_H_
# define _BORGQUEEN_H_

#include <iostream>
#include <string>

namespace Borg
{
  class BorgQueen;
}

#include "Borg.hh"
#include "Federation.hh"
#include "Warpsystem.hh"

namespace Borg
{
  class BorgQueen
  {
  public:
    BorgQueen();
    ~BorgQueen();

    bool		(Borg::Ship::*movePtr)(Destination);
    void		(Borg::Ship::*firePtr)(Federation::Starfleet::Ship*);
    void		(Borg::Ship::*destroyPtr)(Federation::Ship*);

    bool		move(Borg::Ship*, Destination);
    void		fire(Borg::Ship*, Federation::Starfleet::Ship*);
    void		destroy(Borg::Ship*, Federation::Ship*);
  };
}

#endif /* _BORGQUEEN_H_ */
