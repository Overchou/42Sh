/*
** setenv.c for 42sh in /home/theven_d/rendu/PSU_2013_42sh/sources
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Fri Apr 25 17:29:51 2014 theven_d
** Last update Sat May 24 14:55:37 2014 theven_d
*/

#include <string.h>
#include <stdlib.h>
#include "env.h"
#include "setenv.h"
#include "my.h"

int	my_new_add(char **set, t_env *tmp)
{
  t_env	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (-1);
  new->pos = tmp->pos + 1;
  if ((new->value = concat_setenv(set[0], set[1])) == NULL)
    return (-1);
  tmp->next = new;
  new->next = NULL;
  return (0);
}

int	my_add(t_env *env, char **set)
{
  int	check;
  int	i;
  t_env	*tmp;

  tmp = env;
  i = 0;
  check = 1;
  if (set[2] != NULL)
    check = my_getnbr(set[2]);
  while (tmp != NULL)
    {
      if ((i = my_strcmpenv(tmp->value, set[0])) == 0)
	{
	  if (check != 0)
	    if ((tmp->value = concat_setenv(set[0], set[1])) == NULL)
	      return (-1);
	  return (1); 
	}
      if (tmp->next == NULL)
	return (my_new_add(set, tmp));
      tmp = tmp->next;
    }
  return (0);
}

t_env	*my_add_in_null_env(t_env *env, char **set)
{
  if ((env = malloc(sizeof(*env))) == NULL)
    return (NULL);
  env->pos = 0;
  if ((env->value = concat_setenv(set[0], set[1])) == NULL)
    return (NULL);
  env->next = NULL;
  return (env);
}

t_env	*my_setenv(char *str, t_env *env)
{
  char	**set;

  if (str == NULL || str[0] == '\0')
    return (NULL);
  if (((set = my_str_to_wordtab(str)) == NULL) || ((set[1] == NULL)) || (((set[0] = my_str_capitalize(set[0])) == NULL)))
    {
      my_free_tab(set);
      return (NULL);  
    }
  if (env == NULL)
    env = my_add_in_null_env(env, set);
  else
    my_add(env, set);
  my_free_tab(set);
  return (env);
}
