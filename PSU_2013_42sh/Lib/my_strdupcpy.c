/*
** my_strdupcpy.c for 42sh in /home/theven_d/rendu/PSU_2013_42sh/lib
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Wed Apr 23 19:05:37 2014 theven_d
** Last update Sat May 24 16:38:17 2014 theven_d
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"

char	*my_strdupcpy(char *str)
{
  char	*res;
  int	len;

  len = strlen(str);
  if ((res = malloc(sizeof(*res) * (len + 1))) == NULL)
    return (NULL);
  len = 0;
  while (str[len] != '\0')
    {
      res[len] = str[len];
      len += 1;
    }
  res[len] = '\0';
  return (res);
}

char	*my_strcpy(char *in, char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    in[i] = str[i];
  in[++i] = '\0';
  return (in);
}
