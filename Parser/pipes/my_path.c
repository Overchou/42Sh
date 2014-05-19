/*
** my_path.c for minishell in /home/theven_d/rendu/PSU_2013_minishell1/sources
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Tue Feb 25 17:57:47 2014 theven_d
** Last update Tue Feb 25 18:53:38 2014 theven_d
*/

#include <stdlib.h>
#include "my.h"

char	**my_get_path(char **env)
{
  char	**path;
  int	i;
  int	j;

  i = 38;
  j = 0;
  while (env[i][j] != '\0')
    {
      if (env[i][j] == ':' || env[i][j] == '=')
	env[i][j] = ' ';
      j = j + 1;
    }
  path = my_str_to_wordtab(env[i]);
  return (path);
}
