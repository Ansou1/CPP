//
// DomesticKoala.cpp for  in /home/daguen_s/rendu/piscine_cpp_d16/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Thu Jan 23 11:34:36 2014 daguen_s
// Last update Fri Jan 24 08:46:31 2014 daguen_s
//

#include "DomesticKoala.h"

DomesticKoala::DomesticKoala(const KoalaAction &src)
{
  koala = src;
}

DomesticKoala::~DomesticKoala()
{
}

DomesticKoala::DomesticKoala(const DomesticKoala &src)
{
  koala = src.koala;
}

DomesticKoala		&DomesticKoala::operator=(const DomesticKoala &src)
{
  koala = src.koala;
  return (*this);
}

std::vector<methodPointer_t> const * DomesticKoala::getActions(void) const
{
  return &action;
}

void			DomesticKoala::learnAction(unsigned char c, methodPointer_t ptr)
{
  std::vector<unsigned char>::iterator		it;
  int						i = 0;

  it = code.begin();
  while (it != code.end())
    {
      if (c == *it)
	{
	  action[i] = ptr;
	  return;
	}
      i++;
      it++;
    }
  code.push_back(c);
  action.push_back(ptr);
}

void			DomesticKoala::unlearnAction(unsigned char c)
{
  std::vector<unsigned char>::iterator		v_char;
  std::vector<methodPointer_t>::iterator	v_ptr;

  v_ptr = action.begin();
  for (v_char = code.begin(); v_char != code.end(); v_char++)
    {
      if (c == *v_char)
	{
	  code.erase(v_char);
	  action.erase(v_ptr);
	}
      v_ptr++;
    }
}

void			DomesticKoala::doAction(unsigned char c, const std::string& comment)
{
  std::vector<unsigned char>::iterator		v_char;
  std::vector<methodPointer_t>::iterator	v_ptr;
  methodPointer_t				ptr;

  v_ptr = action.begin();
  for (v_char = code.begin(); v_char != code.end(); v_char++)
    {
      if (*v_char == c)
	{
	  ptr = *v_ptr;
	  ((koala).*ptr)(comment);
	}
      v_ptr++;
    }
}

void			DomesticKoala::setKoalaAction(KoalaAction& src)
{
  code.clear();
  action.clear();
  koala = src;
}
