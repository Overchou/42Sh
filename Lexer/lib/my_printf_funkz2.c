/*
** my_printf_funkz2.c for my_print_funkz2 in /home/auffra_a/rendu/printf
** 
** Made by auffra_a
** Login   <auffra_a@epitech.net>
** 
** Started on  Sun Nov 17 18:25:28 2013 auffra_a
** Last update Mon Nov 18 16:38:04 2013 auffra_a
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

void	my_hexa(va_list ap)
{
  my_put_nbr_base_int(va_arg(ap, int), 16);
}

void	my_hexa_min(va_list ap)
{
  my_put_nbr_base_min(va_arg(ap, int), 16);
}

void	my_modulo_n(va_list ap)
{
  my_strlen(va_arg(ap, char *));
}

void	my_print_unsigned_int(va_list ap)
{
  my_put_nbr_un(va_arg(ap, unsigned int));
}

void	my_double_modulo(va_list ap)
{
  my_strlen(va_arg(ap, char *));
}
