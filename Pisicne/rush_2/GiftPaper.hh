//
// GiftPaper.hh for  in /home/daguen_s/rendu/rush2
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sun Jan 19 01:06:43 2014 daguen_s
// Last update Sun Jan 19 06:05:02 2014 daguen_s
//

#ifndef _GIFTPAPER_H_
# define _GIFTPAPER_H_

# include "Wrap.hh"

class GiftPaper : public Wrap
{
public:
  GiftPaper();
  GiftPaper(GiftPaper &);
  ~GiftPaper();

  void			operator=(GiftPaper &);
  virtual void		closeMe();
  Object		*openMe();
};


#endif /* _GIFTPAPER_H_ */
