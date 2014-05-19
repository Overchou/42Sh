/*
** check_builtin.c for 42sh in /home/theven_d/rendu/PSU_2013_42sh/sources
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Sat Apr 26 16:39:35 2014 theven_d
** Last update Mon May 19 17:54:05 2014 theven_d
*/

#include <stdlib.h>
#include "my.h"

char	*my_cut_chain(char *str)
{
  int	i;
  int	len;
  char	*recup;

  i = -1;
  len = 0;
  while (str[++i] != ' ')
    if (str[i] == '\0')
      return (NULL);
  while (str[i++] != '\0')
    len++;
  if ((recup = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  i = i - len;
  len = 0;
  while (str[i] != '\0')
    recup[len++] = str[i++];
  recup[len] = '\0';
  return (recup);
}

int	check_cmd(char *buffer, t_env *chain_env)
{
  char	*tmp;
  int	i;

  tmp = my_cut_chain(buffer);
  if (my_nncmp(buffer, "unsetenv", 0) == 0)
    my_unsetenv(chain_env, tmp);
  else if (my_nncmp(buffer, "setenv", 0) == 0)
    {
      if (chain_env == NULL)
	my_putstr("NULL\n");
      chain_env =  my_setenv(tmp, chain_env);
      my_putchar('a');
      my_printf("chain_env->pos = %d\n", chain_env->pos);
      my_putchar('b');
    }
  else if (my_nncmp(buffer, "env", 0) == 0)
    my_aff_env(chain_env);
  else
    my_fork(buffer, chain_env);
  return (0);
}
