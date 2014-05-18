/*
** my_putstr_octal.c for my_putstr_octal in /home/theven_d/rendu/printf/sources
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Sun Nov 17 21:04:32 2013 theven_d
** Last update Sun Nov 17 23:21:28 2013 theven_d
*/

#include "my.h"

int	my_putstr_octal(char *str)
{
  int	i;

  i = 0;
  while (*str != 0)
    {
      if (*str < 32 || *str >= 127)
	{
	  my_putchar('\\');
	  if (*str < 8)
	    my_putstr("00");
	  else
	    my_putchar(48);
	  my_put_nbr_base(*str, "01234567");
	}
      else
	my_putchar(*str);
      str = str + 1;
      i = i + 1;
    }
  return (i);
}
