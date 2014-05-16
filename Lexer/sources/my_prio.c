/*
** my_prio.c for my_prio in /home/guenol_v/rendu/42sh/sources
**
** Made by guenol_v
** Login   <guenol_v@epitech.net>
**
** Started on  Tue Apr 22 15:29:26 2014 guenol_v
** Last update Fri May 16 18:38:50 2014 guenol_v
*/

#include <stdlib.h>
#include "lexer.h"
#include "my.h"


t_node	*my_other_prio(t_node *plist, t_node *next)
{
  
  return (plist);
}

int	my_db_verif(t_node *plist, t_node *next)
{
  if (my_strcmp(plist->data, ">>") == 0)
    my_printf(" db.droite ");
  else if (my_strcmp(plist->data, "<<") == 0)
    my_printf(" db.gauche ");
  else if (my_strcmp(plist->data, "&&") == 0)
    my_printf(" etet ");
  else if (my_strcmp(plist->data, "||") == 0)
    my_printf(" pipepipe ");
  return (plist);
}

plist	*verif_prio(t_node *plist, t_node *next)
{
  if (my_strcmp(plist->data, ";") == 0)
    my_printf(" virg ");
  else if (my_strcmp(plist->data, "|") == 0)
    my_printf(" pipe ");
  else if (my_strcmp(plist->data, ">") == 0)
    my_printf(" droite ");
  else if (my_strcmp(plist->data, "<") == 0)
    my_printf(" gauche ");
  plist = my_db_verif(plist, next);
  return (plist);
}

t_list	*my_prio(t_list *list, t_node *plist)
{
  int	a;

  while (plist != NULL)
    {
      a = verif_prio(plist, plist->p_nx1);
      plist = plist->p_nx1;
    }
  return (list);
}
