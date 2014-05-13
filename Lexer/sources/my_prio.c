/*
** my_prio.c for my_prio in /home/guenol_v/rendu/42sh/sources
**
** Made by guenol_v
** Login   <guenol_v@epitech.net>
**
** Started on  Tue Apr 22 15:29:26 2014 guenol_v
** Last update Mon May 12 15:15:34 2014 guenol_v
*/

#include <stdlib.h>
#include "lexer.h"
#include "my.h"

struct node	*my_swap_first(struct node *plist)
{
  while (plist != NULL)
    plist = plist->p_prev;
  return (plist);
}

int	verif_prio(struct node *plist)
{
  if (my_strcmp(plist->data, ";") == 0)
    my_swap_first(plist);
  else if (my_strcmp(plist->data, "|") == 0)
    my_printf(" pipe ");
  else if (my_strcmp(plist->data, ">") == 0)
    my_printf(" droite ");
  else if (my_strcmp(plist->data, "<") == 0)
    my_printf(" gauche ");
  else if (my_strcmp(plist->data, ">>") == 0)
    my_printf(" db.droite ");
  else if (my_strcmp(plist->data, "<<") == 0)
    my_printf(" db.gauche ");
  else if (my_strcmp(plist->data, "&&") == 0)
    my_printf(" etet ");
  else if (my_strcmp(plist->data, "||") == 0)
    my_printf(" pipepipe ");
  return (1);
}

t_list	*my_prio(t_list *list, struct node *plist)
{
  int	a;

  if (plist != NULL)
    {
      a = verif_prio(plist);
      if (a != 1)
	my_putstr(plist->data);
      plist = plist->p_nx1;
      my_prio(list, plist);
    }
  //tlist_display(list);
  return (list);
}
