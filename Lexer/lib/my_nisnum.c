/*
** nchar.c for lib in /home/auffra_a/rendu/corewar/lib
** 
** Made by auffra_a
** Login   <auffra_a@epitech.net>
** 
** Started on  Sat Mar 29 15:31:52 2014 auffra_a
** Last update Sun Mar 30 15:03:18 2014 auffra_a
*/

int	nisnum(char c)
{
  if (c >= 48 && c <= 57 || c == '-' || c == ':')
    return (0);
  return (-1);
}
