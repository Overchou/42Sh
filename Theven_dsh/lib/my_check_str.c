/*
** my_check_str.c for 42sh in /home/theven_d/rendu/PSU_2013_42sh/lib
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Wed May  7 17:00:17 2014 theven_d
** Last update Wed May  7 17:01:14 2014 theven_d
*/

int	my_check_str(char val, char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (val == str[i])
	return (1);
      i += 1;
    }
  return (0);
}
