/*
** get_line.c for 42sh in /home/theven_d/rendu/42Sh/PSU_2013_42sh/Sources/Main
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Wed May 21 15:13:41 2014 theven_d
** Last update Thu May 22 20:48:00 2014 theven_d
*/

#include <stdlib.h>
#include <unistd.h>
#include "main.h"

char    *my_concat(char *result, char *recup , int i)
{
  char *tmp;
  int   j;
  int   k;

  j = 0;
  k = 0;
  if ((tmp = malloc(sizeof(*tmp) * (i + 1))) == NULL)
    return (NULL);
  if (result != NULL)
    {
      while (result[k] != '\0')
        {
          tmp[k] = result[k];
          k = k + 1;
        }
    }
  while (k < i)
    tmp[k++] = recup[j++];
  tmp[k] = '\0';
  free(result);
  return (tmp);
}

int     my_check_value(char value, char *str)
{
  int   i;

  i = 0;
  while (i < SIZE)
    {
      if (str[i] == value)
        return (i);
      i = i + 1;
    }
  return (0);
}

char    *my_get_line(char stop, int *a)
{
  int   i;
  int   b;
  char  *result;
  char  *recup;

  i = 0;
  if ((recup = malloc(sizeof(*recup) * (SIZE + 1))) == NULL)
    return (NULL);
  result = NULL;
  while ((b = read(0, recup, SIZE)) > 0)
    {
      *a += b;
      if (recup[0] == stop)
	{
	  free(recup);
	  return (result);
	}
      if ((b = my_check_value(stop, recup)) != 0)
        {
          i = i + b;
          result = my_concat(result , recup, i);
	  free(recup);
          return (result);
        }
      i = i + SIZE;
      result = my_concat(result , recup, i);
    }
  free(recup);
  return (result);
}
