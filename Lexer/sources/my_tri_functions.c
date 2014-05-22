/*
** my_tri_functions.c for my_tri_functions in /home/guenol_v/rendu/42Sh/Lexer
** 
** Made by guenol_v
** Login   <guenol_v@epitech.net>
** 
** Started on  Tue May 13 14:46:02 2014 guenol_v
** Last update Thu May 22 19:31:32 2014 guenol_v
*/

#include <stdlib.h>
#include "lexer.h"
#include "my.h"

t_node	*my_new_tree(t_node *plist, t_node *tree, int a)
{
  t_node	*new_ope;
  t_node	*new_node_next;
  t_node	*new_tree;
  int	b;

  new_tree = NULL;
  while (plist != NULL && a < b)
    {
      if ((b = verif_prio(plist)) != 0 && a < b)
	{
	  if (new_tree == NULL)
	    my_construct(tree, plist);
	  new_ope = tnode_dup(plist);
	  new_node_next = tnode_dup(plist->p_nx1);
	  new_ope->p_nx1 = new_node_next;
	  new_tree->p_nx1 = new_ope;
	}
      plist = plist->p_nx1;
    }
  return (tree);
}

t_node	*my_exec_prio(t_node *plist, t_node *tree)
{
  int	a;
  t_node	*new_tree;

  if ((a = verif_prio(plist)) == 0)
    return (tree);
  if (a > verif_prio(tree))
    {
      tree->p_prev = tnode_dup(plist->p_nx1);
      tree->p_prev->p_nx1 = tree;
      /* verifier le nouvel arbre */
      new_tree = my_new_tree(plist, tree, a);

      tree->p_nx2 = new_tree;
      tree->p_nx2->p_prev = tree;
    }
  tree->p_prev = tnode_dup(plist);
  tree->p_prev->p_nx1 = tree;
  tree = tree->p_prev;
  tree->p_nx2 = tnode_dup(plist->p_nx1);
  return (tree);
}
