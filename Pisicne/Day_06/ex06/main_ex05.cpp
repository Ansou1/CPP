/*
** main.c for piscine in /home/wapiflapi/Projects/piscine/piscine_cpp_d06-2015-rombou_w/ex02
**
** Made by Wannes Rombouts
** Login   <rombou_w@epitech.net>
**
** Started on  Mon Jan  9 13:38:40 2012 Wannes Rombouts
// Last update Tue Jan 10 00:25:40 2012 Wannes Rombouts
*/

#include	<iostream>
#include	<fstream>
#include	"sickkoala.h"
#include	"koalanurse.h"
#include	"koaladoctor.h"
#include	<string>
#include	<cstdlib>
#include	"sickkoalalist.h"

int		main(void)
{
  SickKoala	rabbit("white");
  SickKoala	apple("red");
  KoalaNurse	pokemon(42);
  KoalaDoctor	who("house");

  SickKoala cancer("Ganepar");
  SickKoala gangrene("Scarface");
  SickKoala rougeole("RedFace");
  SickKoala variole("Varia");
  SickKoala fracture("Falter");

  SickKoalaList sick1(&cancer);
  SickKoalaList sick2(&gangrene);
  SickKoalaList sick3(&rougeole);
  SickKoalaList sick4(&variole);
  SickKoalaList sick5(&fracture);

  std::ofstream file;

  file.open("apple.report", std::fstream::out);

  if (file.is_open())
    {
      file << "Buronzand";
      file.close();
    }
  else
    {
      std::cout << "cant make file" << std::endl;
      return 1;
    }


  /* start tests */

  rabbit.poke();
  rabbit.poke();

  std::cout << "mars 1 : " << rabbit.takeDrug("mars")
	    << std::endl;
  std::cout << "mars 1 : " << rabbit.takeDrug("Mars")
	    << std::endl;

  std::cout << "lol 0 : " << rabbit.takeDrug("lol")
	    << std::endl;
  std::cout << "burtruc 1 : " << rabbit.takeDrug("Buronzand")
	    << std::endl;
  std::cout << "Burtruc 0 : " << rabbit.takeDrug("buronzand")
	    << std::endl;

  pokemon.timeCheck();

  rabbit.overDrive("plop le lapin.");
  rabbit.overDrive("ca Kreog !.");
  rabbit.overDrive("ca Kreog ! et ca Kreog !.");
  rabbit.overDrive("... ca Kreog ! et ca Kreog ! ....");

  who.timeCheck();

  pokemon.timeCheck();

  std::cout << "KOALANURSE TESTIIIIIIINNNNNGGGGGGG !!!!!!!" << std::endl;

  std::cout << pokemon.readReport("apple.report") << std::endl;
  std::cout << pokemon.readReport("Vous etes foireux si ce fichier existe.") << std::endl;

  pokemon.timeCheck();

  pokemon.giveDrug("marsss", &rabbit);
  pokemon.giveDrug("mARs", &apple);
  pokemon.giveDrug("bidulle", &apple);

  pokemon.timeCheck();

  who.timeCheck();

  std::cout << rabbit.getName();
  std::cout << apple.getName();

  who.timeCheck();
  srandom(42);
  who.diagnose(&apple);
  who.diagnose(&rabbit);

  std::cout << pokemon.getID() << std::endl;
  std::cout << who.getName() << std::endl;

   std::cout << sick1.isEnd() << std::endl;

  sick1.append(&sick1);
  sick1.append(&sick2);
  sick1.append(&sick3);

  std::cout << sick2.isEnd() << std::endl;

  sick1.append(&sick4);
  sick1.append(&sick5);

  std::cout << sick1.remove(&sick5)->getContent()->getName() << std::endl;
  std::cout << sick1.remove(&sick1)->getContent()->getName() << std::endl;
  sick2.dump();
  sick1.dump();


  std::cout << sick2.getContent()->getName() << std::endl;
  std::cout << sick2.getNext()->getContent()->getName() << std::endl;

  std::string		vtff;

  vtff = sick5.getContent()->getName();
  sick2.removeFromName(vtff);
  sick2.dump();

  return 0;
}
