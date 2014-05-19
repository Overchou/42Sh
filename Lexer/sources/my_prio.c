/*
** my_prio.c for my_prio in /home/guenol_v/rendu/42sh/sources
**
** Made by guenol_v
** Login   <guenol_v@epitech.net>
**
** Started on  Tue Apr 22 15:29:26 2014 guenol_v
** Last update Mon May 19 21:07:00 2014 guenol_v
*/

#include <stdlib.h>
#include "lexer.h"
#include "my.h"

t_node	*my_prio_str(t_node *tree)
{
  
  return (tree);
}

int	my_db_verif(t_node *plist)
{
  if (my_strcmp_strict(plist->data, "<<") == 0)
    return (3);
  else if (my_strcmp_strict(plist->data, ">") == 0)
    return (3);
  else if (my_strcmp_strict(plist->data, "<") == 0)
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
  else if (my_strcmp_strict(plist->data, "&&") == 0)
    return (2);
  else if (my_strcmp_strict(plist->data, "||") == 0)
    return (2);
  else if (my_strcmp_strict(plist->data, ">>") == 0)
    return (3);
  a = my_db_verif(plist);
  return (a);
}

t_list	*my_prio(t_list *list, t_node *plist)
{
  int	a;
  t_node	*tree;

  a = 0;
  while (plist != NULL)
    {
      a = verif_prio(plist);
      tree = my_exec_prio(plist, a, tree);
      plist = plist->p_nx1;
    }
  return (list);
}
