/*
** pipes.c for parser in /home/besnie_b/42Sh/Parser/pipes
** 
** Made by besnie_b
** Login   <besnie_b@epitech.net>
** 
** Started on  Wed May 21 17:47:32 2014 besnie_b
** Last update Sun May 25 20:40:38 2014 besnie_b
*/

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "exec.h"
#include "parser.h"
#include "my.h"

int	pipe_counter(t_node *p_node)
{
  int	i;
  t_node *tmp;

  i = 1;
  tmp = p_node->p_nx1;
  while (my_strcmp_strict(tmp->data, "|") != -1)
    {
      i++;
      tmp = tmp->p_nx1;
    }
  return (i);
}

int	my_exec_son(int pfd[], t_node *node, t_env *env)
{
  char	*pathcmd;
  char	**cmd;

  pid = fork();
  if (pid == 0)
    {
      cmd = my_str_to_wordtab(node->data);
      dup2(pfd[0], 0);
      dup2(pfd[1], 1);
      pathcmd = my_check_access(cmd[0], my_get_path(env));
      execve(pathcmd, cmd, tab_env(env));
      return (-1);
    }
  else
    wait(&pid);
  return (0);
}

int	my_last_son(int pfd[], t_node *node, t_env *env)
{
  int	pid;
  char	**cmd;
  char	*pathcmd;

  if (ncmd == 1)
    {
      pid = fork();
      if (pid == 0)
	{
	  cmd = my_str_to_wordtab(node->data);
	  close(pfd[0]);
	  dup2(pdf[1], 1);
	  if (verif_prio(node->data) != 0)
	    my_next_func(node, env);
	  pathcmd = my_check_access(cmd[0], my_get_path(env));
	  execve(cmd[0], cmd, tab_env(env));
	  return (-1);
	}
      else
	wait(&pid);
      my_free_tab(cmd);
    }
  return (0);
}

int	my_next_son(int pfd[], int ncmd, t_node *node, t_env *env)
{
  int	pid;

  ncmd--;
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
  return (0);
}

int	my_first_son(int pfd[], int ncmd, t_node *node, t_env *t_env)
{
  int	pid;
  char	**cmd;
  char	*pathcmd;

  ncmd--;
  pid = fork();
  if (pid == 0)
    {
      cmd = my_str_to_wordtab(p_node->p_nx2->data);
      my_next_son(pfd, ncmd, node->p_nx1, t_env);
      dup2(pfd[0], 0);
      pathmcd = my_check_access(cmd[0], my_get_path(env));
      execve(cmd[0], cmd, teb_env(env));
      return (-1);
    }
  else
    wait(&wait);
  my_free_tab(cmd);
  return (0);
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
