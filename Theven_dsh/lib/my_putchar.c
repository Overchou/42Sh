/*
** my_putchar.c for my_putchar in /home/theven_d/rendu/Piscine-C-lib/my
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Tue Oct  8 10:20:05 2013 theven_d
** Last update Sun Dec  8 13:07:42 2013 theven_d
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write (1, &c, 1);
}
