/*
** String.h for String in /home/daguen_s/rendu/piscine_cpp_d03/ex00
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Fri Jan 10 06:04:56 2014 daguen_s
** Last update Fri Jan 10 07:28:28 2014 daguen_s
*/

#ifndef _STRING_H_
# define _STRING_H_

typedef struct	String
{
  char		*str;

  void		(*assign_s)(struct String *this, struct String const * str);
  void		(*assign_c)(struct String *this, char const * s );
}		String;

void StringInit(struct String* this, char const * s);
void StringDestroy(struct String* this);

#endif /* _STRING_H_ */
