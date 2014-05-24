/*
** cd_lib.c for 42 in /home/auffra_a/rendu/42sh/sources
** 
** Made by auffra_a
** Login   <auffra_a@epitech.net>
** 
** Started on  Fri May 23 16:34:48 2014 auffra_a
** Last update Fri May 23 16:49:23 2014 auffra_a
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

char    *my_concat(char *s1, char *s2)
{
  char *s3;
  int i;
  int n;

  i = -1;
  n = -1;
  if ((s3 = malloc(sizeof(*s3) * (strlen(s1) + strlen(s2)) + 1)) == NULL)
    return (NULL);
  while (s1[++i] != 0)
    s3[++n] = s1[i];
  i = -1;
  while (s2[++i] != 0)
    s3[++n] = s2[i];
  s3[++n] = 0;
  return (s3);
}

