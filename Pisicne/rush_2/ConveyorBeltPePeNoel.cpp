//
// ConveyorBeltPePeNoel.cpp for  in /home/daguen_s/rendu/rush2
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sun Jan 19 02:07:10 2014 daguen_s
// Last update Sun Jan 19 04:45:39 2014 daguen_s
//

#include	"ConveyorBeltPePeNoel.hh"

ConveyorBeltPePeNoel::ConveyorBeltPePeNoel()
{
  this->index = 0;
  this->current = NULL;
  stack = new Object*[5];
  this->stack[0] = new Box;
  this->stack[1] = new Box;
  this->stack[2] = new GiftPaper;
  this->stack[3] = new GiftPaper;
  this->stack[4] = NULL;
}

ConveyorBeltPePeNoel::~ConveyorBeltPePeNoel()
{
}

Object	*ConveyorBeltPePeNoel::Take()
{
  if (this->current == NULL)
    {
      if (this->index < 4)
	{
	  this->index++;
	  return this->stack[this->index];
	}
      std::cerr << "There are not anymore gift." << std::endl;
      return NULL;
    }
  std::cerr << "There is already an object on the Conveyorbelt." << std::endl;
  return NULL;
}

bool	ConveyorBeltPePeNoel::Put(Object *obj)
{
  if (this->current == NULL)
    {
      this->current = obj;
      return true;
    }
  std::cerr << "There is already something on the Conveyorbelt." << std::endl;
  return false;
}
