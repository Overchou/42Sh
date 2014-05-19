/*
** liste_tri_c2.c for liste_tri_c2.c in /home/besnie_b/My_42sh
**
** Made by besnie_b
** Login   <besnie_b@epitech.net>
**
** Started on  Thu Apr 24 10:56:12 2014 besnie_b
** Last update Mon May 19 15:03:24 2014 besnie_b
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "lexer.h"

/*
** Fonction supprimant une node de la liste chainée, en nième position
*/

t_list   *node_delete1(t_list *p_list, int pos)
{
  t_node *p_tmp;
  int   i;

  if (p_list != NULL)
    {
      p_tmp = p_list->p_start;
      i = 1;
      while (p_tmp != NULL && i <= pos)
        {
          if (pos == i)
            node_delete2(p_list, p_tmp);
          else
            p_tmp = p_tmp->p_nx1;
          i++;
        }
    }
  return (p_list);
}

/*
** Necessaire pour avoir une fonction à la norme
*/

void	node_delete2(t_list *p_list, t_node *p_tmp)
{
  if (p_tmp->p_nx1 == NULL)
    {
      p_list->p_end = p_tmp->p_prev;
      p_list->p_end->p_nx1 = NULL;
    }
  else if (p_tmp->p_prev == NULL)
    {
      p_list->p_start = p_tmp->p_nx1;
      p_list->p_start->p_prev = NULL;
    }
  else
    {
      p_tmp->p_nx1->p_prev = p_tmp->p_prev;
      p_tmp->p_prev->p_nx1 = p_tmp->p_nx1;
    }
  p_list->length--;
}

/*
** Prend en paramètre une node et renvoie un clone
*/

t_node	*tnode_dup(t_node *p_node)
{
  t_node *p_dup;

  if (p_node->data != NULL)
    {
      if ((p_dup = malloc(sizeof(*p_dup))) == NULL)
	return (0);
      if (p_dup != NULL)
	{
	  p_dup->data = p_node->data;
	  p_dup->type = p_node->type;
	  p_dup->p_nx1 = NULL;
	  p_dup->p_nx2 = NULL;
	  p_dup->p_prev = NULL;
	}
      return (p_dup);
    }
  return (NULL);
}
