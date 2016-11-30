/*
** Exo-1.c for Exo-1.c in /home/daguen_s/rendu/piscine_cpp_d09/ex-1
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Thu Jan 16 18:42:52 2014 daguen_s
** Last update Thu Jan 16 19:33:35 2014 daguen_s
*/

#include <stdlib.h>
#include <stdio.h>
#include "Exo-1.h"

char		*strdup(const char *s);

t_cthulhu	*NewCthulhu(void)
{
  t_cthulhu	*c;

  c = malloc(sizeof(t_cthulhu));
  CthulhuInitializer(c);
  return (c);
}

void		PrintPower(t_cthulhu *this)
{
  printf("Power => %d\n", this->m_power);
}

void		Attack(t_cthulhu *this)
{
  if (this->m_power >= 42)
    {
      this->m_power -= 42;
      printf("%s attacks and destroys the city\n", this->m_name);
    }
  else
    printf("%s can't attack, he doesn't have enough power\n", this->m_name);
}

void		Sleeping(t_cthulhu *this)
{
  this->m_power += 42000;
  printf("%s sleeps\n", this->m_name);
}

t_koala         *NewKoala(char* name, char _isALegend)
{
  t_koala	*k;

  k = malloc(sizeof(t_koala));
  KoalaInitializer(k, name, _isALegend);
  return (k);
}

void		Eat(t_koala *this)
{
  (this->m_parent).m_power += 42;
  printf("%s eats\n", (this->m_parent).m_name);
}


static void	CthulhuInitializer(t_cthulhu* this)
{
  this->m_name = strdup("Cthulhu");
  this->m_power = 42;
  printf("----\nBuilding Cthulhu\n");
}

static void	KoalaInitializer(t_koala* this, char* _name, char _isALegend)
{
  CthulhuInitializer(&this->m_parent);
  if (_name != NULL)
    this->m_parent.m_name = strdup(_name);
  else
    this->m_parent.m_name = NULL;
  this->m_isALegend = _isALegend;
  if (_isALegend == 0)
    this->m_parent.m_power = 0;
  printf("Building %s\n", _name);
}
