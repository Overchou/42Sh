/*
** setenv.c for 42sh in /home/theven_d/rendu/PSU_2013_42sh/sources
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Fri Apr 25 17:29:51 2014 theven_d
** Last update Thu May 22 20:44:40 2014 theven_d
*/

#include <string.h>
#include <stdlib.h>
#include "my.h"

char	*malloc_res(int check, char *name, char *value)
{
  int	lenname;
  int	lenval;
  int	i;
  char	*res;

  lenname = my_strlen(name);
  lenval = my_strlen(value);
  i = lenname + lenval + 1;
  if (check == 0)
    i += 1;
  if ((res = malloc(sizeof(*res) * i)) == NULL)
    return (NULL);
  return (res);
}

char	*concat_setenv(char *name, char *value)
{
  char	*res;
  int	check;
  int	i;

  check = 0;
  i = 0;
  if (value[0] == '=' || my_check_str('=', name) == 1)
    check = 1;
  if ((res = malloc_res(check, name, value)) == NULL)
    return (NULL);
  while (name[i] != '\0')
    {
      res[i] = name[i];
      i++;
    }
  if (check == 0)
    res[i++] = '=';
  check = 0;
  while (value[check] != '\0')
    res[i++] = value[check++];
  res[i] = '\0';
  my_printf("%s\n", res);
  return (res);
}

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

int	my_add(t_env *tmp, char **set)
{
  int	check;
  int	i;

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

t_env	*my_setenv(char *str, t_env *env)
{
  char	**set;
  t_env	*tmp;

  tmp = env;
  if (str == NULL || str[0] == '\0')
    return (NULL);
  if ((set = my_str_to_wordtab(str)) == NULL)
    return (NULL);
  if (set[1] == NULL)
    return (NULL);
  if ((set[0] = my_str_capitalize(set[0])) == NULL)
    return (NULL);
  if (env == NULL)
    {
      if ((env = malloc(sizeof(*env))) == NULL)
	return (-1);
      env->pos = 0;
      if ((env->value = concat_setenv(set[0], set[1])) == NULL)
	return (-1);
      env->next = NULL;
      printf("setenv->pos = %d\n", env->pos);
    }
  else
    my_add(tmp, set);
 return (env);
}
