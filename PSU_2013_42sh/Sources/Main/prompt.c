/*
** prompt.c for 42 in /home/auffra_a/rendu/42sh/sources
** 
** Made by auffra_a
** Login   <auffra_a@epitech.net>
** 
** Started on  Sat May 17 15:53:10 2014 auffra_a
** Last update Thu May 22 18:14:38 2014 theven_d
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "env.h"
#include "free_fct.h"
#include "my.h"

char	*find_pwd_prompt(char *pwd, t_env *env)
{
  int	i;
  int	j;
  
  j = 3;
  i = -1;
  while (env != NULL)
    {
      if ((my_nncmp(env->value, "PWD=", 0)) == 0)
	{
	  if ((pwd = malloc(sizeof(*pwd) * (strlen(env->value) - 3))) == NULL)
	    return (NULL);
	  while (env->value[++j] != '\0')
	    pwd[++i] = env->value[j];
	  pwd[++i] = '\0';
	  return (pwd);
	}
      env = env->next;
    }
  return (NULL);
}

void	our_magic_prompt(t_env *env)
{
  char	*pwd;
  t_env	*tmp;

  tmp = env;
  pwd = NULL;
  pwd = find_pwd_prompt(pwd, tmp);
  my_putstr("\033[031m[\033[036m\e[5;38mINSERT A COIN\e[m\033[00m\033[31m]");
  if (pwd == NULL)
    my_putstr(" [\033[036mIci!\033[031m]");
  else
    my_printf(" [\033[036m%s\033[031m]", pwd);
  my_putstr("\n   \033[31m(LAS \033[033mVEGASH\033[031m)\033[00m");
  my_free_env_ptr(tmp);
  free(pwd);
}
