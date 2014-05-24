/*
** echo_calc.c for 42 in /home/auffra_a/rendu/42sh/42Sh/echo
** 
** Made by auffra_a
** Login   <auffra_a@epitech.net>
** 
** Started on  Fri May 16 14:46:56 2014 auffra_a
** Last update Sat May 24 18:54:52 2014 theven_d
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "echo.h"

int     echo_x_nb(char x)
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

void    echo_x(char x1, char x2)
{
  int n1;
  int n2;
  int r;

  n1 = echo_x_nb(x1);
  n2 = echo_x_nb(x2);
  r = (n1 * 16) + n2;
  my_putchar(r);
}

int     echo_o_nb(char x)
{
  if (x >= 48 && x <= 57)
    return (x - 48);
  return (0);
}

void    echo_o(char x1, char x2, char x3)
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
