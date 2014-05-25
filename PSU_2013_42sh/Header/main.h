/*
** main.h for 42sh in /home/theven_d/rendu/42Sh/PSU_2013_42sh/Header
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Tue May 20 16:01:23 2014 theven_d
** Last update Sun May 25 21:45:10 2014 besnie_b
*/

#include "env.h"

#ifndef MAIN_H_
# define MAIN_H_

#define SIZE	5

char    *my_get_line(char stop, int *a, char *result, int i);
void    our_magic_prompt(t_env *env);
void	my_signal();

#endif
