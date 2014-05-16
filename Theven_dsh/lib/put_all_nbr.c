/*
** put_all_nbr.c for put_all_nbr in /home/theven_d/rendu/printf
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Fri Nov 15 11:24:20 2013 theven_d
** Last update Mon Nov 18 15:32:53 2013 theven_d
*/

#include <stdarg.h>
#include "my.h"

int	my_put_nbr_binaire(va_list ap)
{
  int	i;

  i = my_put_nbr_bus(va_arg(ap, unsigned int), "01");
  return (i);
}

int	my_put_nbr_octal(va_list ap)
{
  int	i;

  i = my_put_nbr_bus(va_arg(ap, unsigned int), "01234567");
  return (i);
}

int	my_put_nbr_deci(va_list ap)
{
  int	i;

  i = my_put_nbr_bus(va_arg(ap, unsigned int), "0123456789");
  return (i);
}

int	my_put_nbr_hexamin(va_list ap)
{
  int	i;

  i = my_put_nbr_bus(va_arg(ap, unsigned int), "0123456789abcdef");
  return (i);
}

int	my_put_nbr_hexamaj(va_list ap)
{
  int	i;

  i = my_put_nbr_bus(va_arg(ap, unsigned int), "0123456789ABCDEF");
  return (i);
}
