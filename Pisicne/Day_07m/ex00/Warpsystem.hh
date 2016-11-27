//
// Warpsystem.hh for Warpsystem.hh in /home/daguen_s/rendu/piscine_cpp_d07m/ex00
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Tue Jan 14 10:32:14 2014 daguen_s
// Last update Tue Jan 14 10:37:57 2014 daguen_s
//

#ifndef _WARPSYSTEM_H_
# define _WARPSYSTEM_H_

#include <string>

namespace WarpSystem
{
  class QuantumReactor
  {
    bool		_stability;

  public:
      QuantumReactor();
      ~QuantumReactor();

    bool		isStable();
    void		setStability(bool);
  };

  class Core
  {
    QuantumReactor	*_coreReactor;

  public:
      Core(QuantumReactor *);
      ~Core();

    QuantumReactor	*checkReactor();
  };
}

#endif /* _WARPSYSTEM_H_ */
