//
// IOperand.hh for  in /home/daguen_s/rendu/cpp_abstractvm
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Wed Feb 26 13:51:06 2014 daguen_s
// Last update Wed Feb 26 13:51:23 2014 daguen_s
//

#ifndef IOPERAND_HH
# define IOPERAND_HH

#include <string>
#include <stdint.h>

enum eOperandType{INT8, INT16, INT32, FLOAT, DOUBLE};

class IOperand
{
public:
  virtual std::string const & toString() const = 0; // Renvoie une string reprensentant l’instance

  virtual int getPrecision() const = 0; // Renvoie la precision du type de l’instance
  virtual eOperandType getType() const = 0; // Renvoie le type de l’instance. Voir plus bas

  virtual IOperand * operator+(const IOperand &rhs) const = 0;
  virtual IOperand * operator-(const IOperand &rhs) const = 0;
  virtual IOperand * operator*(const IOperand &rhs) const = 0;
  virtual IOperand * operator/(const IOperand &rhs) const = 0;
  virtual IOperand * operator%(const IOperand &rhs) const = 0;

  virtual ~IOperand() {}
};

#endif
