//
// creerInterfaces.cpp for  in /home/daguen_s/rendu/rush2
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sun Jan 19 04:40:37 2014 daguen_s
// Last update Sun Jan 19 09:28:09 2014 daguen_s
//

#include	"TablePePeNoel.hh"
#include	"ConveyorBeltPePeNoel.hh"

Object	**MyUnitTests()
{
  Object **objet;

  objet = new Object* [4];
  std::cout << "avant =";
  objet[0] = new LittlePony("gay pony");
  std::cout << "apres =";
  objet[1] = new Teddy("bisounours");
  objet[2] = new Teddy("Plein le cul");
  objet[3] = NULL;
  return objet;
}

Object	*MyUnitTests(Object **objets)
{
  if (!objets)
    {
      std::cout << "The array objects is empty" << std::endl;
      return NULL;
    }

  int size = 0;

  while (objets[size++]);
  if (size != 4)
    {
      std::cout << "The size of  array isn't normal, try 4!!!" << std::endl;
      return NULL;
    }

  GiftPaper	*papier = new GiftPaper();
  Box		*carton = new Box();
  Toy		*jouet = new Teddy("Toto");

  size = 0;
  while (size < 3) {
    if (objets[size]->getType() == 2)
      papier = (GiftPaper *) objets[size];
    else if (objets[size]->getType() == 1)
      carton = (Box *) objets[size];
    else if (objets[size]->getType() == 0)
      jouet = (Toy *) objets[size];
    size++;
  }
  if (!(papier && carton && jouet))
    {
      std::cout << "Something is missing" << std::endl;
      return NULL;
    }
  carton->openMe();
  carton->wrapMeThat(jouet);
  carton->closeMe();
  papier->wrapMeThat(carton);
  return papier;
}

ITable *createTable()
{
  ITable *table;

  table = new TablePePeNoel;
  return table;
}

IConveyorBelt *createConveyorBelt()
{
  IConveyorBelt	*tapis;

  tapis = new ConveyorBeltPePeNoel;
  return tapis;
}
