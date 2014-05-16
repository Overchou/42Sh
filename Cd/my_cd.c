/*
** my_cd.c for my_cd in /home/boutel_a/rendu/42sh
** 
** Made by boutel_a
** Login   <boutel_a@epitech.net>
** 
** Started on  Fri May 16 11:58:21 2014 boutel_a
** Last update Fri May 16 14:45:10 2014 boutel_a
*/

#include <unistd.h>

int	my_cd(char *buf, char **envi)
{
  int	l;
  char	*old;

  l = 0;
  if (my_strcmp_strict(buf, "-") == 0)
    my_check_old(envi);
  else if (my_strcmp_strict(buf, "..") == 0)
    my_check_double_point(envi);
  else
    my_check_cd(envi);
}

int	my_check_double_point(char **envi)
{
  int	l;
  int	p;
  int	o;

  l = 0;
  o = 0;
  chdir(buf);
  while (envi[l] != NULL)
    {
      if (my_nncmp(env[l], "PWD", 0) == 0)
	{
	  p = my_strlen(envi[l] - 1);
	  while (p >= 0)
	    {
	      if (env[p] == '/')
		{

		}
	      p--;
	    }
	}
      l++;
    }
}

int	my_check_cd(char **envi)
{
  int	l;

  l = 0;
  chdir(buf);
  while (envi[l] != NULL)
    {
      if (my_nncmp(envi[l], "PWD", 0) == 0)
	{
	  envi[l] = my_strcat(envi[l], buf);
	  envi[l] = my_strcat(envi[l], "/");
	}
      l++;
    }
}

int	my_check_old(char **envi)
{
  int	l;
  char	*old;

  l = 0;
  while (envi[l] != NULL)
    {
      if (my_nncmp(envi[l], "OLDPWD", 0) == 0)
	chdir(envi[l]);
      l++;
    }
}
