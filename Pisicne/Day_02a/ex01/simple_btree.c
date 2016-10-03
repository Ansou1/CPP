/*
** ne simple_btree.c for simple_btree in /home/daguen_s/rendu/piscine_cpp_d02a/ex01
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Thu Jan  9 13:30:33 2014 daguen_s
** Last update Thu Jan  9 14:51:56 2014 daguen_s
*/

#include <stdio.h>
#include <stdlib.h>
#include "simple_btree.h"

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) > (y) ? (y) : (x))

t_bool btree_is_empty(t_tree tree)
{
  if (tree == NULL)
    return TRUE;
  return FALSE;
}

unsigned int btree_get_size(t_tree tree)
{
  if (tree)
    return btree_get_size(tree->left) + btree_get_size(tree->right) + 1;
  return 0;
}

unsigned int btree_get_depth(t_tree tree)
{
  if (tree)
    return MAX(btree_get_depth(tree->left), btree_get_depth(tree->right)) + 1;
  return 0;
}

t_bool btree_create_node(t_tree *node_ptr, double value)
{
  if ((*node_ptr = malloc(sizeof(t_tree))) == NULL)
    return FALSE;
  (*node_ptr)->value = value;
  (*node_ptr)->left = NULL;
  (*node_ptr)->right = NULL;
  return TRUE;
}

t_bool btree_delete(t_tree *root_ptr)
{
  if (*root_ptr)
    {
      btree_delete(&(*root_ptr)->left);
      btree_delete(&(*root_ptr)->right);
      *root_ptr = NULL;
      return TRUE;
    }
  return FALSE;
}

double btree_get_max_value(t_tree tree)
{
  double max = tree->value;
  if (tree->left)
    {
      double g = btree_get_max_value(tree->left);
      max = (max > g ) ? max : g;
    }
  if (tree->right)
    {
      double d = btree_get_max_value(tree->right);
      max = (max > d ) ? max : d;
    }
  return max;
}

double btree_get_min_value(t_tree tree)
{
  double min = tree->value;
  if (tree->left)
    {
      double g = btree_get_min_value(tree->left);
      min = (min < g ) ? min : g;
    }
  if (tree->right)
    {
      double d = btree_get_min_value(tree->right);
      min = (min < d ) ? min : d;
    }
  return min;
}
