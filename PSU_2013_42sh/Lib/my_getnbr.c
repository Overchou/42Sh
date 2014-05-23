/*
** my_getnbr.c for my_getnbr in /home/theven_d/rendu/Piscine-C-Jour_04
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Tue Oct  8 10:28:02 2013 theven_d
** Last update Tue Feb 11 19:01:15 2014 theven_d
*/

#include <stdlib.h>

int	my_get_nbr(char *str, int i)
{
  int	result;
  int	lennb;
  int	l;
  int	stock;

  l = 0;
  result = 0;
  lennb = 1;
  while (str[i] > 47 && str[i] < 58 && str[i] != '\0')
    {
      i = i + 1;
      lennb = lennb * 10;
    }
  lennb = lennb / 10;
  while (l < i)
    {
      stock = str[l] - 48;
      result = result + (stock * lennb);
      lennb = lennb / 10;
      l = l + 1;
    }
  return (result);
}

int     my_getnbr(char *str)
{
  int   result;
  int   sign;
  int   i;

  sign = 1;
  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] == '+' || str[i] == '-')
    {
      if (str[i] == '-')
        sign = sign * (-1);
      i = i + 1;
    }
  while (str[i] == '0')
    i = i + 1;
  if ((result = my_get_nbr(str, i)) == -1)
    return (0);
  return ((sign * result));
}
