/*
** my_en_list.c for my_env_list in /home/boutel_a/rendu/42sh
** 
** Made by boutel_a
** Login   <boutel_a@epitech.net>
** 
** Started on  Fri Apr 18 10:37:04 2014 boutel_a
** Last update Fri Apr 18 11:03:17 2014 boutel_a
*/

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

int	my_env_list(t_list **list)
{
  char	**s2;
  int	doors;
  extern char	**environ;

  doors = 0;
  s2 = environ;
  list = malloc(sizeof(*list));
  if (list == NULL)
    return (NULL);
  while (s2[doors] != NULL)
    {
      printf("envs2->%s\n", s2[doors]);
      my_put_in_list(list, s2[doors]);
      doors++;
    }
  my_show_list(list);
}

int	my_put_in_list(t_list **list, char *line)
{
  t_list	*maillon;
  maillon = malloc(sizeof(*maillon));
  if (maillon == NULL)
    return (1);
  maillon->val = line;
  maillon->next = *list;
  *list = maillon;
  return (0);
}

int	my_show_list(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      printf("%s\n", tmp->val);
      tmp = tmp->next;
    }
}

int	main()
{
  t_list	**list;
  my_env_list(list);  
}
