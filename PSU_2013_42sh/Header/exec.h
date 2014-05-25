/*
** exec.h for 42sh in /home/theven_d/rendu/42Sh/PSU_2013_42sh/Header
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Sun May 25 19:26:13 2014 theven_d
** Last update Sun May 25 19:28:44 2014 theven_d
*/

#include "env.h"

#ifndef EXEC_H
# define EXEC_H_

char    *my_check_access(char *arg, char **path);
char    **my_get_path(t_env *chain_env);
char    **tab_env(t_env *chain_env);


#endif
