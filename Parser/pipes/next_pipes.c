/*
** next_pipes.c for parser.c in /home/besnie_b/42Sh/Parser/pipes
** 
** Made by besnie_b
** Login   <besnie_b@epitech.net>
** 
** Started on  Mon May 19 20:40:08 2014 besnie_b
** Last update Tue May 20 13:41:37 2014 besnie_b
*/

/*
** my_start_pipes /
** *************************************
*/

char	*my_next_pipe(char *nfo, char *cmd, t_env *env)
{
  char	*str;
  int	pipefd[2];
  int	pid;
  
  if (pipe(pipefd) == -1)
    return (NULL);
  if ((pid = fork()) == -1)
    return (NULL);
  
  if (pid == 0)
    {
      close(pipefd[1]);
      if (dup2(pipefd[0], 0) == -1)
	return (NULL);
      str = my_start_pipe(cmd, env);
      close(pipefd[0]);
    }
}
