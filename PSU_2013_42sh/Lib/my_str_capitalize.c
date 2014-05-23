/*
** my_str_capitalize.c for 42sh in /home/theven_d/rendu/42Sh/PSU_2013_42sh/Lib
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Fri May 23 15:24:51 2014 theven_d
** Last update Fri May 23 15:35:10 2014 theven_d
*/

#include <stdlib.h>
#include "my.h"

char    *my_str_capitalize(char *str)
{
  char  *res;
  int   i;

  i = 0;
  if ((res = my_strdupcpy(str)) == NULL)
    return (NULL);
  while (res[i] != '\0')
    {
      if (res[i] >= 97 && res[i] <= 122)
        res[i] = res[i] - 32;
      i = i + 1;
    }
  return (res);
}
