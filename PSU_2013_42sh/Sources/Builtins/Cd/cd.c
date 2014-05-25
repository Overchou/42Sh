/*
** cd.c for 42sh in /home/theven_d/rendu/42Sh/PSU_2013_42sh
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Sun May 25 16:50:49 2014 theven_d
** Last update Sun May 25 16:51:39 2014 theven_d
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "cd.h"
#include "env.h"

t_env	*cd_prev(t_env *env)
{
  char *oldpwd;
  char *pwd;

  if ((oldpwd = cd_pwding(env)) == NULL)
    return (NULL);
  if ((pwd = cd_lesspwd(env)) == NULL)
    return (NULL);
  if ((chdir("..")) != 0)
    return (env);
  env = my_setenv(pwd, env);
  env = my_setenv(oldpwd, env);
  return (env);
}

t_env	*cd_minus(t_env *env)
{
  t_env *tmp;
  char *pwd;
  char *oldpwd;

  tmp = env;
  if ((oldpwd = cd_pwding(env)) == NULL)
    return (NULL);
  while (tmp != NULL)
    {
      if ((my_nncmp(tmp->value, "OLDPWD=", 0)) == 0)
	{
	  pwd = my_ncpy(tmp->value, 7);
	  if ((chdir(pwd)) != 0)
	    return (env);
	  pwd = my_concat_cd("PWD ", pwd);
	  env = my_setenv(pwd, env);
	  env = my_setenv(oldpwd, env);
	  return (env);
	}
      tmp = tmp->next;
    }
  my_printf("No oldpwd available.\n");
  return (env);
}

t_env	*cd_directory(t_env *env, char *directory)
{
  t_env *tmp;
  char *pwd;
  char *oldpwd;

  tmp = env;
  while (tmp != NULL)
    {
      if ((my_nncmp(tmp->value, "PWD=", 0)) == 0)
	{
	  oldpwd = my_ncpy(tmp->value, 4);
	  pwd = my_concat_cd("PWD ", my_concat_cd(my_concat_cd(oldpwd, "/")
						  , directory));
	  oldpwd = my_concat_cd("OLDPWD ", oldpwd);
	  if ((chdir(directory)) != 0)
	    {
	      my_printf("vegash: cd: %s: Not a directory\n", directory);
	      return (env);
	    }
	  env = my_setenv(pwd, env);
	  env = my_setenv(oldpwd, env);
	  return (env);
	}
      tmp = tmp->next;
    }
  return (env);
}

t_env   *cd_go_home(t_env *env)
{
  t_env *tmp;
  char *home;
  char *oldpwd;
  char *pwd;

  tmp = env;
  while (tmp != NULL)
    {
      if ((my_nncmp(tmp->value, "HOME=", 0)) == 0)
        {
          home = my_ncpy(tmp->value, 5);
          pwd = my_concat_cd("PWD ", home);
          chdir(home);
        }
      if ((my_nncmp(tmp->value, "PWD=", 0)) == 0)
        oldpwd = my_concat_cd("OLDPWD ", my_ncpy(tmp->value, 4));
      tmp = tmp->next;
    }
  env = my_setenv(oldpwd, env);
  env = my_setenv(pwd, env);
  return (env);
}

t_env   *shell_cd(t_env *env, char *directory)
{
  if (directory == NULL)
    {
      env = cd_go_home(env);
      return (env);
    }
  if ((my_nncmp(directory, "..", 0)) == 0)
    env = cd_prev(env);
  else if ((my_nncmp(directory, "~", 0)) == 0)
    env = cd_home(env, directory);
  else if ((my_nncmp(directory, "-L", 0)) == 0)
    env = cd_directory(env, my_ncpy(directory, 3));
  else if ((my_nncmp(directory, "-P", 0)) == 0)
    env = cd_p(env, my_ncpy(directory, 3));
  else if ((my_nncmp(directory, "/home/", 0)) == 0)
    env = cd_by_home(env, directory);
  else if ((my_nncmp(directory, "-", 0)) == 0)
    env = cd_minus(env);
  else
    env = cd_directory(env, directory);
  return (env);
}
