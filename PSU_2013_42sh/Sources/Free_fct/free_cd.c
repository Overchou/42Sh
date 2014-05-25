/*
** free_cd.c for 42sh in /home/theven_d/rendu/42Sh/PSU_2013_42sh/Sources/Free_fct
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Sun May 25 17:58:00 2014 theven_d
** Last update Sun May 25 17:58:56 2014 theven_d
*/

#include <stdlib.h>

void	my_free_in_cd(char *tmp, char *ttmp)
{
  free(tmp);
  free(ttmp);
}
