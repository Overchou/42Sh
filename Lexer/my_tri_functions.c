/*
** my_tri_functions.c for my_tri_functions in /home/guenol_v/rendu/42Sh/Lexer
** 
** Made by guenol_v
** Login   <guenol_v@epitech.net>
** 
** Started on  Tue May 13 14:46:02 2014 guenol_v
** Last update Mon May 19 20:43:57 2014 guenol_v
*/

#include <stdlib.h>
#include "lexer.h"
#include "my.h"

t_node	*my_prio_one(t_node *tree)
{
  my_putchar('a');
  return (tree);
}

t_node	*my_prio_two(t_node *tree)
{
  my_putchar('b');
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

t_node	*my_exec_prio(t_node *plist, int a)
{
  t_node *(*fptr[4])(t_node *);
  t_node	*tree;
  t_node	*new_node;

  a = 0;
  my_putchar('a');
  fptr[0] = &my_prio_one;
  fptr[1] = &my_prio_two;
  fptr[2] = &my_prio_three;
  fptr[3] = &my_prio_four;
  new_node = tnode_dup(plist);
  tree = (*fptr[a])(new_node);
  return (tree);
}
