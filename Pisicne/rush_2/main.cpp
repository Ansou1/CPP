#include <iostream>
#include <string>
#include "Teddy.hh"
#include "LittlePony.hh"

Object **MyUnitTests();
Object *MyUnitTests(Object **object);

int	main()
{
  Object **toys;
  Object *gift = new Teddy("bisounours");

  toys = MyUnitTests();
  if (toys == NULL)
    std::cout << "ici\n";
  std::cout << "test";
  gift = MyUnitTests(toys);
  
  
  for (int i = 0; i < 2; i++)
    {
      std::cout << "Name => " << toys[i]->getName() << std::endl;
      toys[i]->isTaken();
    }
  std::cout << gift->openMe()->openMe()->getName() << std::endl;
  return (0);
}
