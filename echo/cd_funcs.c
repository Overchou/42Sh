/*
** cd_funcs.c for 42 in /home/auffra_a/rendu/42sh/sources
** 
** Made by auffra_a
** Login   <auffra_a@epitech.net>
** 
** Started on  Fri May 23 16:14:38 2014 auffra_a
** Last update Fri May 23 16:49:48 2014 auffra_a
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "cd.h"

char    *cd_pwding(t_env *env)
{
  t_env *tmp;
  char *oldpwd;

  tmp = env;
  while (tmp != NULL)
    {
      if ((my_nncmp(tmp->value, "PWD=", 0)) == 0)
        {
          if ((oldpwd = my_ncpy(tmp->value, 4)) == NULL)
	    return (NULL);
          if ((oldpwd = my_concat("OLDPWD ", oldpwd)) == NULL)
	    return (NULL);
          return (oldpwd);
        }
      tmp = tmp->next;
    }
  return (NULL);
}

char    *my_ncpy_lesspwd(char *s, int x1, int i)
{
  char *str;
  int slash;

  slash = 0;
  while (s[++i] != 0)
    if (s[i] == '/')
      slash++;
  if ((str = malloc(sizeof(*str) * (i - x1 + 1))) == NULL)
    return (NULL);
  x1--;
  i = -1;
  while (s[++x1] != 0)
    {
      if (s[x1] == '/')
        slash--;
      if (slash == 0)
        {
          str[++i] = 0;
          return (str);
        }
      str[++i] = s[x1];
    }
  str[++i] = 0;
  return (str);
}

char    *cd_lesspwd(t_env *env)
{
  char *pwd;
  t_env *tmp;

  tmp = env;
  while (tmp != NULL)
    {
      if ((my_nncmp(tmp->value, "PWD=", 0)) == 0)
        {
          if ((pwd = my_ncpy_lesspwd(tmp->value, 4, -1)) == NULL)
	    return (NULL);
          if ((pwd = my_concat("PWD ", pwd)) == NULL)
	    return (NULL);
          return (pwd);
        }
      tmp = tmp->next;
    }
  return (NULL);
}
