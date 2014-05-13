/*
** printf.c for printf in /home/auffra_a/rendu/printf/sources
** 
** Made by auffra_a
** Login   <auffra_a@epitech.net>
** 
** Started on  Tue Nov  5 13:21:15 2013 auffra_a
** Last update Sun Apr 13 18:38:09 2014 guenol_v
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

char	*tab_comparative(char *tabc)
{
  tabc[0] = 's';
  tabc[1] = 'd';
  tabc[2] = 'c';
  tabc[3] = 'i';
  tabc[4] = 'u';
  return (tabc);
}

void	my_tab_funk(va_list ap, int k)
{
  void (*tabf[11])(va_list);

  tabf[0] = &my_print_str;
  tabf[1] = &my_print_number;
  tabf[2] = &my_print_char;
  tabf[3] = &my_print_number;
  tabf[k](ap);
}

void	looping(char *tabc, const char *format, va_list ap)
{
  int k;
  int i;

  i = 0;
  k = 0;
  while (format[i] != '\0')
    {
      if (format[i] == '%')
	{
	  while (format[i + 1] != tabc[k] && tabc[k] != 0)
	    k = k + 1;
	  if (format[i + 1] == tabc[k])
	    my_tab_funk(ap, k);
	  else
	    {
	      my_putchar('%');
	      my_putchar(format[i + 1]);
	    }
	  k = 0;
	  i = i + 1;
	}
      else
	my_putchar(format[i]);
      i = i + 1;
    }
}

int	my_printf(const char *format, ...)
{
  va_list ap;
  char *tabc;

  va_start(ap, format);
  tabc = malloc(sizeof(*tabc) * 11);
  if (tabc == NULL)
    return (0);
  tabc = tab_comparative(tabc);
  looping(tabc, format, ap);
  va_end(ap);
  return (11);
}
