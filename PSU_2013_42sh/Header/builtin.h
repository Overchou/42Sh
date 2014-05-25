/*
** builtin.h for 42sh in /home/theven_d/rendu/42Sh/PSU_2013_42sh/Header
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Fri May 23 15:42:35 2014 theven_d
** Last update Sun May 25 15:34:42 2014 theven_d
*/

#include "env.h"

#ifndef BUILTIN_H_
# define BUILTIN_H_

void    my_aff_env(t_env *);
void    builtin_echo(char *);
int     my_unsetenv(t_env *, char *);
int     check_builtin(char *, t_env *);
int     my_exec(char *, t_env *);
t_env   *my_setenv(char *, t_env *);
t_env   *shell_cd(t_env *, char *);

#endif
