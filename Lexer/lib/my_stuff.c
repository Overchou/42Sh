/*
** stuff.c for corewar in /home/auffra_a/rendu/corewar/sources
** 
** Made by auffra_a
** Login   <auffra_a@epitech.net>
** 
** Started on  Sun Mar 30 14:23:33 2014 auffra_a
** Last update Sun Apr 13 18:19:20 2014 guenol_v
*/

int     ngetnbr_ok(char c)
{
  if (c == ' ' || c == '+' || c == '-' || c == '/' || c == '*' || c == ':')
    {
      return (0);
    }
  return (-1);
}
