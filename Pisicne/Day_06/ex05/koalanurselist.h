/*
** koalanurselist.h for nurse in /home/daguen_s/rendu/piscine_cpp_d06/ex05
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Mon Jan 13 22:20:58 2014 daguen_s
** Last update Mon Jan 13 22:20:59 2014 daguen_s
*/

#ifndef __KOALANURSELIST_H__
#define	__KOALANURSELIST_H__

#include <string>
#include <iostream>

#include "koalanurse.h"

class KoalaNurseList
{
	KoalaNurse *nurse;
	KoalaNurseList *next;

public:
	KoalaNurseList(KoalaNurse *koala);
	~KoalaNurseList();

	bool isEnd();
	void append(KoalaNurseList *next);
	KoalaNurse *getFromID(int id);
	KoalaNurseList *remove(KoalaNurseList *remove);
	KoalaNurseList *removeFromID(int remove);
	void dump();
};

#endif
