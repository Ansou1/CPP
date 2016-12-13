//
// Teddy.hh for  in /home/daguen_s/rendu/rush2
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sun Jan 19 01:36:38 2014 daguen_s
// Last update Sun Jan 19 06:17:56 2014 daguen_s
//

#include "Toy.hh"

class Teddy : public Toy
{
public:
  Teddy(std::string const& name);
  virtual ~Teddy();
  Teddy(Teddy &);

  void			operator=(Teddy &);

  virtual void		isTaken() const;
};
