/*
** my_getnbr.c for getnbr in /home/auffra_a/rendu/alum1/lib
** 
** Made by auffra_a
** Login   <auffra_a@epitech.net>
** 
** Started on  Wed Feb 12 10:03:51 2014 auffra_a
** Last update Sun Apr 13 21:51:50 2014 guenol_v
*/

#include <stdarg.h>
#include "my.h"

int	my_ngetnbr(char *str, int i)
{
  int	n;
  int	p;
  int	s;
  int	minus;

  minus = 0;
  s = i;
  p = 1;
  n = 0;
  if (str[i] == '-')
    minus = 1;
  while ((str[i] >= 48 && str[i++] <= 57))
    p = p * 10;
  p = p / 10;
  i = s;
  while (str[i] >= 48 && str[i] <= 57)
    {
      n = n + (str[i++] - 48) * p;
      p = p / 10;
    }
  if (minus == 1)
    n = n * -1;
  return (n);
}
