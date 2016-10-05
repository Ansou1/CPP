//
// Executor.hh for  in /home/daguen_s/rendu/cpp_abstractvm
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Wed Feb 26 13:50:23 2014 daguen_s
// Last update Wed Feb 26 13:50:49 2014 daguen_s
//

#ifndef EXECUTOR_HH
# define EXECUTOR_HH

#include <map>
#include <list>
#include "VirtualMachine.hh"
#include "Lexer.hh"
# define MAX(x,y) (x > y ? x : y)

class Executor : public VirtualMachine
{
private:
  std::list<IOperand *> *stack;
  std::vector<std::string *> *data;
  std::map<std::string, void (Executor::*)(std::string *)> func_arg;
  std::map<std::string, void (Executor::*)(void)> func;
  std::map<std::string, eOperandType> _lType;
  std::map<eOperandType, IOperand * (Executor::*)(const std::string &) const> allType;

public:
  void execute();
  void push(std::string *arg);
  void assert(std::string *arg);
  void dump();
  void exit();
  void add();
  void sub();
  void mul();
  void div();
  void mod();
  void print();
  void pop();
  template <typename T>
  IOperand * returnOperand(const std::string &) const;
  IOperand * createOperand(const eOperandType &, const std::string &);
  void switch_cast(IOperand **, IOperand **);
  Executor(const Lexer &);
  ~Executor();
};

#endif
