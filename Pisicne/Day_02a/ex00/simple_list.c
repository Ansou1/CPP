/*
** simple_list.c for simple_list in /home/daguen_s/rendu/piscine_cpp_d02a/ex00
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Thu Jan  9 12:05:56 2014 daguen_s
** Last update Thu Jan  9 18:29:08 2014 daguen_s
*/

#include "simple_list.h"
#include <stdlib.h>
#include <stdio.h>

unsigned int list_get_size(t_list list)
{
  unsigned int count = 0;

  while (list)
    {
      list = list->next;
      count++;
    }
  return count;
}

t_bool list_is_empty(t_list list)
{
  if (!list)
    return TRUE;
  return FALSE;
}

void list_dump(t_list list)
{
  while (list)
    {
      printf("%f\n", list->value);
      list = list->next;
    }
}

t_bool list_add_elem_at_front(t_list *front_ptr, double elem)
{
  t_list	new_elem;

  if ((new_elem = malloc(sizeof(t_list))) == NULL)
     return FALSE;
  new_elem->value = elem;
  new_elem->next = *front_ptr;
  *front_ptr = new_elem;
  return TRUE;
}

t_bool list_add_elem_at_back(t_list *front_ptr, double elem)
{
  t_list        tmp;
  t_list        new_elem;

  if ((new_elem = malloc(sizeof(t_list))) == NULL)
    return (FALSE);
  new_elem->value = elem;
  new_elem->next = NULL;
  if (*front_ptr == NULL)
    *front_ptr = new_elem;
  else if (*front_ptr != NULL)
    {
      tmp = *front_ptr;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new_elem;
    }
  return (TRUE);
}

t_bool list_add_elem_at_position(t_list * front_ptr, double elem, unsigned int position)
{
  t_list        tmp;
  t_list        new_elem;
  unsigned int	i;

  new_elem = malloc(sizeof(t_list));
  if (list_get_size(*front_ptr) < position || new_elem == NULL)
    return (FALSE);
  else if (position == 0 || *front_ptr == NULL)
    return (list_add_elem_at_front(front_ptr, elem));
  else    {
    new_elem->value = elem;
    i = 1;
    tmp = *front_ptr;
    while (i++ < position)
      tmp = tmp->next;
    new_elem->next = tmp->next;
    tmp->next = new_elem;
    return (TRUE);
  }
}

t_bool list_del_elem_at_front(t_list *front_ptr)
{
  t_list list = *front_ptr;

  if (!list)
    return FALSE;
  *front_ptr = list->next;
  free(list);
  return TRUE;
}

t_bool list_del_elem_at_back(t_list *front_ptr)
{
  t_list        tmp;

  if (*front_ptr == NULL)
    return (FALSE);
  tmp = *front_ptr;
  if (list_get_size(*front_ptr) == 1)
    *front_ptr = NULL;
  else
    {
      while (tmp->next->next != NULL)
	tmp = tmp->next;
      tmp->next = NULL;
    }
  return (TRUE);
}

t_bool list_del_elem_at_position(t_list *front_ptr, unsigned int position)
{
  t_list        tmp;
  unsigned int	i;

  if (*front_ptr == NULL)
    return (FALSE);
  tmp = *front_ptr;
  if (list_get_size(*front_ptr) < position)
    return (FALSE);
  else if (position == 0)
    return (list_del_elem_at_front(front_ptr));
  else    {
    i = 1;
    tmp = *front_ptr;
    while (i++ < position)
      tmp = tmp->next;
    tmp->next = tmp->next->next;
    return (TRUE);
  }
}

double list_get_elem_at_front(t_list list)
{
  return list->value;
}

double list_get_elem_at_back(t_list list)
{
  t_list	tmp;

  if (list == NULL)
    return (0);
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  return (tmp->value);
}

double list_get_elem_at_position(t_list list, unsigned int position)
{
  t_list	tmp;
  unsigned int	i;

  if (list == NULL || position > list_get_size(list))
    return (0);
  if (position == 0)
    return list_get_elem_at_front(list);
  tmp = list;
  i = 0;
  while (i++ < position)
    tmp = tmp->next;
  return (tmp->value);
}

t_node *list_get_first_node_with_value(t_list list, double value)
{
  t_list tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (tmp->value == value)
	return (tmp);
      tmp = tmp->next;
    }
  return (0);
}
