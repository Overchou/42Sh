/*
** my_putstr.c for my_putstr in /home/guenol_v/rendu/Piscine-C-Jour_04
** 
** Made by guenol_v
** Login   <guenol_v@epitech.net>
** 
** Started on  Thu Oct  3 13:40:08 2013 guenol_v
** Last update Sun Nov 17 21:22:26 2013 guenol_v
*/

int	my_putstr(char *str)
{
  int	a;

  a = 0;
  while (str[a] != 0)
    {
      my_putchar(str[a]);
      a = a + 1;
    }
  return (a);
}
