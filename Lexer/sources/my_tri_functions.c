/*
** my_tri_functions.c for my_tri_functions in /home/guenol_v/rendu/42Sh/Lexer
**
** Made by guenol_v
** Login   <guenol_v@epitech.net>
**
** Started on  Tue May 13 14:46:02 2014 guenol_v
** Last update Sun May 25 16:52:40 2014 guenol_v
*/

#include <stdlib.h>
#include "lexer.h"
#include "my.h"

t_node	*my_making_tree(t_node *plist, t_node *tree)
{
  tree->p_prev = tnode_dup(plist);
  tree->p_prev->p_nx1 = tree;
  tree = tree->p_prev;
  tree->p_nx2 = tnode_dup(plist->p_nx1);
  return (tree);
}

int	my_checking_list(t_node *plist, int a)
{
  while (plist->p_prev != NULL)
    {
      if (verif_prio(plist) > a)
	return (1);
      plist = plist->p_prev;
    }
  return (0);
}

t_node	*my_exec_prio(t_node *plist, t_node *tree)
{
  int	a;

  if ((a = verif_prio(plist)) == 0)
    return (tree);
  if ((a > verif_prio(tree)) && (my_checking_list(plist, a) == 0))
    {
      if (tree->p_prev == NULL)
	tree = my_making_tree(plist, tree);
    }
  else if (my_checking_list(plist, a) == 1)
    {
      if (verif_prio(tree->p_nx2) != 0)
      	tree = my_modif_branch(tree, plist);
      else
	tree = my_construct_branch(tree, plist);
    }
  else
    tree = my_making_tree(plist, tree);
  return (tree);
}
