/*
** my_strcmpenv.c for 42sh in /home/theven_d/rendu/PSU_2013_42sh/sources
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Fri May 16 14:34:16 2014 theven_d
** Last update Fri May 16 14:39:59 2014 theven_d
*/

#include <string.h>

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
