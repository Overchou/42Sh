/*
** pipes.c for 42 in /home/auffra_a/rendu/42sh/sources
** 
** Made by auffra_a
** Login   <auffra_a@epitech.net>
** 
** Started on  Fri May 16 14:16:43 2014 auffra_a
** Last update Fri May 16 14:51:51 2014 auffra_a
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

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

int	my_father(int pipefd[2], char **cmd2, char **path , char **env)
{
  char	*cmd;

  if ((cmd = my_check_access(cmd2[0], path)) == NULL)
    {
      my_putstr("Command not found\n");
      return (0);
    }
  close(pipefd[1]);
  if (dup2(pipefd[0], 0) == -1)
    return (-1);
  if (execve(cmd, cmd2, env) == -1)
    my_putstr("Command not found. Fuck you.\n");
  return (0);
}

int	my_exec_pipe(char **cmd1, char **cmd2, char **path , char **env)
{
  int	pipefd[2];
  int	pid;
  char	*cmd;

  if ((cmd = my_check_access(cmd1[0], path)) == NULL)
    {
      my_putstr("Command not found. Lol.\n");
      return (0);
    }
  if (pipe(pipefd) == -1)
    return (-1);
  if ((pid = fork()) == -1)
    return (-1);
  if (pid == 0)
    {
      close(pipefd[0]);
      if (dup2(pipefd[1], 1) == -1)
	return (-1);
      if (execve(cmd, cmd1, env) == -1)
        my_putstr("Command not found. Fuck.\n");
      return (0);
    }
  else
    {
      if (my_father(pipefd, cmd2, path, env) == -1)
	return (-1);
    }
  return (0);
}

int	my_pipe(char *cmd1, char *cmd2, char **path, char **env)
{
  char	**tab1;
  char	**tab2;
  int	i;

  i = 0;
  if ((tab1 = my_str_to_wordtab(cmd1)) == NULL)
    return (-1);
  if ((tab2 = my_str_to_wordtab(cmd2)) == NULL)
    return (-1);
  my_exec_pipe(tab1, tab2, path, env);
  /* my_free_tab(tab1); */
  /* my_free_tab(tab2); */
  return (0);
}

int	main(int argc, char **argv, char **env)
{
  char **path;
  char *pt = "/usr/bin/";

  path = my_str_to_wordtab(pt);
  my_pipe(argv[1], argv[2], path, env);
}
