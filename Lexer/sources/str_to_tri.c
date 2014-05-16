/*
** str_to_tri.c for str_to_tri in /home/besnie_b/My_42sh
**
** Made by besnie_b
** Login   <besnie_b@epitech.net>
**
** Started on  Sat Apr 19 15:06:28 2014 besnie_b
** Last update Fri May 16 14:20:23 2014 besnie_b
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "lexer.h"

char	*my_epur_str(char *str)
{
  int	i;
  int	len;
  char	*ret;

  len = strlen(str);
  if ((ret = malloc(sizeof(*ret) * (len + 1))) == NULL)
    return (0);
  i = 0;
  len = 0;
  while (str[i] != 0)
    {
      if (str[i] != ' ' && str[i] != '\t')
	ret[len++] = str[i++];
      else if (str[i] == ' ' || str[i] == '\t')
	{
	  ret[len++] = str[i++];
	  while (str[i] == ' ' || str[i] == '\t')
	    i++;
	}
    }
  ret[len] = 0;
  return (ret);
}

int	det_lexeme(char	*str, int i)
{
  if (str[i] != ' ' && str[i] != '\t' && str[i] != 0)
    {
      if (str[i] == '|' || (str[i] == '&' && str[i + 1] == '&'))
	return (1);
      else if (str[i] == '>' || str[i] == '<')
	return (2);
      else if (str[i] == '(' || str[i] == ')')
	return (3);
      else if (str[i] == ';')
	return (4);
      else if (str[i] != '|' && str[i + 1] != '&')
	return (5);
    }
  return (0);
}

t_list	*my_str_to_list(char *str, t_list *list)
{
  int	i;
  int	add;

  i = 0;
  while (str[i] != 0 && (str[i] == ' ' || str[i] == '\t'))
    i++;
  while (str[i] != 0)
    {
      add = 0;
      if (det_lexeme(str, i) == 1)
	add = my_op_word_in_list(str, i, list);
      else if (det_lexeme(str, i) == 2)
	add = my_redir_char(str, i, list);
      else if (det_lexeme(str, i) == 3)
	add = my_exclu_char(str, i, list);
      else if (det_lexeme(str, i) == 4)
	add = my_stop_char(str, i, list);
      else if (det_lexeme(str, i) == 5)
	add = my_sec_word_in_list(str, i, list);
      else if (det_lexeme(str, i) == 0)
	i++;
      i += add;
    }
  return (list);
}
