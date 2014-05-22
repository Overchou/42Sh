/*
** my_start_tree.c for my_start_tree in /home/guenol_v/rendu/42Sh/Lexer/sources
**
** Made by guenol_v
** Login   <guenol_v@epitech.net>
**
** Started on  Tue May 20 16:07:34 2014 guenol_v
** Last update Thu May 22 19:44:16 2014 guenol_v
*/

#include "lexer.h"

t_node	*my_construct(t_node *tree, t_node *plist)
{
  t_node        *new_node_prev;
  t_node        *new_node_next;
  t_node	*new_ope;

  new_node_prev = tnode_dup(plist->p_prev);
  new_ope = tnode_dup(plist);
  new_node_next = tnode_dup(plist->p_nx1);
  tree = new_ope;
  tree->p_nx2 = new_node_next;
  tree->p_nx1 = new_node_prev;
  return (tree);
}
