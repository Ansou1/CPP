/*
** Exo-1.h for Exo-1.h in /home/daguen_s/rendu/piscine_cpp_d09/ex-1
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Thu Jan 16 18:39:15 2014 daguen_s
** Last update Thu Jan 16 19:29:14 2014 daguen_s
*/

#ifndef _EXO1_H_
# define _EXO1_H_

typedef struct	s_cthulhu
{
  int		m_power;
  char		*m_name;
}		t_cthulhu;

typedef struct	s_koala
{
  t_cthulhu	m_parent;
  char		m_isALegend;
}		t_koala;

t_cthulhu	*NewCthulhu();
void		PrintPower(t_cthulhu *this);
void		Attack(t_cthulhu *this);
void		Sleeping(t_cthulhu *this);

t_koala		*NewKoala(char* name, char _isALegend);
void		Eat(t_koala* this);
static void	KoalaInitializer(t_koala* this, char* _name, char _isALegend);
static void	CthulhuInitializer(t_cthulhu* this);

#endif /* _EXO-1_H_ */
