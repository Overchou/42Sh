/*
** main.c for 42sh in /home/theven_d/rendu/PSU_2013_minishell2/42sh
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Mon Apr 14 11:38:58 2014 theven_d
** Last update Sun May 25 21:21:18 2014 besnie_b
*/

#include <stdlib.h>
#include "builtin.h"
#include "main.h"
#include "env.h"
#include "free_fct.h"
#include "my.h"

int	my_loop(char **env)
{
  t_env	*chain_env;
  char	*buffer;
  int	a;

  a = 1;
  if (env != NULL)
    chain_env = my_env_in_list(env);
  while (a > 0)
    {
      our_magic_prompt(chain_env);
      my_signal();
      buffer = my_get_line('\n', &a, NULL, 0);
      buffer = my_epur_str(buffer, a);
      if (buffer != NULL)
	check_builtin(buffer, chain_env);
      a = 1;
      if (buffer == NULL)
	a = 0;
      free(buffer);
    }
  my_free_env(chain_env);
  free(buffer);
  return (0);
}

int     main(int ac, char **av, char **env)
{
  av = av;
  ac = my_loop(env);
  return (ac);
}
