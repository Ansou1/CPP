/*
** String.h for String in /home/daguen_s/rendu/piscine_cpp_d03/ex00
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Fri Jan 10 06:04:56 2014 daguen_s
** Last update Fri Jan 10 06:26:29 2014 daguen_s
*/

#ifndef _STRING_H_
# define _STRING_H_

typedef struct	String
{
  char *str;
}		String;

void StringInit(struct String* this, char const * s);
void StringDestroy(struct String* this);

#endif /* _STRING_H_ */
