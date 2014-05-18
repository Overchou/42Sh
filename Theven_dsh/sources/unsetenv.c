/*
** unsetenv.c for 42sh in /home/theven_d/rendu/PSU_2013_42sh/sources
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Fri Apr 18 19:44:42 2014 theven_d
** Last update Fri May 16 14:56:53 2014 theven_d
*/

#include <stdlib.h>
#include "my.h"

char	*my_str_capitalize(char *str)
{
  char	*res;
  int	i;

  i = 0;
  if ((res = my_strdupcpy(str)) == NULL)
    return (NULL);
  while (res[i] != '\0')
    {
      if (res[i] >= 97 && res[i] <= 122)
	res[i] = res[i] - 32;
      i = i + 1;
   }
  return (res);
}

void	reset_env(t_env *env)
{
  t_env	*tmp;

  tmp = env;
  while (tmp->next != NULL)
    {
      tmp->pos = tmp->pos - 1;
      tmp = tmp->next;
    }
  free(tmp);
}

int	my_cmp_env(char *venv, char *cmd)
{
  int	i;

  i = -1;
  while (cmd[++i] != '\0')
    if (venv[i] != cmd[i])
      return (1);
  if (venv[i] != '=')
    return (1);
  return (0);
}

int	my_unsetenv(t_env *env, char *cmd)
{
  t_env	*inte;
  t_env	*tmp;

  if (cmd == NULL)
    return (my_putstr("No arg for unsetenv\n"));
  cmd = my_str_capitalize(cmd);
  inte = env;
  tmp = env;
  while (inte != NULL)
    {
      if (my_cmp_env(inte->value, cmd) == 0)
	{
	  while (tmp->next != inte)
	    tmp = tmp->next;
	  tmp->next = inte->next;
	  reset_env(env);
	  my_printf("unsetenv success\n");
	  return (1);
	}
      inte = inte->next;
    }
  return (my_putstr("Don't find your command in env\n"));
}
