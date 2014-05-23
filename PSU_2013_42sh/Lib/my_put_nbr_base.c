/*
** my_put_nbr_base.c for my_put_nbr_base in /home/theven_d/rendu/printf/sources
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Sun Nov 17 21:11:28 2013 theven_d
** Last update Sun Nov 17 22:12:18 2013 theven_d
*/

#include "my.h"

int    my_len_base(char *base)
{
  int  i;

  i = 0;
  while (base[i] != '\0')
    i = i + 1;
  return (i);
}

int     my_put_nbr_base(int nbr, char *base)
{
  int	len;
  int	a;
  long	p;
  int   i;

  len = my_len_base(base);
  i = 0;
  p = 1;
  a = 0;
  while (nbr >= p)
    p = p * len;
  p = p / len;
  while (p > 0)
    {
      a = nbr / p;
      a = a % len;
      my_putchar(base[a]);
      p = p / len;
      i = i + 1;
    }
  return (i);
}
