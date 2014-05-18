/*
** pipes.c for 42 in /home/auffra_a/rendu/42sh/sources
** 
** Made by auffra_a
** Login   <auffra_a@epitech.net>
** 
** Started on  Fri May 16 14:16:43 2014 auffra_a
** Last update Sun May 18 14:51:31 2014 auffra_a
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void    my_free_tab(char **tab)
{
  int   i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i = i + 1;
    }
  free(tab);
}

char    *concat_path(char *str, char *str2)
{
  int   len;
  int   len2;
  char  *result;
  int   i;

  i = 0;
  len = my_strlen(str) + 1;
  len2 = my_strlen(str2);
  if ((result = malloc((len + len2 + 2) * sizeof(*result))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      result[i] = str[i];
      i = i + 1;
    }
  result[i] = '/';
  i = 0;
  while (str2[i] != '\0')
    {
      result[len] = str2[i];
      len = len  + 1;
      i = i + 1;
    }
  result[len] = '\0';
  return (result);
}

char    *my_check_access(char *arg, char **path)
{
  int   check;
  char  *recup;
  int   i;

  i = 0;
  check = 0;
  while (path[i] != NULL)
    {
      recup = concat_path(path[i], arg);
      check = access(recup, F_OK);
      if (check == 0)
        return (recup);
      i = i + 1;
      free(recup);
    }
  return (NULL);
}

char	*get_pipe_str(int pipefd[2], char *strpipe)
{
  int n;
  char buf;

  n = -1;
  close(pipefd[1]);
  while (read(pipefd[0], &buf, 1) > 0)
    strpipe[++n] = buf;
  close(pipefd[0]);
  return (strpipe);
}

char	*my_exec_pipe(char **cmd1, char **path , char **env, char *strpipe)
{
  int	pipefd[2];
  int	pid;
  char	*cmd;

  if ((cmd = my_check_access(cmd1[0], path)) == NULL)
    {
      my_putstr("Command not found. Lol.\n");
      return (NULL);
    }
  if (pipe(pipefd) == -1)
    return (NULL);
  if ((pid = fork()) == -1)
    return (NULL);
  if (pid == 0)
    {
      close(pipefd[0]);
      if (dup2(pipefd[1], 1) == -1)
	return (NULL);
      if (execve(cmd, cmd1, env) == -1)
        my_putstr("Command not found. Fuck.\n");
      return (NULL);
    }
  else
    strpipe = get_pipe_str(pipefd, strpipe);
  free(cmd);
  return (strpipe);
}

char	*my_pipe(char *cmd1, char **path, char **env, char *strpipe)
{
  char	**tab1;

  if ((tab1 = my_str_to_wordtab(cmd1)) == NULL)
    return (NULL);
  strpipe = my_exec_pipe(tab1, path, env, strpipe);
  my_free_tab(tab1);
  return (strpipe);
}

int	main(int argc, char **argv, char **env)
{
  char **path;
  char *pt = "/usr/bin/";
  char *strpipe;

  if ((strpipe = malloc(sizeof(*strpipe) * 5000)) == NULL)
    return (0);
  path = my_str_to_wordtab(pt);
  strpipe = my_pipe(argv[1], path, env, strpipe);
  my_putstr(strpipe);
  my_free_tab(path);
  free(strpipe);
  return (0);
}
