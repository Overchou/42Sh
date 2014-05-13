/*
** adt.c for lib in /home/auffra_a/rendu/corewar/lib
** 
** Made by auffra_a
** Login   <auffra_a@epitech.net>
** 
** Started on  Mon Mar 17 08:52:21 2014 auffra_a
** Last update Wed Apr  9 18:41:11 2014 auffra_a
*/

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "my.h"

void    adt(char **adt)
{
  int i;

  i = -1;
  while (adt[++i] != NULL)
    my_printf("%s$\n", adt[i]);
}
