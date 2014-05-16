/*
** my_put_nbr_bus.c for my_put_nbr_bus in /home/theven_d/rendu/printf
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Thu Nov 14 10:22:47 2013 theven_d
** Last update Sun Nov 17 21:51:44 2013 theven_d
*/

#include "my.h"

unsigned int	my_lenbase(char *base)
{
  unsigned int	i;

  i = 0;
  while (base[i] != '\0')
    i = i + 1;
  return (i);
}

int	my_put_nbr_bus(unsigned int nbr, char *base)
{
  unsigned int  len;
  unsigned int	a;
  unsigned int	p;
  int	i;

  len = my_lenbase(base);
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
