/*
** my_putstr.c for my_putstr in /home/theven_d/rendu/Piscine-C-Jour_04
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Thu Oct  3 11:04:50 2013 theven_d
** Last update Thu Apr 24 15:04:37 2014 theven_d
*/

#include "my.h"

int	my_putstr(char *str)
{
  while (*str != 0)
    {
      my_putchar(*str);
      str = str + 1;
    }
  return (-1);
}
