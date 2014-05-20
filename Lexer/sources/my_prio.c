/*
** my_prio.c for my_prio in /home/guenol_v/rendu/42sh/sources
**
** Made by guenol_v
** Login   <guenol_v@epitech.net>
**
** Started on  Tue Apr 22 15:29:26 2014 guenol_v
** Last update Tue May 20 16:46:18 2014 guenol_v
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
    return (2);
  else if (my_strcmp_strict(plist->data, "&&") == 0)
    return (3);
  else if (my_strcmp_strict(plist->data, "||") == 0)
    return (3);
  else if (my_strcmp_strict(plist->data, ";") == 0)
    return (4);
  return (0);
}

int	verif_prio(t_node *plist)
{
  int	a;

  if (my_strcmp_strict(plist->data, "|") == 0)
    return (1);
  else if (my_strcmp_strict(plist->data, ">>") == 0)
    return (2);
  else if (my_strcmp_strict(plist->data, "<<") == 0)
    return (2);
  else if (my_strcmp_strict(plist->data, ">") == 0)
    return (2);
  a = my_db_verif(plist);
  return (a);
}

t_list	*my_prio(t_list *list, t_node *plist)
{
  int	a;
  t_node	*tree;

  a = 0;
  tree = NULL;
  while (plist != NULL)
    {
      if (tree == NULL)
	my_construct(tree, plist);
      else if (verif_str(plist) == 0 && tree != NULL)
	my_exec_prio(plist, tree);
      else
	return (NULL);
      plist = plist->p_nx1;
    }
  return (list);
}
