/*
** echo.c for 42 in /home/auffra_a/rendu/42sh
** 
** Made by auffra_a
** Login   <auffra_a@epitech.net>
** 
** Started on  Mon Apr 21 10:49:59 2014 auffra_a
** Last update Wed May  7 14:39:48 2014 auffra_a
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

int	echo_x_nb(char x)
{
  if (x >= 48 && x <= 57)
    return (x - 48);
  else if (x == 'A' || x == 'a')
    return (10);
  else if (x == 'B' || x == 'b')
    return (11);
  else if (x == 'C' || x == 'c')
    return (12);
  else if (x == 'D' || x == 'd')
    return (13);
  else if (x == 'E' || x == 'e')
    return (14);
  else if (x == 'F' || x == 'f')
    return (15);
  return (0);
}

void	echo_x(char x1, char x2)
{
  int n1;
  int n2;
  int r;

  n1 = echo_x_nb(x1);
  n2 = echo_x_nb(x2);
  r = (n1 * 16) + n2;
  my_putchar(r);
}

int	echo_o_nb(char x)
{
  if (x >= 48 && x <= 57)
    return (x - 48);
  return (0);
}

void	echo_o(char x1, char x2, char x3)
{
  int n1;
  int n2;
  int n3;
  int r;

  n1 = echo_o_nb(x1);
  n2 = echo_o_nb(x2);
  n3 = echo_o_nb(x3);
  if (n3 > 7)
    {
      n3 = n3 - 8;
      n2++;
    }
  if (n2 > 7)
    {
      n2 = n2 - 8;
      n1++;
    }
  r = n1 * 8 * 8 + n2 * 8 + n3;
  my_putchar(r);
}

int	check_nb_octal(char *s, int i1, int i2)
{
  i1--;
  while (++i1 != i2)
    if (s[i1] <= 48 || s[i1] >= 56)
      return (-1);
  return (0);
}

int	check_nb_hexa(char *s, int i1, int i2)
{
  i1--;
  while ((s[++i1] >= 48 && s[i1] <= 57) || (s[i1] >= 65 && s[i1] <= 70) ||
	 (s[i1] >= 97 && s[i1] <= 102));
  if (i1 != i2)
    return (-1);
  return (0);
}

int	echo_if(char *s, int i)
{
  if (s[i + 1] == 'n')
    {
      my_putchar('\n');
      return (0);
    }
  else if (s[i + 1] == 'a')
    {
      my_putchar('\a');
      return (0);
    }
  else if (s[i + 1] == '\\')
    {
      my_putchar('\\');
      return (0);
    }
  else if (s[i + 1] == 'e')
    {
      my_putchar('\e');
      return (0);
    }
  return (-1);
}

int	echo_if2(char *s, int i)
{
  if (s[i + 1] == 't')
    {
      my_putchar('\t');
      return (0);
    }
  else if (s[i + 1] == 'f')
    {
      my_putchar('\f');
      return (0);
    }
  else if (s[i + 1] == 'r')
    {
      my_putchar('\r');
      return (0);
    }
  else if (s[i + 1] == 'v')
    {
      my_putchar('\v');
      return (0);
    }
  return (-1);
}

int	echo_if_base(char *s, int i)
{
  if (s[i + 1] == 'x' && (check_nb_hexa(s, i + 2, i + 3)))
    {
      echo_x(s[i + 2], s[i + 3]);
      i += 2;
      return (i);
    }
  else if (s[i + 1] == '0')
    {
      if (check_nb_octal(s, i + 2, i + 4) == 0)
	{
	  echo_o(s[i + 2], s[i + 3], s[i + 4]);
	  i += 3;
	}
      else
	{
	  while (s[++i] <= 48 || s[i] >= 56);
	  i--;
	}
      return (i);
    }
  return (-1);
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

int	main(int argc, char **argv, char **env)
{
  if (argc == 2)
    builtin_echo(argv[1]);
  else
    my_putchar('\n');
  return (0);
}
