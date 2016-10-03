/*
** koaladoctorlist.h for doctor in /home/daguen_s/rendu/piscine_cpp_d06/ex05
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Mon Jan 13 22:06:32 2014 daguen_s
** Last update Mon Jan 13 22:06:57 2014 daguen_s
*/

#ifndef __KOALADOCTORLIST_H__
#define	__KOALADOCTORLIST_H__

#include <string>
#include <iostream>

#include "koaladoctor.h"

class KoalaDoctorList
{
	KoalaDoctor *doctor;
	KoalaDoctorList *next;

public:
	KoalaDoctorList(KoalaDoctor *doctor);
	~KoalaDoctorList();

	bool isEnd();
	void append(KoalaDoctorList *next);
	KoalaDoctor *getFromName(std::string name);
	KoalaDoctorList *remove(KoalaDoctorList *remove);
	KoalaDoctorList *removeFromName(std::string remove);
	void dump();
};

#endif
