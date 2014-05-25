/*
** my_epur_str.c for 42sh in /home/theven_d/rendu/42Sh/Theven_dsh/lib
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Fri May 16 18:37:17 2014 theven_d
** Last update Sun May 25 15:38:54 2014 theven_d
*/

#include <stdlib.h>
#include "my.h"

int	check(char c)
{
  if (c == ' ')
    return (1);
  else if (c == '\t')
    return (1);
  else if (c == '\n')
    return (1);
  return (0);
}

char	*epur_loop(char *epur, char *tmp, int i, int *j)
{
  int	jj;

  jj = *j;
  while (epur[i] != '\0')
    {
      while (epur[i] != '\0' && check(epur[i]) == 0)
	tmp[jj++] = epur[i++];
      while (epur[i] != '\0' && check(epur[i]) == 1)
	i += 1;
      if (epur[i] != '\0')
	tmp[jj++] = ' ';
    }
  *j = jj;
  return (tmp);
}

char	*my_epur_str(char *epur, int len)
{
  char	*tmp;
  int	i;
  int	j;

  if (epur == NULL)
    return (NULL);
  if ((tmp = malloc(sizeof(*tmp) * (len + 1))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (epur[i] != '\0' && check(epur[i]) == 1)
    i++;
  if (epur[i] == '\0')
    return (NULL);
  tmp = epur_loop(epur, tmp, i, &j);
  if (j == 0)
    return (NULL);
  tmp[j] = '\0';
  return (tmp);
}
