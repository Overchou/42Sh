/*
** echo_check.c for 42 in /home/auffra_a/rendu/42sh/42Sh/echo
** 
** Made by auffra_a
** Login   <auffra_a@epitech.net>
** 
** Started on  Fri May 16 14:47:36 2014 auffra_a
** Last update Sat May 24 15:50:38 2014 auffra_a
*/

#include <stdio.h>
#include <stdlib.h>
#include "echo.h"

int     check_nb_octal(char *s, int i1, int i2)
{
  i1--;
  while (++i1 != i2)
    if (s[i1] <= 48 || s[i1] >= 56)
      return (-1);
  return (0);
}

int     check_nb_hexa(char *s, int i1, int i2)
{
  i1--;
  while ((s[++i1] >= 48 && s[i1] <= 57) || (s[i1] >= 65 && s[i1] <= 70) ||
         (s[i1] >= 97 && s[i1] <= 102));
  if (i1 != i2)
    return (-1);
  return (0);
}

int     echo_if(char *s, int i)
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

int     echo_if2(char *s, int i)
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

int     echo_if_base(char *s, int i)
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

