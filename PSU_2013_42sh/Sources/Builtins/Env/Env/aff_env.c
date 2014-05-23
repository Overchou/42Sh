/*
** aff_env.c for 42sh in /home/theven_d/rendu/42Sh/PSU_2013_42sh/Sources/Builtins/Env/Env
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Fri May 23 14:18:19 2014 theven_d
** Last update Fri May 23 15:13:40 2014 theven_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "env.h"

void    my_aff_env(t_env *env)
{
  t_env *tmp;

  tmp = env;
  while (tmp != NULL)
    {
      printf("%s\n", tmp->value);
      tmp = tmp->next;
    }
  free(tmp);
}
