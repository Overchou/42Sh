/*
** my_free_env_ptr.c for 42sh in /home/theven_d/rendu/42Sh/PSU_2013_42sh/Sources/Free_fct
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Wed May 21 21:48:37 2014 theven_d
** Last update Wed May 21 22:12:09 2014 theven_d
*/

#include <stdlib.h>
#include "env.h"

void	my_free_env_ptr(t_env *tmp)
{
  tmp = NULL;
  free(tmp);
}
