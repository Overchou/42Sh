/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/besnie_b/rendu/Piscine-C-Jour_0X/Piscine-C-Jour_08
**
** Made by besnie_b
** Login   <besnie_b@epitech.net>
**
** Started on  Thu Oct 10 18:39:22 2013 besnie_b
** Last update Sun Apr 27 18:04:14 2014 theven_d
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int	my_numberofword(char *str)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (str[i] != 0 && str[i] == ' ')
    {
      i++;
      if (str[i + 1] == 0)
	  return (n);
    }
  while (str[i] != 0)
    {
      if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == 0))
	n++;
      i++;
    }
  return (n);
}

char	**my_size_tab(char *str, char **tab)
{
  int	i;
  int	k;
  int	n;

  i = 0;
  n = 0;
  k = 0;
  while (str[i] != 0 && str[i] == ' ')
    i++;
  while (str[i] != 0)
    {
      if (str[i] != ' ' && (str[i + 1] != ' ' || str[i + 1] != 0))
	n++;
      if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == 0))
	{
	  if ((tab[k] = malloc(sizeof(**tab) * (n + 1))) == NULL)
	    return (0);
	  tab[k][n] = 0;
	  k++;
	  n = 0;
	}
      i++;
    }
  return (tab);
}

char	**my_finished_tab(char *str, char **tab)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  while (str[i] != 0 && str[i] == ' ')
    i++;
  while (str[i] != 0)
    {
     if (str[i] != ' ' && str[i] != '\n')
	{
	  tab[j][k] = str[i];
	  k++;
	}
       if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == 0))
	{
	  k = 0;
	  j++;
	}
      i++;
    }
  return (tab);
}

char	**my_str_to_wordtab(char *str)
{
  char	**tab;
  int	n;

  n = my_numberofword(str);
  if ((tab = malloc(sizeof(*tab) * (n + 1))) == NULL)
    return (0);
  tab = my_size_tab(str, tab);
  tab = my_finished_tab(str, tab);
  tab[n] = NULL;
  return (tab);
}
