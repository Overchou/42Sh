/*
** parser.h for 42sh in /home/theven_d/rendu/42Sh/PSU_2013_42sh/Header
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Sun May 25 19:01:48 2014 theven_d
** Last update Sun May 25 21:10:36 2014 besnie_b
*/

#include "lexer.h"
#include "env.h"

#ifndef PARCER_H_
# define PARCER_H_

int	fallen_down_nx(t_node *node, t_env *env);
int	mpipes_func(t_node *p_node, t_env *env);
int     redir_right(t_node *node, t_env *env);
int	redir_left(t_node *node, t_env *env);
int	double_redir_right(t_node *node, t_env *env);
int	double_redir_left(t_node *node, t_env *env);
int	verif_prio(t_node *plist);
int	my_op_pv_func(t_node *node, t_env *env);
int	my_op_and_func(t_node *node, t_env *env);
int	my_op_or_func(t_node *node, t_env *env);
int	my_next_func(t_node *node, t_env *env);
int     check_builtin(char *buffer, t_env *chain_env);
char    *my_get_line(char stop, int *a, char *result, int i);

#endif
