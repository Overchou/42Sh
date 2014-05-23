/*
** builtin.h for 42sh in /home/theven_d/rendu/42Sh/PSU_2013_42sh/Header
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Fri May 23 15:42:35 2014 theven_d
** Last update Fri May 23 18:13:49 2014 theven_d
*/

#include "env.h"

#ifndef BUILTIN_H_
# define BUILTIN_H_

void    my_aff_env(t_env *);
int     my_unsetenv(t_env *, char *);
int     check_builtin(char *, t_env *);
t_env   *my_setenv(char *, t_env *);

#endif
