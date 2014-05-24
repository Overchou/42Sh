/*
** my_free_tab.c for my_free_tab in /home/theven_d/rendu/PSU_2013_minishell1/sources
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Sat Feb  1 23:29:16 2014 theven_d
** Last update Wed May 21 21:47:56 2014 theven_d
*/

#include <stdlib.h>

void	my_free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i = i + 1;
    }
  free(tab);
}
