/*
** my_strcmpenv.c for 42sh in /home/theven_d/rendu/PSU_2013_42sh/sources
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Fri May 16 14:34:16 2014 theven_d
** Last update Sat May 24 14:41:22 2014 theven_d
*/

#include <string.h>
#include <stdlib.h>
#include "my.h"

int	my_strcmpenv(char *valenv, char *str)
{
  int	len;
  int	lenstr;
  int	i;

  i = 0;
  len = -1;
  while (valenv[++len] != '=');
  lenstr = strlen(str);
  if (len != lenstr)
    return (-1);
  while (i != len)
    if (valenv[i] != str[i])
      return (-1);
    else
      i++;
  return (0);
}

char    *malloc_res(int check, char *name, char *value)
{
  int   lenname;
  int   lenval;
  int   i;
  char  *res;

  lenname = strlen(name);
  lenval = strlen(value);
  i = lenname + lenval + 1;
  if (check == 0)
    i += 1;
  if ((res = malloc(sizeof(*res) * i)) == NULL)
    return (NULL);
  return (res);
}

char    *concat_setenv(char *name, char *value)
{
  char  *res;
  int   check;
  int   i;

  check = 0;
  i = 0;
  if (value[0] == '=' || my_check_str('=', name) == 1)
    check = 1;
  if ((res = malloc_res(check, name, value)) == NULL)
    return (NULL);
  while (name[i] != '\0')
    {
      res[i] = name[i];
      i++;
    }
  if (check == 0)
    res[i++] = '=';
  check = 0;
  while (value[check] != '\0')
    res[i++] = value[check++];
  res[i] = '\0';
  return (res);
}
