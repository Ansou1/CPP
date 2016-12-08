/*
** DomesticKoala.h for  in /home/daguen_s/rendu/piscine_cpp_d16/ex01
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Thu Jan 23 11:34:39 2014 daguen_s
** Last update Thu Jan 23 23:04:47 2014 daguen_s
*/

#ifndef _DOMESTICKOALA_H_
# define _DOMESTICKOALA_H_

#include <string>
#include <vector>
#include "KoalaAction.h"

typedef void (KoalaAction::*methodPointer_t)(const std::string &);

class DomesticKoala
{
private:
  KoalaAction	koala;
  std::vector<unsigned char> code;
  std::vector<methodPointer_t> action;

 public:
  DomesticKoala(const KoalaAction&);
  ~DomesticKoala();

  DomesticKoala(const DomesticKoala&);
  DomesticKoala			&operator=(const DomesticKoala &);

  std::vector<methodPointer_t> const	*getActions(void) const;

  void				learnAction(unsigned char, methodPointer_t);
  void				unlearnAction(unsigned char);
  void				doAction(unsigned char, const std::string&);
  void				setKoalaAction(KoalaAction&);
};

#endif /* _DOMESTICKOALA_H_ */
