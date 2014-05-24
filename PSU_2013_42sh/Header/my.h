/*
** my.h for 42sh in /home/theven_d/rendu/42Sh/PSU_2013_42sh/Header
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Wed May 21 19:00:22 2014 theven_d
** Last update Fri May 23 18:49:50 2014 theven_d
*/

#ifndef MY_H_
# define MY_H_

void	my_free_tab(char **);
void	my_putchar(char );
int	my_putstr(char *);
int     my_getnbr(char *);
int     my_nncmp(char *, char *, int);
int	my_printf(const char *, ...);
int     my_check_str(char, char *);
char	*my_epur_str(char *, int);
char	*my_str_capitalize(char *);
char	*my_strdupcpy(char *);
char	**my_str_to_wordtab(char *);

#endif
