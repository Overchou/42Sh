/*
** pipes.c for parser in /home/besnie_b/42Sh/Parser/pipes
** 
** Made by besnie_b
** Login   <besnie_b@epitech.net>
** 
** Started on  Wed May 21 17:47:32 2014 besnie_b
** Last update Thu May 22 17:52:54 2014 besnie_b
*/

#include <unistd.h>

int	pipe_counter(t_node *p_node)
{
  int	i;
  t_node *tmp;

  i = 1;
  tmp = p_node->p_nx1;
  while (my_strcmp_strict(tmp->data, "|"))
    {
      i++;
      tmp = tmp->p_nx1;
    }
  return (i);
}

int	my_exec_son(int pfd[], t_node *node, t_env *env)
{
  pid = fork;
  if (pid == 0)
    {
      dup2(pfd[0], 0);
      dup2(pfd[1], 1);
      my_check_access(cmd[0], cmd);
      execve(cmd[0], cmd, my_get_path(env));
      return (-1);
    }
  else
    ;
  return (0);
}

int	my_last_son(int pfd[], t_node *node, t_env *env)
{
  int	pid;
  char	**cmd;

  if (ncmd == 1)
    {
      pid = fork();
      if (pid == 0)
	{
	  cmd = my_str_to_wordtab();
	  dup2(pdf[1], 1);
	  my_check_access(cmd[0], 0);
	  execve(cmd[0], cmd, env);
	  return (-1);
	}
      else
	;
      my_free_tab(cmd);
    }
  return (0);
}

int	my_next_son(int pfd[], int ncmd, t_node *node, t_env *env)
{
  int	pid;
  char	**cmd;

  ncmd--;
  cmd = my_str_to_wordtab(p_node->p_nx2);
  if (ncmd > 1)
    {
      my_next_son(pfd, ncmd, node->p_nx1, env);
      my_exec_son(pfd, node->p_nx2, env);
    }
  else if (ncmd == 1)
    {
      my_last_son(pfd, node->p_nx1, env);
      my_exec_son(pfd, node->p_nx2, env);
    }
  my_free_tab(cmd);
}

int	my_first_son(int pfd[], int ncmd, t_node *node, t_env *t_env)
{
  int	pid;
  char	**cmd;

  ncmd--;
  pid = fork();
  if (pid == 0)
    {
      cmd = my_str_to_wordtab(p_node->p_nx2);
      my_check_access(cmd[0], my_get_path(env));
      my_next_son(pfd, ncmd, node->p_nx1, t_env);
      dup2(pfd[0], 0);
      execve(cmd[0], cmd, my_get_path(env));
      return (-1);
    }
  else
    ;
  my_free_tab(cmd);
}

int	mpipes_func(t_node *p_node, t_env *env)
{
  int	pfd[2];
  int	heritage;

  heritage = 0;
  if (pipe(pfd) == -1)
    return (-1);
  heritage = pipe_counter(p_node) + 1;
  my_first_son(pfd, heritage, p_node, t_env);
  return (0);
}
