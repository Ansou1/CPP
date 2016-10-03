/*
** castmania.c for castmania.c in /home/daguen_s/rendu/piscine_cpp_d02m/ex04
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Thu Jan  9 09:39:33 2014 daguen_s
** Last update Thu Jan  9 10:24:00 2014 daguen_s
*/
#include <stdio.h>
#include "castmania.h"

void exec_add(t_add *operation);
void exec_div(t_div *operation);

void exec_operation(t_instruction_type instruction_type, void *data)
{
  t_instruction *value;

  if (instruction_type == ADD_OPERATION)
    {
      value = (t_instruction *)data;
      exec_add(value->operation);
      if (value->output_type == VERBOSE)
	printf("%i\n", ((t_add *)value->operation)->add_op.res);
    }
  else if(instruction_type == DIV_OPERATION)
    {
      value = (t_instruction *)data;
      exec_div(value->operation);
      if (value->output_type == VERBOSE)
	{
	  if (((t_div *)value->operation)->div_type == INTEGER)
	    printf("%i\n", ((t_integer_op *)((t_div *)value->operation)->div_op)->res);
	  else
	    printf("%f\n", ((t_decimale_op *)((t_div *)value->operation)->div_op)->res);
	}
    }
}

void exec_instruction(t_instruction_type instruction_type, void *data)
{
  if (instruction_type == PRINT_INT)
    printf("%i\n", *((int*)data));
  else if (instruction_type == PRINT_FLOAT)
    printf("%f\n", *((float*)data));
  else
    exec_operation(instruction_type, data);
}
