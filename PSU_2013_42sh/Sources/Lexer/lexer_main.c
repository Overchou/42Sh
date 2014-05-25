/*
** main.c for main.c in /home/besnie_b/My_42sh
** 
** Made by besnie_b
** Login   <besnie_b@epitech.net>
** 
** Started on  Sat Apr 19 15:02:31 2014 besnie_b
** Last update Sun May 25 21:12:55 2014 besnie_b
*/

#include "lexer.h"

int	lexer_main(char *str)
{
  t_list *list;
  t_node *p_list;

  list = tlist_new();
  list = my_str_to_list(str, list);
  if (my_verif_syntax(list) == -1)
    return (0);
  p_list = list->p_start;
  p_list = my_prio(p_list);
  return (0);
}
