/*
** my_start_tree.c for my_start_tree in /home/guenol_v/rendu/42Sh/Lexer/sources
**
** Made by guenol_v
** Login   <guenol_v@epitech.net>
**
** Started on  Tue May 20 16:07:34 2014 guenol_v
** Last update Sat May 24 23:44:19 2014 guenol_v
*/

#include <stdlib.h>
#include "lexer.h"

t_node	*my_modif_branch(t_node *tree, t_node *plist)
{
  my_putchar('A');
  return (tree);
}

t_node	*my_construct_branch(t_node *tree, t_node *plist)
{
  int	a;
  //trouver l'ope le plus proche

  a = 0;
  while (plist != NULL && a != 1)
    {
      if (verif_prio(plist) != 0)
	a = 1;
      plist = plist->p_nx1;
    }
  if (a == 1)
    tree = my_construct(tree, plist);
  return (tree);
}

t_node	*my_construct(t_node *tree, t_node *plist)
{
  tree = tnode_dup(plist);
  tree->p_nx2 = tnode_dup(plist->p_nx1);
  tree->p_nx1 = tnode_dup(plist->p_prev);
  return (tree);
}
