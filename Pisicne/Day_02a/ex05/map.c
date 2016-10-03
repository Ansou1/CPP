/*
** map.c for map.c in /home/daguen_s/rendu/piscine_cpp_d02a/ex05
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Thu Jan  9 18:40:50 2014 daguen_s
** Last update Thu Jan  9 21:17:53 2014 daguen_s
*/

#include "generic_list.h"
#include "map.h"

unsigned int map_get_size(t_map map)
{
  return list_get_size(map);
}

t_bool map_is_empty(t_map map)
{
  return list_is_empty(map);
}

int pair_comparator(void *first, void *second)
{
  return (((t_pair *)first)->key - ((t_pair *)second)->key);
}

t_key_comparator key_cmp_container(t_bool store, t_key_comparator new_key_cmp);
{
  static t_key_comparator value = 0;
  if (store)
    value = new_key_cmp;
  else if (store == FALSE && new_key_cmp == NULL)
    return value;
  return;
}

t_bool map_add_elem(t_map *map_ptr, void *key, void *value, t_key_comparator key_cmp)
{
  return FALSE;
  return TRUE;
}

t_bool map_del_elem(t_map *map_ptr, void *key, t_key_comparator key_cmp)
{
  
}

void *map_get_elem(t_map map, void *key, t_key_comparator key_cmp)
{
  
}
