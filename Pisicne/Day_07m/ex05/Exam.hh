//
// Exam.hh for exam in /home/daguen_s/rendu/piscine_cpp_d07m/ex05
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Tue Jan 14 22:29:37 2014 daguen_s
// Last update Tue Jan 14 22:58:30 2014 daguen_s
//

#ifndef _EXAM_H_
# define _EXAM_H_

#include <string>
#include <iostream>

class Exam
{
public:
    Exam(bool *);
    ~Exam();
  void (Exam::*kobayashiMaru)(int);
  void	start(int);
  bool	isCheating();

  static bool cheat;
};

#endif /* _EXAM_H_ */
