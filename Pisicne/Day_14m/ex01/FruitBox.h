/*
** FruitBox.h for  in /home/daguen_s/rendu/piscine_cpp_d14m/ex00
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Tue Jan 21 09:45:55 2014 daguen_s
** Last update Tue Jan 21 10:04:43 2014 daguen_s
*/

#ifndef _FRUITBOX_H_
# define _FRUITBOX_H_

#include "Fruit.h"
#include "FruitNode.h"

class		FruitBox
{
 private:
  int		size;
  int		nbFruit;
  FruitNode	*head_node;

 public:
  FruitBox(int size);
  ~FruitBox();

  int		getSize() const;
  int		nbFruits() const;

  void		setHead(FruitNode *h);

  bool		putFruit(Fruit* f);
  Fruit*	pickFruit();
  FruitNode*	head() const;
};

#endif /* _FRUITBOX_H_ */
