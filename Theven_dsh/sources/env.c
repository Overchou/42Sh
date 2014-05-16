/*
** env.c for 42sh in /home/theven_d/rendu/PSU_2013_42sh/sources
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Wed Apr 16 17:32:38 2014 theven_d
** Last update Wed May 14 14:54:35 2014 theven_d
*/

#include <stdlib.h>
#include "my.h"

int	new_struct(t_chain *chain, char *str)
{
  t_env *new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (-1);
  new->next = NULL;
  new->value = str;
  if (chain->begin == NULL)
    {
      new->pos = 0;
      chain->begin = new;
    }
  else
    {
      new->pos = chain->end->pos + 1;
      chain->end->next = new;
    }
  chain->end = new;
  return (0);
}

t_env	*my_env_in_list(char **av)
{
  t_chain	*chain;
  int	i;

  i = 0;
  if ((chain = malloc(sizeof(*chain))) == NULL)
    return (NULL);
  chain->begin = NULL;
  chain->end = NULL;
  while (av[i] != NULL)
    {
      new_struct(chain, av[i]);
      i = i + 1;
    }
  return (chain->begin);
}

void	my_aff_env(t_env *env)
{
  t_env	*tmp;

  tmp = env;
  while (tmp != NULL)
    {
      my_printf("%s\n", tmp->value);
      tmp = tmp->next;
    }
  free(tmp);
}
