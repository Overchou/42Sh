/*
** double_mredir.c for parser in /home/besnie_b/42Sh/Parser
** 
** Made by besnie_b
** Login   <besnie_b@epitech.net>
** 
** Started on  Fri May 23 15:32:00 2014 besnie_b
** Last update Fri May 23 16:13:22 2014 besnie_b
*/

/*
** WARNING ! CODE DANGEUREUX POUR LA VUE ET LE CERVEAU : NE PAS LE LIRE ^^
*/

int     func_double_norme(t_node *node, t_env *env, int pfd[])
{
  char  **cmd;

  cmd = my_str_to_wordtab(node->data);
  pid = fork();
  if (pid == 0)
    {
      close(pfd[0]);
      dup2(pfd[1], 1);
      my_check_access();
      execve(cmd[0], cmd, env);
      return (-3);
    }
  else
    ;
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

int	double_redir_left(t_node *node, t_env *env) // gauche
{
  
}
