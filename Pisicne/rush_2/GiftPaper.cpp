//
// GiftPaper.cpp for  in /home/daguen_s/rendu/rush2
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sun Jan 19 01:05:06 2014 daguen_s
// Last update Sun Jan 19 09:53:58 2014 daguen_s
//

#include	<iostream>
#include	"GiftPaper.hh"

GiftPaper::GiftPaper() : Wrap("PapierCadeau", GIFTPAPER)
{
  this->open = true;
}

GiftPaper::GiftPaper(GiftPaper &src) : Wrap(src.name, src.type)
{
}

void		GiftPaper::operator=(GiftPaper &src)
{  (std::string)this->name = src.name;
  this->type = src.type;
}

GiftPaper::~GiftPaper()
{
}

void		GiftPaper::closeMe()
{
  std::cerr << "A GiftPaper doensn't close !" << std::endl;
}

Object *GiftPaper::openMe()
{
  this->open = true;
  return (this->content);
}
