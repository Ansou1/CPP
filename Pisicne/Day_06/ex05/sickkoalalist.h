/*
** sickkoalalist.h for koala in /home/daguen_s/rendu/piscine_cpp_d06/ex05
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Mon Jan 13 22:07:20 2014 daguen_s
** Last update Mon Jan 13 22:07:55 2014 daguen_s
*/

#ifndef __SICKKOALALIST_H__
#define	__SICKKOALALIST_H__

#include <string>
#include <iostream>

#include "sickkoala.h"

class SickKoalaList
{
	SickKoala *koala;
	SickKoalaList *next;

public:
	SickKoalaList(SickKoala *koala);
	~SickKoalaList();

	bool isEnd();
	void append(SickKoalaList *next);
	SickKoala *getFromName(std::string name);
	SickKoalaList *remove(SickKoalaList *remove);
	SickKoalaList *removeFromName(std::string remove);
	void dump();
	SickKoala *getContent();
	void *getNext();
};

#endif
