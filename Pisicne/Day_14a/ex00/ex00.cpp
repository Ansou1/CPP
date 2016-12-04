//
// ex00.cpp for  in /home/daguen_s/rendu/piscine_cpp_d14a/ex00
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Tue Jan 21 15:08:27 2014 daguen_s
// Last update Wed Jan 22 09:24:01 2014 daguen_s
//

#include "ex00.hh"

//#################CARD#########################

Cluedo::Card::Card()
{
}

Cluedo::Card::~Card()
{
}

bool		Cluedo::Card::IsPartOfTheCrime() const
{
  return (_isPartOfTheCrime);
}

//#################WEPONS######################

Cluedo::Weapon::Weapon(Weapon::Name name, bool bearsFingerprints)
{
  this->_name = name;
  this->is_bearsFingerprints = bearsFingerprints;
}

Cluedo::Weapon::~Weapon()
{
}

//#################SUSPECT####################

Cluedo::Suspect::Suspect(Suspect::Name name, bool isLying)
{
  this->_name = name;
  this->is_isLying = isLying;
}

Cluedo::Suspect::~Suspect()
{
}

//#################ROOM######################

Cluedo::Room::Room(Room::Name name, bool hasSecretPassage)
{
  this->_name = name;
  this->is_hasSecretPassage = hasSecretPassage;
}

Cluedo::Room::~Room()
{
}

//#################GAME#####################

bool	Cluedo::Game::CaseSolved(Weapon* w[], Suspect* s[], Room* r[])
{
  size_t	i;
  int		validity = 0;

  i = 0;
  while (w[i])
    {
      if (w[i]->IsPartOfTheCrime())
	validity++;
      i++;
    }
  i = 0;
  while (s[i])
    {
      if (w[i]->IsPartOfTheCrime())
	validity++;
      i++;
    }
  i = 0;
  while (r[i])
    {
      if (w[i]->IsPartOfTheCrime())
	validity++;
      i++;
    }
  return (validity == 3 ? true : false);
}

//#################OTHER###################

WeaponException::WeaponException(Weapon* w[])
{
  this->_message = "Weapon ne contient pas la bonne carte!";
  int i = 0;
  while (w[i])
    i++;
  this->_array = new Weapon*[i + 1];
  i = 0;
  while (w[i])
    {
      this->_array[i] = new Weapon(w[i]);
      i++;
    }
  this->_array[i] = NULL;
}

WeaponException::~WeaponException()
{
}

std::string const     &WeaponException::getMessage() const
{
  return this->_message;
}

Cluedo::Weapon        **WeaponException::getCards() const
{
  return this->_array;
}

SuspectException::SuspectException(Suspect* s[])
{
  this->_message = "Suspect ne contient pas la bonne carte!";
  int i = 0;
  while (s[i])
    i++;
  this->_array = new Suspect*[i + 1];
    i = 0;
  while (s[i])
    {
      this->_array[i] = new Suspect(s[i]);
      i++;
    }
  this->_array[i] = NULL;
}

SuspectException::~SuspectException()
{
}

std::string const     &SuspectException::getMessage() const
{
  return this->_message;
}

Cluedo::Suspect      **SuspectException::getCards() const
{
  return this->_array;
}

RoomException::RoomException(Room* r[])
{
  this->_message = "Room ne contient pas la bonne carte!";
  int i = 0;
  while (r[i])
    i++;
  this->_array = new Room*[i + 1];
  i = 0;
  while (r[i])
    {
      this->_array[i] = new Room(r[i]);
      i++;
    }
  this->_array[i] = NULL;
}

RoomException::~RoomException()
{
}

std::string const     &RoomException::getMessage() const
{
  return this->_message;
}

Cluedo::Room          **RoomException::getCards() const
{
  return this->_array;
}
