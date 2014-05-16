/*
** my_strlen.c for my_strlen in /home/theven_d/rendu/Piscine-C-Jour_04
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Thu Oct  3 14:27:09 2013 theven_d
** Last update Wed Jan 29 17:26:37 2014 theven_d
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str[0] != '\0')
    {
      while (*str != '\0')
	{
	  str = str + 1;
	  i = i + 1;
	}
      return (i);
    }
  else
    return (1);
  return (0);
}
