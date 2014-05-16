/*
** check_syntax.c for lexer in /home/besnie_b/My_42sh
** 
** Made by besnie_b
** Login   <besnie_b@epitech.net>
** 
** Started on  Thu May  8 15:48:14 2014 besnie_b
** Last update Fri May 16 14:19:02 2014 besnie_b
*/

#include <string.h>
#include "lexer.h"

int     my_strcmp_strict(char *str, char *comp)
{
  int   i;
  int   j;

  i = strlen(str);
  j = strlen(comp);
  if (i != j)
    return (-1);
  i = 0;
  while (str[i] != 0)
    {
      if (str[i] != comp[i])
        return (-1);
      i++;
    }
  return (0);
}

int	check_op(char *str)
{
  if (my_strcmp_strict(str, "&&") == 0)
    return (0);
  else if (my_strcmp_strict(str, "||") == 0)
    return (0);
  else if (my_strcmp_strict(str, "|") == 0)
    return (0);
  else if (my_strcmp_strict(str, "&") == 0)
    return (0);
  return (-1);
}

int	check_redir(char *str)
{
  if (my_strcmp_strict(str, "<") == 0)
    return (0);
  else if (my_strcmp_strict(str, "<<") == 0)
    return (0);
  else if (my_strcmp_strict(str, ">>") == 0)
    return (0);
  else if (my_strcmp_strict(str, ">") == 0)
    return (0);
  return (-1);
}

int	check_exclu(char *str)
{
  if (my_strcmp_strict(str, "(") == 0)
    return (0);
  else if (my_strcmp_strict(str, ")") == 0)
    return (0);
  return (-1);
}

int	check_stop(char	*str)
{
  if (my_strcmp_strict(str, ";") == 0)
    return (0);
  return (-1);
}
