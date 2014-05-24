/*
** my_signal.c for my_signal in /home/theven_d/rendu/PSU_2013_minishell1/sources
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Tue Feb  4 15:48:26 2014 theven_d
** Last update Sun Apr 27 15:02:05 2014 theven_d
*/

#include <signal.h>
#include <stdlib.h>
#include "my.h"

void	my_nothing()
{
  my_putstr("");
}

void	my_signal()
{
  signal(SIGINT, my_nothing);
  signal(SIGTSTP, my_nothing);
  signal(SIGUSR1, my_nothing);
  signal(SIGUSR2, my_nothing);
  signal(SIGQUIT, my_nothing);
}
