/*
** my_prio.c for my_prio in /home/guenol_v/rendu/42sh/sources
**
** Made by guenol_v
** Login   <guenol_v@epitech.net>
**
** Started on  Tue Apr 22 15:29:26 2014 guenol_v
** Last update Fri May 16 15:47:42 2014 guenol_v
*/

#include <stdlib.h>
#include "lexer.h"
#include "my.h"

t_node	*my_swap_first(t_node *plist)
{
  while (plist != NULL)
    plist = plist->p_prev;
  return (plist);
}

int	verif_prio(t_node *plist)
{
  plist = my_init_tab(plist);
  if (my_strcmp(plist->data, ">>") == 0)
    my_printf(" db.droite ");
  else if (my_strcmp(plist->data, "<<") == 0)
    my_printf(" db.gauche ");
  else if (my_strcmp(plist->data, "&&") == 0)
    my_printf(" etet ");
  else if (my_strcmp(plist->data, "||") == 0)
    my_printf(" pipepipe ");
  return (1);
}

t_list	*my_prio(t_list *list, t_node *plist)
{
  int	a;

  while (plist != NULL)
    {
      a = verif_prio(plist);
      if (a != 1)
	my_putstr(plist->data);
      plist = plist->p_nx1;
    }
  return (list);
}
