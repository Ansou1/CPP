//
// ex05.hpp for  in /home/daguen_s/rendu/piscine_cpp_d15/ex05
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Wed Jan 22 16:09:10 2014 daguen_s
// Last update Wed Jan 22 22:52:08 2014 daguen_s
//

#ifndef _EX05_H_
# define _EX05_H_

#include <iostream>
#include <exception>

template<typename T>
class array
{
  unsigned int	_size;
  T*		tab;

public:

  //#######################  CTOR/DTOR/COPY/= ##################################
  array(unsigned int size = 0)
  {
    if (size == 0)
      {
	this->_size = 0;
	this->tab = NULL;
      }
    else
      {
	this->_size = size;
	this->tab = new T[_size];
      }
  }

  array(const array<T> & source)
  {
    this->_size = source._size;
    this->tab = new T[_size];
    for (unsigned int i = 0; i < this->_size; i++)
      this->tab[i] = source.tab[i];
  }

  array<T> & operator=(const array<T> & src)
  {
    if (this->tab)
      delete[] this->tab;
    this->_size = src._size;
    this->tab = new T[this->_size];
    for (unsigned int i = 0; i < this->_size; i++)
      this->tab[i] = src.tab[i];
    return (*this);
  }

  virtual ~array()
  {
    if (this->tab)
      delete[] this->tab;
  }

  //#######################  GETTEUR ##################################
  unsigned int size() const
  {
    return this->_size;
  }

  //#######################  PRINT ####################################
  void dump() const
  {
    unsigned int i = 0;

    std::cout << "[";
    while (i < this->_size)
      {
	std::cout << this->tab[i];
	i++;
	if (i != this->_size)
	  std::cout << ", ";
      }
    std::cout << "]" << std::endl;
  }

  template<typename U>
  array<U> convertTo(U(*convert)(const T &)) const
  {
    array<U> copy_int(this->_size);
    for (unsigned int i = 0; i < this->_size; i++)
      copy_int[i] = (*convert)(this->tab[i]);
    return copy_int;
  }

  T & operator[](unsigned int index)
  {
    if (index >= this->_size)
      {
	T * copy = new T[index + 1];
	for (unsigned int i = 0; i < this->_size; i++)
	  copy[i] = this->tab[i];
	delete[] this->tab;
	this->tab = copy;
	this->_size = index + 1;
      }
    return this->tab[index];
  }

  T & operator[](unsigned int index) const
  {
    if (index >= this->_size)
      throw std::exception();
    return this->tab[index];
  }

};

template<>
void array<bool>::dump() const
{
  unsigned int i = 0;

  std::cout << "[";
  while (i < this->_size)
    {
      std::cout << (this->tab[i] ? "true" : "false");
      i++;
      if (i != this->_size)
	std::cout << ", ";
    }
  std::cout << "]" << std::endl;
}

#endif /* _EX05_H_ */
