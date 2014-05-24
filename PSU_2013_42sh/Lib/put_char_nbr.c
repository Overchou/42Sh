/*
** put_char_nbr.c for put_char_nbr in /home/theven_d/rendu/printf
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Sat Nov 16 16:36:33 2013 theven_d
** Last update Sat Feb 15 18:36:08 2014 theven_d
*/

#include <stdarg.h>
#include "my.h"

int	my_put_nbr_signed(va_list ap)
{
  int	i;

  i = my_put_nbr(va_arg(ap , int));
  return (i);
}

int	my_put_char(va_list ap)
{
  int	i;

  i = 1;
  my_putchar(va_arg(ap, int));
  return (i);
}

int	my_put_str(va_list ap)
{
  int	i;

  i = my_putstr(va_arg(ap, char *));
  return (i);
}

int	my_put_str_octal(va_list ap)
{
  int	i;

  i = my_putstr_octal(va_arg(ap, char *));
  return (i);
}
