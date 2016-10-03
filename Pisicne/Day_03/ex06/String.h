/*
** String.h for String in /home/daguen_s/rendu/piscine_cpp_d03/ex00
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Fri Jan 10 06:04:56 2014 daguen_s
** Last update Fri Jan 10 08:43:35 2014 daguen_s
*/

#ifndef _STRING_H_
# define _STRING_H_

typedef struct	String
{
  char		*str;

  void		(*assign_s)(struct String *this, struct String const * str);
  void		(*assign_c)(struct String *this, char const * s );
  void		(*append_s)(struct String* this, struct String const* ap);
  void		(*append_c)(struct String* this, char const* ap);
  char		(*at)(struct String* this, size_t pos);
  void		(*clear)(struct String* this);
  int		(*size)(struct String* this);
  int		(*compare_s)(struct String *this, const struct String* str);
  int		(*compare_c)(struct String *this, char const* str);
}		String;

void StringInit(struct String* this, char const * s);
void StringDestroy(struct String* this);

#endif /* _STRING_H_ */
