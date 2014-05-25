/*
** my_start_tree.c for my_start_tree in /home/guenol_v/rendu/42Sh/Lexer/sources
**
** Made by guenol_v
** Login   <guenol_v@epitech.net>
**
** Started on  Tue May 20 16:07:34 2014 guenol_v
** Last update Sun May 25 22:15:40 2014 guenol_v
*/

#include <stdlib.h>
#include "lexer.h"
#include "my.h"

t_node  *tnode_dup_branch(t_node *p_node)
{
  t_node        *p_cpy;

  p_cpy = NULL;
  if ((p_cpy = malloc(sizeof(*p_cpy))) == NULL)
    return (0);
  if (p_cpy != NULL)
    {
      p_cpy->data = p_node->data;
      p_cpy->type = p_node->type;
      p_cpy->p_nx1 = p_node->p_nx1;
      p_cpy->p_nx2 = p_node->p_nx2;
      p_cpy->p_prev = NULL;
    }
  return (p_cpy);
}

t_node	*my_modif_branch(t_node *tree, t_node *plist)
{
  t_node	*ope_tmp;

  if (verif_prio(tree) != 0)
    ope_tmp = tnode_dup_branch(tree->p_nx2);
  tree->p_nx2 = tnode_dup(plist);
  tree->p_nx2->p_nx2 = tnode_dup(plist->p_nx1);
  tree->p_nx2->p_nx1 = ope_tmp;
  return (tree);
}

t_node	*my_construct_branch(t_node *tree, t_node *plist)
{
  t_node	*tmp;

  tmp = tnode_dup(tree->p_nx2);
  tree->p_nx2 = tnode_dup(plist);
  tree->p_nx2->p_prev = tree;
  tree->p_nx2->p_nx2 = tnode_dup(plist->p_nx1);
  tree->p_nx2->p_nx1 = tnode_dup(tmp);
  return (tree);
}

t_node	*my_construct(t_node *tree, t_node *plist)
{
  if (plist->p_nx1 == NULL || plist->p_prev == NULL)
    return (NULL);
  tree = tnode_dup(plist);
  tree->p_nx2 = tnode_dup(plist->p_nx1);
  tree->p_nx1 = tnode_dup(plist->p_prev);
  return (tree);
}
