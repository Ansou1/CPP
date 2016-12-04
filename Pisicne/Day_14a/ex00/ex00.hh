#ifndef CLUEDO_H_
#define CLUEDO_H_

#include <iostream>
#include <string>

namespace Cluedo
{
  class Card
  {
  protected:
    Card();
    ~Card();

  public:
    bool	IsPartOfTheCrime() const;

  protected:
    bool	_isPartOfTheCrime;
  };

  class Weapon : public Card
  {
  public:
    enum Name {Corde, Matraque, Poignard, Cle_Anglaise, Chandelier, Revolver};
    static const Name PartOfTheCrime;

  private:
    bool	is_bearsFingerprints;
    Name	_name;

  public:
    Weapon(Weapon::Name name, bool bearsFingerprints);
    ~Weapon();

    bool	BearsFingerprints() const;
  };

  class Suspect : public Card
  {
  public:
    enum Name
      {Mlle_Rose, Pr_Violet, Col_Moutarde, Dr_Olive, Mme_Leblanc, Mme_Pervenche};
    static const Name PartOfTheCrime;

  private:
    bool	is_isLying;
    Name	_name;

  public:
    Suspect(Suspect::Name name, bool isLying);
    ~Suspect();

    bool	IsLying() const;
  };

  class Room : public Card
  {
  public:
    enum Name
      {Cuisine,	Grand_Salon, Veranda, Petit_Salon, Salle_a_Manger, Billard, Bibliotheque, Bureau, Hall};
    static const Name PartOfTheCrime;

  private:
    bool	is_hasSecretPassage;
    Name	_name;

  public:
    Room(Room::Name name, bool hasSecretPassage);
    ~Room();

    bool	HasSecretPassage() const;
  };

  class Game
  {
  public:
    static bool CaseSolved(Weapon* w[], Suspect* s[], Room* r[]);
  };
}

class WeaponException
{
  std::string		_message;
  Cluedo::Weapon	**_array;

public:
  WeaponException(Cluedo::Weapon* w[]);
  ~WeaponException();

  std::string const	&getMessage() const;
  Cluedo::Weapon	**getCards() const;
};

class SuspectException
{
  std::string		_message;
  Cluedo::Suspect	**_array;

public:
  SuspectException(Cluedo::Suspect* s[]);
  ~SuspectException();

  std::string const	&getMessage() const;
  Cluedo::Suspect	**getCards() const;
};

class RoomException
{
  std::string		_message;
  Cluedo::Room		**_array;

public:
  RoomException(Cluedo::Room* r[]);
  ~RoomException();

  std::string const	&getMessage() const;
  Cluedo::Room		**getCards() const;
};

#endif // CLUEDO_H_
