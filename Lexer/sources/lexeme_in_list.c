/*
** lexeme_in_list.c for lexeme_in_list in /home/besnie_b/My_42sh
**
** Made by besnie_b
** Login   <besnie_b@epitech.net>
**
** Started on  Mon May  5 15:03:00 2014 besnie_b
** Last update Fri May 16 14:22:48 2014 besnie_b
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "lexer.h"

int     my_stop_char(char *str, int i, t_list *list)
{
  int   len;
  int   k;
  char  *tmp;

  len = 0;
  while (str[i] != 0 && str[i] == ';')
    {
      len++;
      i++;
    }
  i -= len;
  if ((tmp = malloc(sizeof(*tmp) * (len + 1))) == NULL)
    return (0);
  k = 0;
  while (str[i] != 0 && str[i] == ';')
    tmp[k++] = str[i++];
  tmp[len] = 0;
  tlist_append(list, tmp, 4);
  return (len);
}

int     my_redir_char(char *str, int i, t_list *list)
{
  int   len;
  int   k;
  char  *tmp;

  len = 0;
  while (str[i] != 0 && (str[i] == '<' || str[i] == '>'))
    {
      len++;
      i++;
    }
  i -= len;
  if ((tmp = malloc(sizeof(*tmp) * (len + 1))) == NULL)
    return (0);
  k = 0;
  while (str[i] != 0 && (str[i] == '<' || str[i] == '>'))
    tmp[k++] = str[i++];
  tmp[len] = 0;
  tlist_append(list, tmp, 2);
  return (len);
}

int     my_exclu_char(char *str, int i, t_list *list)
{
  int   len;
  int   k;
  char  *tmp;

  len = 0;
  while (str[i] != 0 && (str[i] == '(' || str[i] == ')'))
    {
      len++;
      i++;
    }
  i -= len;
  if ((tmp = malloc(sizeof(*tmp) * (len + 1))) == NULL)
    return (0);
  k = 0;
  while (str[i] != 0 && (str[i] == '(' || str[i] == ')'))
    tmp[k++] = str[i++];
  tmp[len] = 0;
  tlist_append(list, tmp, 3);
  return (len);
}

int     my_sec_word_in_list(char *str, int i, t_list *list)
{
  int   len;
  int   k;
  char  *tmp;

  len = 0;
  while (str[i] != 0
	 && (str[i] != '|' && str[i] != '(' && str[i] != ')'
	     && str[i] != '>' && str[i] != '<' && str[i] != ';'
	     && str[i + 1] != '&'))
    {
      len++;
      i++;
    }
  i -= len;
  if ((tmp = malloc(sizeof(*tmp) * (len + 1))) == NULL)
    return (0);
  k = 0;
  while (str[i] != 0
         && (str[i] != '|' && str[i] != '(' && str[i] != ')'
             && str[i] != '>' && str[i] != '<' && str[i] != ';'
             && str[i + 1] != '&'))
    tmp[k++] = str[i++];
  tmp[len] = 0;
  tlist_append(list, tmp, 0);
  return (len);
}

int     my_op_word_in_list(char *str, int i, t_list *list)
{
  int   len;
  int   k;
  char  *tmp;

  len = 0;
  while (str[i] != 0 && (str[i] == '|' || str[i] == '&'))
    {
      len++;
      i++;
    }
  i -= len;
  if ((tmp = malloc(sizeof(*tmp) * (len + 1))) == NULL)
    return (0);
  k = 0;
  while (str[i] != 0 && (str[i] == '|' || str[i] == '&'))
    tmp[k++] = str[i++];
  tmp[len] = 0;
  tlist_append(list, tmp, 1);
  return (len);
}
