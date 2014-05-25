/*
** my_prio.c for my_prio in /home/guenol_v/rendu/42sh/sources
**
** Made by guenol_v
** Login   <guenol_v@epitech.net>
**
** Started on  Tue Apr 22 15:29:26 2014 guenol_v
** Last update Sun May 25 22:37:56 2014 guenol_v
*/

#include <stdlib.h>
#include "lexer.h"
#include "my.h"

int	verif_str(t_node *plist)
{
  int	a;

  a = 0;
  if (plist->p_prev != NULL && verif_prio(plist->p_prev) == 0)
    a++;
  if (plist->p_nx1 != NULL && verif_prio(plist->p_nx1) == 0)
    a++;
  if (a == 2)
    return (0);
  else
    return (1);
}

int	my_db_verif(t_node *plist)
{
  if (my_strcmp_strict(plist->data, "<") == 0)
    return (1);
  else if (my_strcmp_strict(plist->data, "&&") == 0)
    return (2);
  else if (my_strcmp_strict(plist->data, "||") == 0)
    return (2);
  else if (my_strcmp_strict(plist->data, ";") == 0)
    return (3);
  return (0);
}

int	verif_prio(t_node *plist)
{
  int	a;

  if (my_strcmp_strict(plist->data, "|") == 0)
    return (1);
  else if (my_strcmp_strict(plist->data, ">>") == 0)
    return (1);
  else if (my_strcmp_strict(plist->data, "<<") == 0)
    return (1);
  else if (my_strcmp_strict(plist->data, ">") == 0)
    return (1);
  a = my_db_verif(plist);
  return (a);
}

t_node	*my_prio(t_node *plist)
{
  t_node	*tree;

  tree = NULL;
  if ((my_verif_list(plist)) != NULL)
    tree = my_verif_list(plist);
  while (plist != NULL)
    {
      if (tree == NULL && verif_prio(plist) != 0)
	if ((tree = my_construct(tree, plist)) == NULL)
	  return (NULL);
      else if ((verif_str(plist) == 0) && tree != NULL)
	tree = my_exec_prio(plist, tree);
      plist = plist->p_nx1;
    }
  return (tree);
}
