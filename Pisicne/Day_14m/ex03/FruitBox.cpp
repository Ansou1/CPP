//
// FruitBox.cpp for  in /home/daguen_s/rendu/piscine_cpp_d14m/ex00
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Tue Jan 21 09:45:34 2014 daguen_s
// Last update Tue Jan 21 21:16:02 2014 daguen_s
//

#include "FruitNode.h"
#include "FruitBox.h"

FruitBox::FruitBox(int size)
{
  if (size < 0)
    size = 0;
  this->size = size;
  this->nbFruit = 0;
  this->head_node = NULL;
}

FruitBox::~FruitBox()
{
}

int		FruitBox::getSize() const
{
  return (this->size);
}

int		FruitBox::nbFruits() const
{
  return (this->nbFruit);
}

void		FruitBox::setHead(FruitNode *h)
{
  this->head_node = h;
}

bool		FruitBox::putFruit(Fruit* f)
{
  FruitNode	*newFruitNode;
  FruitNode	*tmp;

  if (f != NULL && this->nbFruit < this->size)
    {
      newFruitNode = new FruitNode;
      newFruitNode->f = f;
      newFruitNode->next = NULL;
      if (this->nbFruit == 0)
	this->head_node = newFruitNode;
      else
	{
	  tmp = this->head_node;
	  if (tmp->f == f)
	    return false;
	  while (tmp->next != NULL)
	    {
	      if (tmp->f == f)
		return false;
	      tmp = tmp->next;
	    }
	  tmp->next = newFruitNode;
	}
      this->nbFruit = this->nbFruit + 1;
      return (true);
    }
  return (false);
}

Fruit*		FruitBox::pickFruit()
{
  Fruit		*f;

  if (this->nbFruit > 0 && this->head_node != NULL)
    {
      f = (this->head_node)->f;
      this->setHead((this->head_node)->next);
      this->nbFruit = this->nbFruit - 1;
      return (f);
    }
  return (NULL);
}

FruitNode*	FruitBox::head() const
{
  if (this->nbFruit > 0)
    return (this->head_node);
  else
    return (NULL);
}
