/*
** echo.c for 42 in /home/auffra_a/rendu/42sh
** 
** Made by auffra_a
** Login   <auffra_a@epitech.net>
** 
** Started on  Mon Apr 21 10:49:59 2014 auffra_a
** Last update Fri May 16 14:48:49 2014 auffra_a
*/

#include <stdio.h>
#include <stdlib.h>

char	*my_nncpy(char *s, int x1, int x2)
{
  char *str;
  int i;

  x1--;
  i = -1;
  if ((str = malloc(sizeof(*str) * (x2 - x1 + 2))) == NULL)
    return (0);
  while (++x1 <= x2)
    str[++i] = s[x1];
  str[++i] = NULL;
  return (str);
}

int	echo_e(char *s, int i)
{
  while (s[++i] != 0)
    {
      if (s[i] == '\\')
	{
	  if (echo_if(s, i) == 0)
	    i++;
	  else if (echo_if2(s, i) == 0)
	    i++;
	  else if (echo_if_base(s, i) != -1)
	    i++;
	  else if (s[i + 1] == 'c')
	    return (1);
	  else if (s[i + 1] == 'b')
	    my_putchar('\b');
	  else
	    my_putchar(s[i]);
	}
      else
	my_putchar(s[i]);
    }
  return (0);
}

int	echo_print(char **echo, int i, int e)
{
  while (echo[++i] != NULL)
    {
      if (e == 1)
	{
	  if (echo_e(echo[i], -1) == 1)
	    return (1);
	}
      else
	my_printf("%s", echo[i]);
      if (echo[i + 1] != NULL)
	my_putchar(' ');
    }
  return (0);
}

void	builtin_echo(char *s)
{
  char **echo;
  int n;
  int e;
  int i;

  echo = my_str_to_wordtab(s);
  n = 0;
  e = 0;
  i = -1;
  while (echo[++i] != NULL)
    {
      if (my_nncmp(echo[i], "-n", 0) == 0)
	n = 1;
      if (my_nncmp(echo[i], "-e", 0) == 0)
	e = 1;
      if (my_nncmp(echo[i], "-E", 0) == 0)
	e = 0;
    }
  i = -1;
  while (my_nncmp(echo[++i], "-", 0) == 0);
  i--;
  echo_print(echo, i, e);
  if (n == 0)
    my_putchar('\n');
  free(echo);
}
