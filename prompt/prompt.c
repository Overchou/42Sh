/*
** prompt.c for 42 in /home/auffra_a/rendu/42sh/sources
** 
** Made by auffra_a
** Login   <auffra_a@epitech.net>
** 
** Started on  Sat May 17 15:53:10 2014 auffra_a
** Last update Mon May 19 21:26:58 2014 auffra_a
*/

#include <time.h>
#include <sys/stat.h>
//#include "42.h"
#include "my.h"
#include <unistd.h>
#include <stdlib.h>

char	*find_pwd_prompt(char *pwd, char **env)
{
  int i;
  int n;
  int x;

  x = -1;
  i = -1;
  n = 3;
  while (env[++i] != NULL)
    if ((my_nncmp(env[i], "PWD=", 0)) == 0)
      {
	if ((pwd = malloc(sizeof(*pwd) * (my_strlen(env[i]) - 4))) == NULL)
	  return (NULL);
	while (env[i][++n] != 0)
	  pwd[++x] = env[i][n];
      }
  return (pwd);
}

void	our_magic_prompt(char **env)
{
  char *pwd;

  pwd = find_pwd_prompt(pwd, env);
  my_putstr("\n\n\n");
  my_printf("\033[031m[\033[036m\e[5;38mINSERT A COIN\e[m\033[00m\033[31m]");
  my_printf(" [\033[036m%s\033[031m]", pwd);
  my_printf("\n   \033[31m(LAS \033[033mVEGASH\033[031m)\033[00m");
  my_printf("\n\n\n");
}

int	main(int argc, char **argv, char **env)
{
  our_magic_prompt(env);
}
