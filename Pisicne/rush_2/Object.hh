//
// Objet.hh for  in /home/daguen_s/rendu/rush2
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sun Jan 19 01:12:47 2014 daguen_s
// Last update Sun Jan 19 09:47:23 2014 daguen_s
//

#ifndef _OBJECT_H_
# define _OBJECT_H_

# include	<string>
# include	<ostream>

typedef enum {LITTLEPONY, TEDDY, BOX, GIFTPAPER, UNKNOW} e_type;

class Object
{
public:
  e_type		type;
  std::string const	name;
  bool open;
  Object *content;
public:
  Object(std::string const & name = "bob", e_type type = UNKNOW);
  Object(Object &);
  virtual ~Object();

  virtual void		isTaken() const = 0;
  virtual bool		wrapMeThat(Object *) = 0;
  virtual Object	*openMe();
  virtual void		closeMe() = 0;
  std::string const	&getName() const;
  e_type		getType() const;

  void			operator=(Object &);
};

std::ostream &	operator<<(std::ostream &, Object *);

#endif /* _OBJECT_H_ */
