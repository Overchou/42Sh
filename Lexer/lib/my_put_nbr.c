/*
** my_put_nbr.c for my_put_nbr in /home/guenol_v/rendu/Piscine-C-Jour_03
** 
** Made by guenol_v
** Login   <guenol_v@epitech.net>
** 
** Started on  Wed Oct  2 18:15:14 2013 guenol_v
** Last update Thu Nov  7 17:40:11 2013 guenol_v
*/

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb >= 10)
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
    }
  else
    my_putchar(nb + 48);
  return (0);
}
