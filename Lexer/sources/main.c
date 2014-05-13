/*
** main.c for main.c in /home/besnie_b/My_42sh
** 
** Made by besnie_b
** Login   <besnie_b@epitech.net>
** 
** Started on  Sat Apr 19 15:02:31 2014 besnie_b
** Last update Thu May  8 18:06:54 2014 guenol_v
*/

#include "lexer.h"

int	main(int ac, char **av)
{
  char *str;
  t_list *list;
  struct node	*plist;

  if (ac == 1)
    return (0);
  str = my_epur_str(av[1]);
  list = tlist_new();
  list = my_str_to_list(str, list);
  if (my_verif_syntax(list) == -1)
    return (0);
  plist = list->p_start;
  list = my_prio(list, plist);
  return (0);
}