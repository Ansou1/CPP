/*
** Toy.h for  in /home/daguen_s/rendu/piscine_cpp_d13/ex00
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Mon Jan 20 09:05:27 2014 daguen_s
** Last update Mon Jan 20 21:18:59 2014 daguen_s
*/

#ifndef _TOY_H_
# define _TOY_H_

#include "Picture.h"

class Toy
{
 public:
  enum ToyType {BASIC_TOY, ALIEN, BUZZ, WOODY};

  class Error
  {
  public:
    enum ErrorType {UNKNOWN, PICTURE, SPEAK};

    ErrorType	type;

    Error();
    ~Error();

    void		setType(ErrorType);
    std::string		what() const;
    std::string		where() const;
  };

 private:
  ToyType		type;
  std::string		name;
  Picture		image;
  Error			erreur;

 public:
  Toy();
  Toy(ToyType type, const std::string & name, const std::string & file);
  Toy(const Toy &);
  ~Toy();

  int			getType() const;
  std::string		getName() const;
  std::string		getAscii() const;

  void			setName(const std::string &name);
  bool			setAscii(const std::string &file);

  Toy			&operator=(Toy const &);

  virtual bool		speak(const std::string &);
  virtual bool		speak_es(const std::string &);

  Toy			&operator<<(const std::string &);
  Toy::Error		getLastError()const;
};

std::ostream		&operator<<(std::ostream &, const Toy &);

#endif /* _TOY_H_ */
