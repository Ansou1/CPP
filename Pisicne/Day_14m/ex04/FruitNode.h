/*
** FruitNode.h for  in /home/daguen_s/rendu/piscine_cpp_d14m/ex00
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Tue Jan 21 09:33:49 2014 daguen_s
** Last update Tue Jan 21 10:05:24 2014 daguen_s
*/

#ifndef __FRUITNODE_H__
#define __FRUITNODE_H__

#include "Fruit.h"

typedef struct		FruitNode
{
  Fruit		*f;
  FruitNode	*next;
} FruitNode;

#endif
