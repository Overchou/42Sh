/*
** double_mredir_left.c for double_mredir_left in /home/besnie_b/42Sh/PSU_2013_42sh/Sources/Parser
** 
** Made by besnie_b
** Login   <besnie_b@epitech.net>
** 
** Started on  Sun May 25 21:36:01 2014 besnie_b
** Last update Sun May 25 21:38:54 2014 besnie_b
*/

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "exec.h"
#include "parser.h"
#include "my.h"

int     my_loop_for_dredir(t_node *node, char *rbuff, int pfd[])
{
  int   i;

  i = 0;
  rbuff = my_get_line('\n', &i, NULL, 0);
  while (my_strcmp_strict(rbuff, node->data) != -1)
    {
      i = 0;
      write(pfd[1], rbuff, strlen(rbuff));
      rbuff = my_get_line('\n', &i, NULL, 0);
    }
  return (0);
}

int     double_redir_left_rec(t_node *node, t_env *env, int pfd[])
{
  char  *rbuff;

  rbuff = NULL;
  if (my_strcmp_strict(node->p_nx1->data, "<<") == 0)
    {
      my_loop_for_dredir(node->p_nx2, rbuff, pfd);
      double_redir_left_rec(node->p_nx1, env, pfd);
    }
  else
    {
      my_loop_for_dredir(node->p_nx1, rbuff, pfd);
      return (0);
    }
  return (0);
}

int     double_redir_left(t_node *node, t_env *env)
{
  int   pfd[2];
  int   pid;
  char  **cmd;
  char  *pathcmd;

  if (pipe(pfd) == -1)
    return (-1);
  double_redir_left_rec(node->p_nx1, env, pfd);
  close(pfd[1]);
  pid = fork();
  cmd = my_str_to_wordtab(node->p_nx2->data);
  if (pid == 0)
    {
      dup2(pfd[0], 0);
      check_builtin(node->p_nx2->data, env);
      pathcmd = my_check_access(cmd[0], my_get_path(env));
      execve(pathcmd, cmd, tab_env(env));
      return (-3);
    }
  else
    wait(&pid);
  my_free_tab(cmd);
  close(pfd[0]);
  return (0);
}
