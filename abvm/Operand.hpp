//
// Operand.hpp for  in /home/daguen_s/rendu/cpp_abstractvm
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Wed Feb 26 13:56:08 2014 daguen_s
// Last update Fri Feb 28 11:23:01 2014 daguen_s
// Last update Fri Feb 28 11:18:49 2014 florian
//

#ifndef _OPERAND_HH
# define _OPERAND_HH

#include <sstream>
#include <iostream>
#include <limits>
#include "IOperand.hh"
#include "Exception.hpp"
#include <iomanip>

#include <stdio.h>
#include <string.h>

template <typename T>
class Operand : public IOperand
{
private:
  T _nbr;
  std::string _str;
  int _precision;

public:
  virtual std::string const & toString() const
  {
    return this->_str;
  }

  virtual int getPrecision() const
  {
    return this->_precision;
  }

  virtual int whichPrecision(std::string const & str) const
  {
    unsigned int i = 0;

    if ((i = str.find('.')) != 0)
      return str.size() - ++i;
    return 0;
  }

  virtual eOperandType getType() const
  {
    return INT8;
  }

  T getValue() const
  {
    return this->_nbr;
  }

  void get_offset(T &min, T &max) const
  {
    min = std::numeric_limits<T>::min();
    max = std::numeric_limits<T>::max();
  }

  T str_to_nbr(std::string const &str) const
  {
    std::istringstream buffer(str);
    T stock;

    buffer >> stock;
    return stock;
  }

  std::string nbr_to_str(T const &nbr) const
  {
    std::ostringstream convert;
    std::string ret;

    convert << nbr;
    ret = convert.str();
    return ret;
  }

  virtual IOperand * operator+(const IOperand &rhs) const
  {
    Operand <T>*ret;
    T min,max;
    T nb1 = this->_nbr;
    T nb2 = Operand<T>::str_to_nbr(rhs.toString());

    this->get_offset(min, max);
    if (max < nb1 + nb2)
      throw exception_syntax("Overflow");
    else if (min > nb1 + nb2)
      throw exception_syntax("Underflow");
    nb1 = nb1 + nb2;
    ret = new Operand<T>(this->nbr_to_str(nb1));
    int p2 = whichPrecision(rhs.toString());
    ret->_precision = this->_precision > p2 ? this->_precision : p2;
    return ret;
  }

  virtual IOperand * operator-(const IOperand &rhs) const
  {
    Operand <T>*ret;
    T min,max;
    T nb1 = this->_nbr;
    T nb2 = Operand<T>::str_to_nbr(rhs.toString());

    this->get_offset(min, max);
    if (max < nb2 - nb1)
      throw exception_syntax("Overflow");
    else if (min > nb2 - nb1)
      throw exception_syntax("Underflow");
    nb1 = nb2 - nb1;
    ret = new Operand<T>(this->nbr_to_str(nb1));
    int p2 = whichPrecision(rhs.toString());
    ret->_precision = this->_precision > p2 ? this->_precision : p2;
    return ret;
  }

  virtual IOperand * operator*(const IOperand &rhs) const
  {
    Operand <T>*ret;
    T min,max;
    T nb1 = this->_nbr;
    T nb2 = Operand<T>::str_to_nbr(rhs.toString());

    this->get_offset(min, max);
    if (max < nb1 * nb2)
      throw exception_syntax("Overflow");
    else if (min > nb1 * nb2)
      throw exception_syntax("Underflow");
    nb1 = nb1 * nb2;
    ret = new Operand<T>(this->nbr_to_str(nb1));
    int p2 = whichPrecision(rhs.toString());
    ret->_precision = this->_precision > p2 ? this->_precision : p2;
    return ret;
  }

  virtual IOperand * operator/(const IOperand &rhs) const
  {
    Operand <T>*ret;
    T min,max;
    T nb1 = this->_nbr;
    T nb2 = Operand<T>::str_to_nbr(rhs.toString());

    if (nb1 == 0)
      throw exception_calcul("Math error division by 0");
    this->get_offset(min, max);
    if (max < nb2 / nb1)
      throw exception_syntax("Overflow");
    else if (min > nb2 / nb1)
      throw exception_syntax("Underflow");
    nb1 = nb2 / nb1;
    ret = new Operand<T>(this->nbr_to_str(nb1));
    int p2 = whichPrecision(rhs.toString());
    ret->_precision = this->_precision > p2 ? this->_precision : p2;
    return ret;
  }

  virtual IOperand * operator%(const IOperand &rhs) const
  {
    Operand <T>*ret;
    T min,max;
    T nb1 = this->_nbr;
    T nb2 = Operand<T>::str_to_nbr(rhs.toString());

    if (nb1 == 0)
      throw exception_calcul("Math error modulo by 0");
    this->get_offset(min, max);
    if (max < nb2 % nb1)
      throw exception_syntax("Overflow");
    else if (min > nb2 % nb1)
      throw exception_syntax("Underflow");
    nb1 = nb2 % nb1;
    ret = new Operand<T>(this->nbr_to_str(nb1));
    int p2 = whichPrecision(rhs.toString());
    ret->_precision = this->_precision > p2 ? this->_precision : p2;
    return ret;
  }

  Operand(std::string const &value)
  {
    std::string clean = value;
    int i = 0;

    for (; value[i] == '0';++i);
    clean = clean.erase(0, i);
    this->_nbr = str_to_nbr(clean);
    this->_str = clean;
    this->_precision = whichPrecision(clean);
  }

  ~Operand(){}

};

template<>
eOperandType Operand<int16_t>::getType() const {return INT16;}

template<>
eOperandType Operand<int32_t>::getType() const {return INT32;}

template<>
eOperandType Operand<float>::getType() const {return FLOAT;}

template<>
eOperandType Operand<double>::getType() const {return DOUBLE;}

template<>
IOperand * Operand<float>::operator%(const IOperand &rhs) const
{
  float nb2 = Operand<float>::str_to_nbr(rhs.toString());
  nb2 = nb2;
  throw exception_calcul("Math error try to do an euclidien division with a no integer type.");
  return NULL;
}

template<>
IOperand * Operand<double>::operator%(const IOperand &rhs) const
{
  double nb2 = Operand<double>::str_to_nbr(rhs.toString());
  nb2 = nb2;
  throw exception_calcul("Math error try to do an euclidien division with a no integer type.");
  return NULL;
}

template<>
void Operand<float>::get_offset(float &min, float &max) const
{
  max = std::numeric_limits<float>::max();
  min = -max;
}

template<>
void Operand<double>::get_offset(double &min, double &max) const
{
  max = std::numeric_limits<double>::max();
  min = -max;
}

template<>
int8_t Operand<int8_t>::str_to_nbr(std::string const &value) const
{
  std::istringstream buffer(value);
  int stock;

  buffer >> stock;
  return (int8_t)stock;
}

template<>
std::string Operand<int8_t>::nbr_to_str(int8_t const &nbr) const
{
  std::ostringstream convert;
  std::string ret;

  convert << (int)nbr;
  ret = convert.str();
  return ret;
}

#endif
