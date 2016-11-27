/*
** KreogCom.h for kreocom in /home/daguen_s/rendu/piscine_cpp_d07a/ex02
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Wed Jan 15 01:16:40 2014 daguen_s
** Last update Wed Jan 15 02:12:53 2014 daguen_s
*/

#ifndef _KREOGCOM_H_
# define _KREOGCOM_H_

#include <string>
#include <iostream>

class KreogCom
{
int		m_serial;
int		my_x;
int		my_y;
KreogCom	*next;

public:
      KreogCom(int x, int y, int serial);
      ~KreogCom();

void		addCom(int x, int y, int serial);
KreogCom	*getCom();
void		removeCom();
void		ping() const;
void		locateSquad() const;
};

#endif /* _KREOGCOM_H_ */
