/*
** my_printf_funkz.c for my_printf_func in /home/auffra_a/rendu/printf
** 
** Made by auffra_a
** Login   <auffra_a@epitech.net>
** 
** Started on  Fri Nov 15 11:54:11 2013 auffra_a
** Last update Sun Apr 13 18:38:19 2014 guenol_v
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

void	my_print_char(va_list ap)
{
  my_putchar(va_arg(ap, int));
}

void	my_print_str(va_list ap)
{
  my_putstr(va_arg(ap, char *));
}

void	my_print_number(va_list ap)
{
  my_put_nbr(va_arg(ap, int));
}
