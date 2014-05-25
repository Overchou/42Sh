/*
** redir.c for parser in /home/besnie_b/42Sh/Parser
** 
** Made by besnie_b
** Login   <besnie_b@epitech.net>
** 
** Started on  Thu May 22 18:04:28 2014 besnie_b
** Last update Sun May 25 19:41:21 2014 theven_d
*/

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "exec.h"
#include "parser.h"
#include "my.h"

int	redir_right_func_norme(t_node *node, t_env *env, int pfd[])
{
  char	**cmd;
  int   pid;
  char	*path_cmd;
  
  cmd = my_str_to_wordtab(node->data);
  pid = fork();
  if (pid == 0)
    {
      close(pfd[0]);
      dup2(pfd[1], 1);
      path_cmd = my_check_access(node->data, my_get_path(env));
      execve(path_cmd, cmd, tab_env(env));
      return (-3);
    }
  else
    wait(&pid);
  return (0);
}

int	redir_right_rec(t_node *node, t_env *env, int pfd[])
{
  int	fd;

  if (my_strcmp_strict(node->data, ">") == 0)
    {
      if ((fd = open(node->p_nx2->data, O_WRONLY | O_CREAT | O_TRUNC,
			 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
	return (-2);
      redir_right_rec(node->p_nx1, env, pfd);
      close(fd);
    }
  else
    redir_right_func_norme(node->p_nx1, env, pfd);
  return (0); 
}

int     redir_right(t_node *node, t_env *env)
{
  int	pfd[3];
  char	buf;

  if (pipe(pfd) == -1)
    return (-1);
  if ((pfd[2] = open(node->p_nx2->data, O_WRONLY | O_CREAT | O_TRUNC, 
		     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    return (-2);
  redir_right_rec(node->p_nx1, env, pfd);
  close(pfd[1]);
  while (read(pfd[0], &buf, 1) > 0)
    if (write(pfd[2], &buf, 1) == -1)
      return (-1);
  close(pfd[2]);
  close(pfd[0]);
  return (0);
}

int	redir_left_func_norme(t_node *node, int pfd[])
{
  int	fd;
  char	buff;

  if ((fd = open(node->data, O_RDONLY)) == -1)
    return (-2);
  dup2(pfd[1], 1);
  if (read(fd, &buff, 1) > 0)
    if (write(pfd[1], &buff, 1) == -1)
      return (-1);
  close(fd);
  return (0);
}

int	redir_left_rec(t_node *node, int pfd[])
{
  int	fd;

  if (my_strcmp_strict(node->data, ">") == 0)
    {
      if ((fd = open(node->p_nx2->data, O_RDONLY)) == -1)
	return (-2);
      redir_left_rec(node->p_nx1, pfd);
      close(fd);
    }
  else
    redir_left_func_norme(node, pfd);
  return (0);
}

int	redir_left(t_node *node, t_env *env)
{
  int	pfd[2];
  char	**cmd;
  char	*path_cmd;
  int	pid;

  if (pipe(pfd) == -1)
    return (-1);
  redir_left_rec(node->p_nx1, pfd);
  close(pfd[1]);
  pid = fork();
  if (pid == 0)
    {
      cmd = my_str_to_wordtab(node->p_nx2->data);
      dup2(pfd[0], 0);
      path_cmd = my_check_access(node->p_nx2->data, my_get_path(env));
      execve(path_cmd, cmd, tab_env(env));
      return (-3);
    }
  else
    wait(&pid);
  return (0);
}
