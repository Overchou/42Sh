/*
** my_strncmp.c for my_strncmp in /home/auffra_a/izi
** 
** Made by auffra_a
** Login   <auffra_a@epitech.net>
** 
** Started on  Thu Oct 17 15:24:40 2013 auffra_a
** Last update Wed Apr 23 18:47:39 2014 theven_d
*/

#include "my.h"

int     my_nncmp(char *s1, char *s2, int i)
{
  int k;

  k = -1;
  while (s2[++k] != 0)
    {
      if (s1[i] != s2[k])
	return (-1);
      i++;
    }
  return (0);
}
