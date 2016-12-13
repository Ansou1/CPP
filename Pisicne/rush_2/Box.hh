//
// Box.hh for  in /home/daguen_s/rendu/rush2
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sun Jan 19 00:58:40 2014 daguen_s
// Last update Sun Jan 19 09:57:51 2014 daguen_s
//

#ifndef _BOX_H_
# define _BOX_H_

# include "Wrap.hh"

class Box : public Wrap
{
private:
  bool		opened;

public:
  Box();
  Box(Box &);
  ~Box();

  void			operator=(Box &);

  virtual bool		wrapMeThat(Object *);
  virtual Object*	openMe();
  virtual void		closeMe();
};

#endif /* _BOX_H_ */
