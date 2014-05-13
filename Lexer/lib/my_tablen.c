/*
** tablen.c for lib in /home/auffra_a/rendu/corewar/lib
** 
** Made by auffra_a
** Login   <auffra_a@epitech.net>
** 
** Started on  Mon Mar 17 08:51:57 2014 auffra_a
** Last update Mon Mar 17 08:53:17 2014 auffra_a
*/

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "my.h"

int     tablen(char **adt)
{
  int i;

  i = -1;
  while (adt[++i] != NULL);
  return (i);
}
