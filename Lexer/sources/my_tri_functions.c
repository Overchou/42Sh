/*
** my_tri_functions.c for my_tri_functions in /home/guenol_v/rendu/42Sh/Lexer
** 
** Made by guenol_v
** Login   <guenol_v@epitech.net>
** 
** Started on  Tue May 13 14:46:02 2014 guenol_v
** Last update Wed May 21 16:28:54 2014 guenol_v
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
  t_node	*new_ope;
  t_node	*new_node_next;
  t_node	*new_tree;

  if ((a = verif_prio(plist)) == 0)
    return (tree);
  my_printf("a = %d\n", a);
  if (a > verif_prio(tree))
    {
      new_tree = my_new_tree(plist, tree, a);
      new_tree->p_nx2 = tree->p_nx2;
      tree->p_nx2 = new_tree;
    }
  else
    {
      new_ope = tnode_dup(plist);
      new_node_next = tnode_dup(plist->p_nx1);
      new_ope->p_nx1 = new_node_next;
      tree->p_nx1 = new_ope;
    }
  return (tree);
}
