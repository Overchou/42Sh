/*
** cd_lib.c for 42 in /home/auffra_a/rendu/42sh/sources
** 
** Made by auffra_a
** Login   <auffra_a@epitech.net>
** 
** Started on  Fri May 23 16:34:48 2014 auffra_a
** Last update Sat May 24 18:44:28 2014 theven_d
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "cd.h"

char    *my_ncpy(char *s, int x1)
{
  char *str;
  int i;
  int x2;

  x2 = strlen(s);
  x1--;
  i = -1;
  if ((str = malloc(sizeof(*str) * (x2 - x1 + 2))) == NULL)
    return (NULL);
  while (++x1 != x2)
    str[++i] = s[x1];
  str[++i] = 0;
  return (str);
}

