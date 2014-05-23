/*
** my_put_nbr.c for my_put_nbr in /home/theven_d/rendu/Piscine-C-Jour_03
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Wed Oct  2 18:25:08 2013 theven_d
** Last update Wed Jan 29 17:26:04 2014 theven_d
*/

#include "my.h"

int	my_number(int nb)
{
  long	p;
  int	l;

  p = 1;
  while (nb >= p)
    p = p * 10;
  p = p / 10;
  l = p;
  return (l);
}

int	my_put_nbr(int nb)
{
  int	a;
  int	b;
  int	q;

  if (nb == -2147483648)
    my_putstr("-2147483648");
  else if (nb == 0)
    my_putchar(48);
  else if (nb < 0 )
    {
      nb = nb * (-1);
      my_putchar('-');
    }
  q = my_number(nb);
  while (q >= 1)
    {
      a = nb / q;
      b = a % 10;
      my_putchar(b + 48);
      q = q / 10;
    }
  return (0);
}
