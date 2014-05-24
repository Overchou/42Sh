/*
** env.h for 42sh in /home/theven_d/rendu/42Sh/PSU_2013_42sh/Header
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Tue May 20 16:00:57 2014 theven_d
** Last update Sat May 24 14:38:49 2014 theven_d
*/

#ifndef ENV_H_
# define ENV_H_

typedef struct s_env
{
  int   pos;
  char  *value;
  struct s_env *next;
}t_env;

typedef struct s_chain
{
  t_env *begin;
  t_env *end;
}t_chain;

t_env   *my_env_in_list(char **);

#endif
