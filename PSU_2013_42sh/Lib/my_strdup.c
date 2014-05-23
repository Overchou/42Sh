/*
** my_strdup.c for my_strdup in /home/theven_d/rendu/Piscine-C-Jour_08/ex_01
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Wed Oct  9 11:09:13 2013 theven_d
** Last update Fri Feb 14 17:11:48 2014 theven_d
*/

#include <stdlib.h>
#include "my.h"

int	**my_str_to_int_tab(int x, int y)
{
  int	**tab;
  int	i;

  i = 0;
  if ((tab = malloc(sizeof(**tab) * y)) == NULL)
    return (NULL);
  while (i < y)
    {
      if ((*tab = malloc(sizeof(*tab) * x)) == NULL)
	return (NULL);
      i = i + 1;
      *tab = *tab + 1;
    }
  my_put_nbr(i);
  return (tab);
}

char	*my_strdup(char *src)
{
  int	i;
  char	*str;

  i = 0;
  if (src == NULL)
    return (NULL);
  while (src[i] != '\0')
    i = i + 1;
  if ((str = malloc(sizeof(*str) * i)) == NULL)
    return (NULL);
  i = 0;
  while (src[i] != '\0')
    {
      str[i] = src[i];
      i = i + 1;
    }
  str[i - 1] = '\0';
  return (str);
}
