/*
** cd_options.c for 42 in /home/auffra_a/rendu/42sh/sources
** 
** Made by auffra_a
** Login   <auffra_a@epitech.net>
** 
** Started on  Sun May 25 15:09:00 2014 auffra_a
** Last update Sun May 25 16:24:51 2014 auffra_a
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "cd.h"

char	*get_home(t_env *env)
{
  t_env *tmp;
  char *home;

  tmp = env;
  while (tmp != NULL)
    {
      if ((my_nncmp(tmp->value, "HOME=", 0)) == 0)
	{
	  home = my_ncpy(tmp->value, 5);
	  return (home);
	}
      tmp = tmp->next;
    }
  return (NULL);
}

t_env	*cd_home(t_env *env, char *directory)
{
  t_env *tmp;
  char *pwd;
  char *oldpwd;

  tmp = env;
  while (tmp != NULL)
    {
      if ((my_nncmp(tmp->value, "PWD=", 0)) == 0)
        {
          oldpwd = my_concat("OLDPWD ", my_ncpy(tmp->value, 4));
	  env = cd_go_home(env);
          pwd = my_concat("PWD ", my_concat(get_home(env), my_ncpy(directory, 1)));
	  directory = my_concat(get_home(env), my_ncpy(directory, 1));
          my_printf("\n%s\n%s\n", oldpwd, pwd);
	  //	  env = setenv(pwd, env);
	  //	  env = setenv(oldpwd, env);
          if ((chdir(my_ncpy(directory, 1))) != 0)
            {
              my_printf("vegash: cd: %s: Not a directory\n", directory);
              return (env);
            }
        }
      tmp = tmp->next;
    }
  return (env);
}


t_env	*cd_by_home(t_env *env, char *directory)
{
  t_env *tmp;
  char *pwd;
  char *oldpwd;

  tmp = env;
  while (tmp != NULL)
    {
      if ((my_nncmp(tmp->value, "PWD=", 0)) == 0)
	{
	  oldpwd = my_concat("OLDPWD ", my_ncpy(tmp->value, 4));
	  pwd = my_concat("PWD ", directory);
	  //	  env = setenv(pwd, env);
	  //	  env = setenv(oldpwd, env);
	  env = cd_go_home(env);
	  env = cd_prev(env);
	  my_printf("\n\n%s\n%s\n", oldpwd, pwd);
	  if ((chdir(my_ncpy(directory, 1))) != 0)
            {
              my_printf("vegash: cd: %s: Not a directory\n", directory);
              return (env);
            }
	}
      tmp = tmp->next;
    }
  return (env);
}

t_env	*cd_p(t_env *env, char *directory)
{
  if (directory == NULL)
    env = cd_go_home(env);
  else if ((my_nncmp(directory, get_home(env))) == 0)
    env = cd_by_home(env, directory);
  else
    env = cd_directory(env, directory);
  return (env);
}
