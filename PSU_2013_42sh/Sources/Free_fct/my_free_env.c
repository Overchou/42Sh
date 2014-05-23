/*
** my_free_env.c for 42sh in /home/theven_d/rendu/42Sh/PSU_2013_42sh/Sources/Free_fct
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Thu May 22 19:38:30 2014 theven_d
** Last update Thu May 22 19:43:46 2014 theven_d
*/

#include <stdlib.h>
#include "env.h"

void	my_free_env(t_env *env)
{
  t_env	*tmp;

  tmp = env;
  while (tmp != NULL)
    {
      env = env->next;
      free(tmp);
      tmp = env;
    }
  free(tmp);
  free(env);
}
