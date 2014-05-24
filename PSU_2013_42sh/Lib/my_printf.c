/*
** my_printf.c for my_printf in /home/theven_d/rendu/Piscine-C/Piscine-C-lib/my
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Tue Nov 12 14:04:06 2013 theven_d
** Last update Fri May 23 15:35:58 2014 theven_d
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

char	*my_tab(char *tab)
{
  tab = malloc(sizeof(*tab) * 11);
  if (tab == NULL)
    return (NULL);
  tab[0] = 'b';
  tab[1] = 'i';
  tab[2] = 'd';
  tab[3] = 'o';
  tab[4] = 'u';
  tab[5] = 'x';
  tab[6] = 'X';
  tab[7] = 'c';
  tab[8] = 's';
  tab[9] = 'S';
  return (tab);
}

int	put_error(const char *format, int i, char *tab)
{
  int	j;

  j = 0;
  if (format[i] == '%' && format[i + 1] == '%')
    {
      my_putchar('%');
      return (++i);
    }
  while (j != 9 && tab[j] != format[i + 1])
    j = j + 1;
  if (j == 9)
    {
      my_putchar(format[i]);
      my_putchar(format[i + 1]);
    }
  return (i);
}

static int	my_loop(const char *format, int (**fptr)(va_list),
			va_list ap, char *tab)
{
  int	i;
  int	j;
  int	retour;

  i = 0;
  while (format[i] != '\0')
    {
      if (format[i] == '%')
	{
	  j = 0;
	  while (j != 10)
	    {
	      if (tab[j] == format[i + 1])
		retour = fptr[j](ap);
	      j = j + 1;
	    }
	  if (j == 10)
	    i = put_error(format, i, tab);
	  i = i +  1;
	}
      else
	my_putchar(format[i]);
      i = i + 1;
    }
  return (retour);
}

int	my_control(const char *format, int (**fptr)(va_list), va_list ap)
{
  char	*tab;
  int	i;
  int	j;

  j = -1;
  i = 0;
  tab = NULL;
  tab = my_tab(tab);
  i = my_loop(format, fptr, ap, tab);
  while (++j != 1)
    free(&tab[j]);
  return (i);
}

int	my_printf(const char *format, ...)
{
  int	(**fptr)(va_list);
  int	i;
  va_list	ap;
  int	j;

  j = -1;
  va_start(ap, format);
  fptr = malloc(sizeof(*fptr) * 10);
  if (fptr == NULL)
    return (0);
  fptr[0] = &my_put_nbr_binaire;
  fptr[1] = &my_put_nbr_signed;
  fptr[2] = &my_put_nbr_signed;
  fptr[3] = &my_put_nbr_octal;
  fptr[4] = &my_put_nbr_deci;
  fptr[5] = &my_put_nbr_hexamin;
  fptr[6] = &my_put_nbr_hexamaj;
  fptr[7] = &my_put_char;
  fptr[8] = &my_put_str;
  fptr[9] = &my_put_str_octal;
  i = my_control(format, fptr, ap);
  va_end(ap);
  while (++j != 1)
    free(&fptr[j]);
  return (i);
}
