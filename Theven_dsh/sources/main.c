/*
** main.c for 42sh in /home/theven_d/rendu/PSU_2013_minishell2/42sh
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Mon Apr 14 11:38:58 2014 theven_d
** Last update Fri May 16 19:29:00 2014 theven_d
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char    *my_concat(char *result, char *recup , int i)
{
  char *tmp;
  int   j;
  int   k;

  j = 0;
  k = 0;
  if ((tmp = malloc(sizeof(*tmp) * (i + 1))) == NULL)
    return (NULL);
  if (result != NULL)
    {
      while (result[k] != '\0')
        {
          tmp[k] = result[k];
          k = k + 1;
        }
    }
  while (k < i)
    tmp[k++] = recup[j++];
  tmp[k] = '\0';
  return (tmp);
}

int     my_check_value(char value, char *str)
{
  int   i;

  i = 0;
  while (i < SIZE)
    {
      if (str[i] == value)
        return (i);
      i = i + 1;
    }
  return (0);
}

char    *my_get_line(char stop, int *a)
{
  int   i;
  int	b;
  char  *result;
  char  *recup;

  i = 0;
  if ((recup = malloc(sizeof(*recup) * (SIZE + 1))) == NULL)
    return (NULL);
  result = NULL;
  while ((b = read(0, recup, SIZE)) > 0)
    {
      *a += b;
      if (recup[0] == '\n')
	return (result);
      if ((b = my_check_value(stop, recup)) != 0)
        {
          i = i + b;
          result = my_concat(result , recup, i);
          return (result);
        }
      i = i + SIZE;
      result = my_concat(result , recup, i);
    }
  return (result);
}

static int	my_loop(char **env)
{
  t_env	*chain_env;
  char	*buffer;
  int	a;

  a = 0;
  if (env != NULL)
    chain_env = my_env_in_list(env);
  while (42)
    {
      my_putstr("$>");
      my_signal();
      buffer = my_get_line('\n', &a);
      if (a == 0 || a == -1)
	return (-1);
      buffer = my_epur_str(buffer, a);
      if (buffer != NULL && a != 1)
	check_cmd(buffer, chain_env);
      a = 0;
    }
  my_free_tab(env);
  return (0);
}

int     main(int ac, char **av, char **env)
{
  av = av;
  if ((ac = my_loop(env)) == -1)
    return (-1);
  return (0);
}
