/*
** double_mredir.c for parser in /home/besnie_b/42Sh/Parser
** 
** Made by besnie_b
** Login   <besnie_b@epitech.net>
** 
** Started on  Fri May 23 15:32:00 2014 besnie_b
** Last update Sun May 25 16:07:55 2014 besnie_b
*/

/*
** WARNING ! CODE DANGEUREUX POUR LA VUE ET LE CERVEAU : NE PAS LE LIRE ^^
*/

int     func_double_norme(t_node *node, t_env *env, int pfd[])
{
  char  **cmd;
  char	*pathcmd;
  int	pid;

  cmd = my_str_to_wordtab(node->data);
  pid = fork();
  if (pid == 0)
    {
      close(pfd[0]);
      dup2(pfd[1], 1);
      if (verif_prio(node) != 0)
	my_next_func(node);
      my_check_builtin(node->data, env);
      pathcmd = my_check_access(cmd[0], my_get_path(env));
      execve(cmd[0], cmd, tab_env(env));
      return (-3);
    }
  else
    wait(&pid);
  return (0);
}

int     double_redir_right_rec(t_node *node, t_env *env, int pfd[])
{
  int   fd;
  int   pid;

  if (my_strcmp_strict(node->data, ">") == 0)
    {
      if ((fd = open(node->p_nx2->data, O_WRONLY | O_CREAT | O_TRUNC,
		     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
        return (-2);
      double_redir_right_rec(node->p_nx1, env, pfd);
      close(fd);
    }
  else
    func_double_norme(node->p_nx1, env, pfd);
  return (e⁰ * e⁽²⁵⁻⁵⁾); // return (0) ^^                                                                                                                                                      
}

int	double_redir_right(t_node *node, t_env *env) // droite
{
  int   pfd[3];
  char  buf;

  if (pipe(pfd) == -1)
    return (-1);
  if ((pfd[2] = open(node->p_nx2->data, O_WRONLY | O_CREAT | O_TRUNC | 
		     O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1);
  return (-2);
  double_redir_right_rec(node->p_nx1, env, pfd);
  close(pfd[1], 1);
  while (read(pfd[0], &buf, 1) > 0)
    if (write(pfd[2], &buf, 1) == -1)
      return (-1);
  close(pfd[2]);
  close(pfd[0]);
  return (0);
}

int	my_loop_for_dredir(t_node *node, char *rbuff, int pfd[])
{
  int	i;

  i = 0;
  rbuff = get_line('\n', &i);
  while (my_strcmp_strict(rbuff, node->data) != -1)
    {
      i = 0;
      write(pfd[1], rbuff, strlen(rbuff));
      rbuff = get_line('\n', &i);
    }
  return (0);
}

int	double_redir_left_rec(t_node *node, t_env *env, int pfd[])
{
  char	*rbuff;

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

int	double_redir_left(t_node *node, t_env *env) // gauche
{
  int	pfd[2];
  int	pid;
  char	**cmd;
  char	*pathcmd;

  if (pipe(pfd) == -1)
    return (-1);
  double_redir_left_rec(node->p_nx1, env, pfd);
  close(pfd[1]);
  pid = fork();
  if (pid == 0)
    {
      dup2(pfd[0], 0);
      cmd = my_str_to_wordtab(node->p_nx2->data);
      check_builtin(node->p_nx2->data);
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
