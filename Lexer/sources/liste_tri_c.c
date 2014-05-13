/*
** liste_tri_c.c for liste_tri_c in /home/besnie_b/My_42sh
**
** Made by besnie_b
** Login   <besnie_b@epitech.net>
**
** Started on  Thu Apr 17 18:48:25 2014 besnie_b
** Last update Wed May  7 15:14:49 2014 besnie_b
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "lexer.h"

/*
** Créer une liste qui sauvegarde la liste chainée
*/

t_list   *tlist_new(void)
{
  t_list *p_new;

  p_new = malloc(sizeof (*p_new));
  if (p_new == NULL)
    return (0);
  if (p_new != NULL)
    {
      p_new->length = 0;
      p_new->p_start = NULL;
      p_new->p_end = NULL;
    }
  return (p_new);
}

/*
** Ajout d'une node dans la liste chainée (MAJ de la liste de pointeur)
*/

t_list   *tlist_append(t_list *p_list, char *data, int type)
{
  struct node *p_new;

  if (p_list != NULL)
    {
      p_new = malloc(sizeof (*p_new));
      if (p_new == NULL)
        return (0);
      if (p_new != NULL)
        {
          p_new->data = data;
	  p_new->type = type;
          p_new->p_nx1 = NULL;
	  p_new->p_nx2 = NULL;
          p_list = tlist_append2(p_list, p_new);
          p_list->length++;
        }
    }
  return (p_list);
}

t_list   *tlist_append2(t_list *p_list, struct node *p_new)
{
  if (p_list->p_end == NULL)
    {
      p_new->p_prev = NULL;
      p_list->p_end = p_new;
      p_list->p_start = p_new;
    }
  else
    {
      p_list->p_end->p_nx1 = p_new;
      p_new->p_prev = p_list->p_end;
      p_list->p_end = p_new;
    }
  return (p_list);
}

/*
** Affiche la liste chainée entièrement
*/

void    tlist_display(t_list *p_list)
{
  struct node *p_tmp;

  if (p_list != NULL)
    {
      p_tmp = p_list->p_start;
      while (p_tmp != NULL)
        {
          printf("%s$", p_tmp->data);
	  p_tmp = p_tmp->p_nx1;
        }
    }
  printf("NULL\n");
}
