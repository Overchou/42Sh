/*
** verif_syntaxe.c for lexer in /home/besnie_b/My_42sh
** 
** Made by besnie_b
** Login   <besnie_b@epitech.net>
** 
** Started on  Wed May  7 13:48:07 2014 besnie_b
** Last update Fri May 16 15:16:47 2014 besnie_b
*/

#include <stdlib.h>
#include <stdio.h>
#include "lexer.h"

int	check_sytx(char	*str, int type)
{
  if (type == 0)
    return (0);
  if (type == 1)
    if (check_op(str) == -1)
      return (-1);
  if (type == 2)
    if (check_redir(str) == -1)
      return (-1);
  if (type == 3)
    if (check_exclu(str) == -1)
      return (-1);
  if (type == 4)
    if (check_stop(str) == -1)
      return (-1);
  return (0);
}

int	my_verif_loop(t_list *list)
{
  t_node *p_new;

  p_new = list->p_start;
  while (p_new != NULL)
    {
      if (p_new->type > 0)
	if (check_sytx(p_new->data, p_new->type) == -1)
	  {
	    printf("%s : Bad syntax\n", p_new->data);
	    return (-1);
	  }
      p_new = p_new->p_nx1;
    }
  return (0);
}

int	my_verif_syntax(t_list *list)
{
  if (my_verif_loop(list) < 0)
    return (-1);
  return (0);
}
