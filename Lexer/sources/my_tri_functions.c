/*
** my_tri_functions.c for my_tri_functions in /home/guenol_v/rendu/42Sh/Lexer
** 
** Made by guenol_v
** Login   <guenol_v@epitech.net>
** 
** Started on  Tue May 13 14:46:02 2014 guenol_v
** Last update Mon May 19 22:08:06 2014 guenol_v
*/

#include <stdlib.h>
#include "lexer.h"
#include "my.h"

t_node	*my_prio_one(t_node *tree)
{
  
  return (tree);
}

t_node	*my_prio_two(t_node *tree)
{
  
  return (tree);
}

t_node	*my_prio_three(t_node *tree)
{
  
  return (tree);
}

t_node	*my_prio_four(t_node *tree)
{
  
  return (tree);
}

t_node	*my_exec_prio(t_node *plist, int a, t_node *tree)
{
  t_node *(*fptr[5])(t_node *);
  t_node	*tree;
  t_node	*new_node;

  fptr[0] = &my_prio_str;
  fptr[1] = &my_prio_one;
  fptr[2] = &my_prio_two;
  fptr[3] = &my_prio_three;
  fptr[4] = &my_prio_four;
  new_node = tnode_dup(plist);
  tree = (*fptr[a])(new_node);
  return (tree);
}
