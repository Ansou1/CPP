//
// Wrap.hh for  in /home/daguen_s/rendu/rush2
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sun Jan 19 01:19:04 2014 daguen_s
// Last update Sun Jan 19 06:29:01 2014 daguen_s
//

#ifndef _WRAP_H_
# define _WRAP_H_

# include	"Object.hh"

class	Wrap : public Object
{
protected:
  Object		*content;
public:
  Wrap(std::string const &, e_type);
  Wrap(Wrap &);
  ~Wrap();

  void			operator=(Wrap &);
  virtual void		isTaken() const;
  virtual bool		wrapMeThat(Object *);
  virtual Object *	openMe();
};

#endif /* _WRAP_H_ */
