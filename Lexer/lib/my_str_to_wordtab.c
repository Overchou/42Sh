/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/guenol_v/rendu/ratrapage
**
** Made by guenol_v
** Login   <guenol_v@epitech.net>
**
** Started on  Thu Jan 23 15:14:11 2014 guenol_v
** Last update Sun Mar  9 22:48:14 2014 guenol_v
*/

#include <stdlib.h>
#include <unistd.h>

int	my_count_char(int p, char *str)
{
  int	a;

  a = 0;
  while (str[p] != '\0' && str[p++] != ' ' && str[p] != '\t')
    a++;
  return (a);
}

int	my_count_word(char *av)
{
  int	a;
  int	b;

  a = 0;
  b = 0;
  while (av[a] == ' ' && av[a] != '\t')
    a++;
  if (av[a] == 0)
    return (0);
  while (av[a] != 0)
    {
      if (av[a] == ' ' && av[a] != '\t')
	b = b + 1;
      while (av[a] == ' ' && av[a] != '\t')
	a++;
      a++;
    }
  b = b + 1;
  return (b);
}

char	**my_table(int a, char *av, char **res, int e)
{
  int	d;
  int	c;
  int	g;
  int	f;

  d = 0;
  f = 0;
  while (d != a)
    {
      c = my_count_char(e, av);
      if ((res[d] = malloc((c + 1) * sizeof(**res))) == NULL)
	return (0);
      e = e + c + 1;
      g = 0;
      while (f != e)
	{
	  res[d][g++] = av[f];
	  if (av[f + 1] == ' ' || av[f + 1] == '\n' || av[f + 1] == '\t')
	    f++;
	  f++;
	}
      res[d++][g] = '\0';
    }
  return (res);
}

char	**my_str_to_wordtab(char *av)
{
  int	a;
  char	**res;

  a = my_count_word(av);
  if (a == 0)
    return (0);
  if ((res = malloc((a + 1) * sizeof(*res))) == NULL)
    return (0);
  res[a] = NULL;
  res = my_table(a, av, res, 0);
  return (res);
}
