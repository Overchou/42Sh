/*
** my_tri_functions.c for my_tri_functions in /home/guenol_v/rendu/42Sh/Lexer
** 
** Made by guenol_v
** Login   <guenol_v@epitech.net>
** 
** Started on  Tue May 13 14:46:02 2014 guenol_v
** Last update Fri May 16 15:55:54 2014 guenol_v
*/

#include <stdlib.h>
#include "lexer.h"
#include "my.h"

t_node	*my_prio_ptv(t_node *plist)
{
  my_putstr("C'est un point virgule\n");
  return (plist);
}

char    *my_init_value()
{
  char	*ptr;

  if ((ptr = malloc(sizeof(*ptr) * 5)) == NULL)
    return (NULL);
  ptr[0] = ';';
  ptr[1] = '|';
  ptr[2] = '>';
  ptr[3] = '<';
  ptr[4] = '\0';
  return (ptr);
}

t_node	*my_init_tab(t_node *plist)
{
  t_node *(*fptr[7])(t_node *);
  char	*buffer;
  char	*str;
  int	a;
  int	x;

  a = 0;
  fptr[0] = &my_prio_ptv;
  /* fptr[1] = &my_prio_pipe; */
  /* fptr[2] = &my_prio_red_right; */
  /* fptr[3] = &my_prio_red_left; */
  /* fptr[4] = &my_prio_db_right; */
  /* fptr[5] = &my_prio_db_left; */
  buffer = plist->data;
  str = my_init_value();
  while (buffer[a] != 0)
    {
      x = 0;
      while (str[x] != 0 && str[x] == buffer[a])
	{
	  my_putchar('a');
	  if (str[a] == buffer[a])
	    (*fptr[x])(plist);
	  my_putchar('b');
	  x++;
	}
      a++;
    }
}
