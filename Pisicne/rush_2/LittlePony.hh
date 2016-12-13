//
// LittlePony.hh for  in /home/daguen_s/rendu/rush2
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sun Jan 19 01:09:20 2014 daguen_s
// Last update Sun Jan 19 06:08:16 2014 daguen_s
//


#ifndef _LITTLEPONY_H_
# define _LITTLEPONY_H_


#include "Toy.hh"

class LittlePony : public Toy
{
public:
  LittlePony(std::string const&);
  virtual ~LittlePony();
  LittlePony(LittlePony &);

  void			operator=(LittlePony &);

  virtual void		isTaken() const;
};


#endif /* _LITTLEPONY_H_ */
