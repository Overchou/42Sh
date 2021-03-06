/*
** my_exec.c for 42sh in /home/theven_d/rendu/42Sh/PSU_2013_42sh/Sources/Execution
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Sat May 24 18:23:05 2014 theven_d
** Last update Sat May 24 23:17:27 2014 theven_d
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "env.h"
#include "my.h"

char    *concat_path(char *str, char *str2)
{
  int   len;
  int   len2;
  char  *result;
  int   i;

  i = 0;
  len = strlen(str) + 1;
  len2 = strlen(str2);
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
  if ((check = access(arg, F_OK)) == 0)
    return (arg);
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

char	**my_get_path(t_env *chain_env)
{
  char	**path;
  char	*inte;
  int	i;
  t_env	*env;

  i = -1;
  env = chain_env;
  while (env != NULL)
    {
      if (my_nncmp(env->value, "PATH=", 0) == 0)
	{
	  if ((inte = strdup(env->value)) == NULL)
	    return (NULL);
	  while (inte[++i] != '\0')
	    if (inte[i] == ':' || inte[i] == '=')
	      inte[i] = ' ';
	  if ((path = my_str_to_wordtab(inte)) == NULL)
	    return (NULL);
	  free(inte);
	  return (path);
	}
      env = env->next;
    }
  return (NULL);
}

char	**tab_env(t_env *chain_env)
{
  char	**ennv;
  t_env	*tmp;
  int	i;
  int	len;

  i = 0;
  tmp = chain_env;
  while (tmp->next != NULL)
    tmp = tmp->next;
  if ((ennv = malloc(sizeof(*ennv) * (tmp->pos + 1))) == NULL)
    return (NULL);
  tmp = chain_env;
  while (tmp->next != NULL)
    {
      len = strlen(tmp->value);
      if ((ennv[i] = malloc(sizeof(char) * (len + 1))) == NULL)
	return (NULL);
      ennv[i] = strcpy(ennv[i], tmp->value);
      i += 1;
      tmp = tmp->next;
    }
  ennv[i] = NULL;
  return (ennv);
}

int	my_exec(char *buffer, t_env *chain_env)
{
  char  **arg;
  char	**path;
  char  *cmd;
  pid_t pid;
  int   status;

  status = 0;
  if ((path = my_get_path(chain_env)) == NULL)
    return (my_putstr("No Path\n"));
  if ((arg = my_str_to_wordtab(buffer)) == NULL)
    return (my_printf("Error S_t_W\n"));
  if ((cmd = my_check_access(arg[0], path)) == NULL)
    return (my_printf("%s : Command not found\n", buffer));
  pid = vfork();
  if (pid == 0)
    {
      if (execve(cmd, arg, tab_env(chain_env)) == -1)
	my_printf("%s : Command not found\n", buffer);
      return (0);
    }
  else
    wait(&status);
  my_free_tab(arg);
  return (0);
}
