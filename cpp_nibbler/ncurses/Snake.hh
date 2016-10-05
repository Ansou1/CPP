/*
** Snake.h for  in /home/daguen_s/rendu/cpp_nibbler/ncurses
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Mon Mar 31 08:39:11 2014 daguen_s
// Last update Fri Apr  4 15:16:09 2014 daguen_s
*/

#ifndef _SNAKE_H_
# define _SNAKE_H_

#include <map>
#include <ncurses.h>
#include "../displaymodule.h"

class Snake : public IDisplayModule
{
public:
  typedef void (Snake::*draw)() const;

private:
  coord				size;
  std::map<int, e_key>		key;
  std::map<int, draw>		print_tab;

public:
  virtual void		aff(const std::vector<std::string> &, const unsigned int &score, const float &speed);
  void			init(const coord &size);
  virtual e_key		getKey(void) const;
  virtual		~Snake();
  Snake();
  Snake(const Snake &);
  Snake			&operator=(const Snake &);

  void			wall() const;
  void			snake() const;
  void			fruit() const;
  void			head() const;
  void			tail() const;
  void			empty() const;
};

#endif /* _SNAKE_H_ */
