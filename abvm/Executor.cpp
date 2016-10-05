//
// Executor.cpp for  in /home/daguen_s/rendu/cpp_abstractvm
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Thu Feb 27 09:54:07 2014 daguen_s
// Last update Sun Mar  2 08:51:42 2014 daguen_s
//

#include "Executor.hh"
#include "Operand.hpp"

/*
**execute all the instructions :) :)
*/
void Executor::execute()
{
  for(std::vector<std::string *>::iterator it = this->data->begin(); it != this->data->end(); ++it)
    {
      if (*it)
	{
	  if (*it[0] == "push" || *it[0] == "assert")
	    (this->*func_arg[*it[0]])(*it);
	  else
	    {
	      (this->*func[*it[0]])();
	    }
	}
    }
}

void Executor::print()
{
  std::list<IOperand *>::iterator it = this->stack->begin();

  if (it == this->stack->end())
    std::cerr << "Error : print on an empty stack\n";
  else if ((*it)->getType() == INT8){
    std::istringstream buffer((*it)->toString());
    int stock;

    buffer >> stock;
    std::cout << (int8_t )stock << std::endl;
  }
}

void Executor::dump()
{
  std::string tmp;

  for (std::list<IOperand *>::iterator i = this->stack->begin(); i != this->stack->end(); ++i)
    {
      tmp = (*i)->toString();
      if (tmp.size())
	std::cout << tmp << std::endl;
      else
	std::cout << 0 << std::endl;
    }
}

void Executor::exit()
{
  while (this->stack->size() != 0)
    {
      delete *(this->stack->begin());
      this->stack->pop_front();
    }
}

/*
**switch the opernd with the higher type
*/
void Executor::switch_cast(IOperand **o1, IOperand **o2)
{
  std::list<IOperand *>::iterator it = this->stack->begin();
  eOperandType t1 = (*it)->getType();
  ++it;
  eOperandType t2 = (*it)->getType();
  it = this->stack->begin();
  IOperand *op1 = *it;
  ++it;
  IOperand *op2 = *it;
  if (t1 < t2)
    {
      IOperand *tmp = createOperand(t2, op1->toString());
      delete op1;
      op1 = tmp;
    }
  else if (t2 < t1)
    {
      IOperand *tmp = createOperand(t1, op2->toString());
      delete op2;
      op2 = tmp;
    }
  this->stack->pop_front();
  this->stack->pop_front();
  *o1 = op1;
  *o2 = op2;
}

void Executor::add()
{
  if (this->stack->size() < 2)
    {
      throw exception_syntax("Error stack not contain enougth element for addition\n");
      return;
    }
  IOperand *op1;
  IOperand *op2;
  switch_cast(&op1, &op2);
  this->stack->push_front(*op1 + *op2);
  delete op1;
  delete op2;
}

void Executor::sub()
{
  if (this->stack->size() < 2)
    {
      throw exception_syntax("Error stack not contain enougth element for addition\n");
      return;
    }
  IOperand *op1;
  IOperand *op2;
  switch_cast(&op1, &op2);
  this->stack->push_front(*op1 - *op2);
  delete op1;
  delete op2;
}

void Executor::mul()
{
  if (this->stack->size() < 2)
    {
      throw exception_syntax("Error stack not contain enougth element for addition\n");
      return;
    }
  IOperand *op1;
  IOperand *op2;
  switch_cast(&op1, &op2);
  this->stack->push_front(*op1 * *op2);
  delete op1;
  delete op2;
}

void Executor::div()
{
  if (this->stack->size() < 2)
    {
      throw exception_syntax("Error stack not contain enougth element for addition\n");
      return;
    }
  IOperand *op1;
  IOperand *op2;
  switch_cast(&op1, &op2);
  this->stack->push_front(*op1 / *op2);
  delete op1;
  delete op2;
}

void Executor::mod()
{
  if (this->stack->size() < 2)
    {
      throw exception_syntax("Error stack not contain enougth element for addition\n");
      return;
    }
  IOperand *op1;
  IOperand *op2;
  switch_cast(&op1, &op2);
  this->stack->push_front(*op1 % *op2);
  delete op1;
  delete op2;
}

void Executor::assert(std::string *arg)
{
  if (this->stack->size() == 0)
    throw exception_syntax("Assert on an empty stack");
  else if (this->_lType[arg[1]] != (*(this->stack->begin()))->getType())
    throw exception_syntax("The type of the top of the stack is not the same that the one past as parameter");
  if ((*(this->stack->begin()))->toString() != arg[2])
    throw exception_syntax("Assert failed value are different");
}

void Executor::push(std::string *arg)
{
  IOperand *op = createOperand(this->_lType[arg[1]], arg[2]);
  this->stack->push_front(op);
}

template <typename T>
IOperand * Executor::returnOperand(const std::string &value) const
{
  Operand<T> *ret = new Operand<T>(value);
  return ret;
}

/*
**create an operand of the type specified in type with the value value
*/
IOperand * Executor::createOperand(const eOperandType &type, const std::string & value)
{
  return (this->*allType[type])(value);
}

void Executor::pop()
{
  if (this->stack->size() == 0)
    throw exception_syntax("pop on an empty stack");
  else
    {
      delete *(this->stack->begin());
      this->stack->pop_front();
    }
}

//The block ha ha :)
Executor::Executor(const Lexer &lex)
{
  this->data = lex.getData();
  this->stack = new std::list<IOperand *>;
  this->func_arg["push"] = &Executor::push;
  this->func_arg["assert"] = &Executor::assert;
  this->func["dump"] = &Executor::dump;
  this->func["exit"] = &Executor::exit;
  this->func["add"] = &Executor::add;
  this->func["sub"] = &Executor::sub;
  this->func["mul"] = &Executor::mul;
  this->func["div"] = &Executor::div;
  this->func["mod"] = &Executor::mod;
  this->func["print"] = &Executor::print;
  this->func["pop"] = &Executor::pop;
  this->_lType["int8"] = INT8;
  this->_lType["int16"] = INT16;
  this->_lType["int32"] = INT32;
  this->_lType["float"] = FLOAT;
  this->_lType["double"] = DOUBLE;
  this->allType[INT8] = &Executor::returnOperand<int8_t>;
  this->allType[INT16] = &Executor::returnOperand<int16_t>;
  this->allType[INT32] = &Executor::returnOperand<int32_t>;
  this->allType[FLOAT] = &Executor::returnOperand<float>;
  this->allType[DOUBLE] = &Executor::returnOperand<double>;
}

Executor::~Executor()
{
  while (this->stack->size() != 0)
    {
      delete *(this->stack->begin());
      this->stack->pop_front();
    }
  delete stack;
}
