/*
** check_builtin.c for 42sh in /home/theven_d/rendu/PSU_2013_42sh/sources
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Sat Apr 26 16:39:35 2014 theven_d
** Last update Sun May 25 16:13:50 2014 theven_d
*/

#include <stdlib.h>
#include "builtin.h"
#include "env.h"
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

int	check_builtin(char *buffer, t_env *chain_env)
{
  char	*tmp;

  tmp = my_cut_chain(buffer);
  if (my_nncmp(buffer, "unsetenv", 0) == 0)
    my_unsetenv(chain_env, tmp);
  else if (my_nncmp(buffer, "setenv", 0) == 0)
    chain_env = my_setenv(tmp, chain_env);
  else if (my_nncmp(buffer, "env", 0) == 0)
    my_aff_env(chain_env);
  else if (my_nncmp(buffer, "echo", 0) == 0)
    builtin_echo(tmp);
  else if (my_nncmp(buffer, "cd", 0) == 0)
    chain_env = shell_cd(chain_env, tmp);
  /*else if (my_nncmp(buffer, "exit", 0) == 0)
    chain_env = my_exit(tmp);*/
  else
    my_exec(buffer, chain_env);
  return (0);
}
