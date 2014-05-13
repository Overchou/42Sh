/*
** my_strcmp.c for strcmp in /home/guenol_v/rendu/Piscine-C-Jour_06/ex_05
** 
** Made by guenol_v
** Login   <guenol_v@epitech.net>
** 
** Started on  Thu Oct 17 15:26:04 2013 guenol_v
** Last update Tue Mar  4 14:48:54 2014 guenol_v
*/

int	my_strcmp(char *s1, char *s2)
{
  int	a;
  int	b;

  a = 0;
  if (s1[a] != s2[a])
    {
      b = s1[a] - s2[a];
      return (b);
    }
  while (s1[a] == s2[a])
    {
      a = a + 1;
      if (s1[a] != s2[a])
	{
	  b = s1[a] - s2[a];
	  return (b);
	}
      if (s1[a] == 0 && s2[a] == 0)
	return (0);
    }
  return (0);
}
