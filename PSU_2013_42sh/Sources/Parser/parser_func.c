/*
** op_and_func.c for parser in /home/besnie_b/42Sh/Parser
**
** Made by besnie_b
** Login   <besnie_b@epitech.net>
**
** Started on  Sun May 18 14:13:38 2014 besnie_b
** Last update Sun May 25 21:22:51 2014 besnie_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "parser.h"

int	my_next_func(t_node *node, t_env *env)
{
  if (my_strcmp_strict(node->data, "|") == 0)
    mpipes_func(node, env);
  else if (my_strcmp_strict(node->data, ">") == 0)
    redir_right(node, env);
  else if (my_strcmp_strict(node->data, ">>") == 0)
    double_redir_right(node, env);
  else if (my_strcmp_strict(node->data, "<") == 0)
    redir_left(node, env);
  else if (my_strcmp_strict(node->data, "<<") == 0)
    double_redir_left(node, env);
  return (0);
}

int	my_op_pv_func(t_node *node, t_env *env)
{
  fallen_down_nx(node->p_nx1, env);
  fallen_down_nx(node->p_nx2, env);
  return (0);
}

int	my_op_and_func(t_node *node, t_env *env)
{
  if (fallen_down_nx(node->p_nx1, env) == 0 &&
      fallen_down_nx(node->p_nx2, env) == 0)
    return (0);
  else
    return (-1);
}

int	my_op_or_func(t_node *node, t_env *env)
{
  if (fallen_down_nx(node->p_nx1, env) == 0)
    return (0);
  else if (fallen_down_nx(node->p_nx1, env) == 0)
    return (0);
  else
    return (-1);
}
