/*
** cd.c for 42 in /home/auffra_a/rendu/42sh/sources
** 
** Made by auffra_a
** Login   <auffra_a@epitech.net>
** 
** Started on  Thu May 22 18:11:39 2014 auffra_a
** Last update Sun May 25 00:23:16 2014 auffra_a
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "cd.h"
 
t_env	*cd_prev(t_env *env)
{
  char *oldpwd;
  char *pwd;

  if ((oldpwd = cd_pwding(env)) == NULL)
    return (NULL);
  if ((pwd = cd_lesspwd(env)) == NULL)
    return (NULL);
  my_printf("\n%s\n%s\n", pwd, oldpwd);
  if ((chdir("..")) != 0)
    return (NULL);
  //  env = setenv(pwd, env);
  //  env = setenv(oldpwd, env);
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
	  my_printf("%s\n", pwd);
	  if ((chdir(pwd)) != 0)
	    return (NULL);
	  pwd = my_concat("PWD ", pwd);
	  //	  env = setenv(pwd, env);
	  //	  env = setenv(oldpwd, env);
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
	  pwd = my_concat("PWD ", my_concat(my_concat(oldpwd, "/"), directory));
	  oldpwd = my_concat("OLDPWD ", oldpwd);
	  my_printf("\n%s\n%s\n", oldpwd, pwd);
	  if ((chdir(directory)) != 0)
	    return (NULL);
	  //	  env = setenv(pwd, env);
	  //	  env = setenv(oldpwd, env);
	  return (env);
	}
      tmp = tmp->next;
    }
  return (env);
}

t_env	*cd_go_home(t_env *env)
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
	  pwd = my_concat("PWD ", home);
	  chdir(home);
	}
      if ((my_nncmp(tmp->value, "PWD=", 0)) == 0)
	oldpwd = my_concat("OLDPWD ", my_ncpy(tmp->value, 4));
      tmp = tmp->next;
    }
  // env = setenv(oldpwd, env);
  // env = setenv(pwd, env);
  my_printf("\n%s\n%s\n", pwd, oldpwd);
  return (env);
}

t_env	*shell_cd(t_env *env, char *directory)
{
  //  my_aff_env(env);
  if (directory == NULL)
    {
      env = cd_go_home(env);
      return (env);
    }
  if ((my_nncmp(directory, "..", 0)) == 0)
    env = cd_prev(env);
  else if ((my_nncmp(directory, "-L", 0)) == 0)
    env = cd_go_home(env);
  else if ((my_nncmp(directory, "-P", 0)) == 0)
    env = cd_go_home(env);
  else if ((my_nncmp(directory, "-", 0)) == 0)
    env = cd_minus(env);
  else
    env = cd_directory(env, directory);
  return (env);
}
