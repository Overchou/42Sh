/*
** my.h for my in /home/theven_d/rendu/MUL_2013_fdf/header
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Fri Dec  6 22:47:59 2013 theven_d
** Last update Fri May 16 14:36:47 2014 theven_d
*/


#ifndef MY_H_
# define MY_H_

#define SIZE 5

typedef struct s_env
{
  int   pos;
  char  *value;
  struct s_env *next;
}t_env;

typedef struct s_chain
{
  t_env	*begin;
  t_env	*end;
}t_chain;

t_env   *my_env_in_list(char **av);
void	my_signal();
void	my_putchar(char c);
void	my_free_tab(char **tab);
void    my_aff_env(t_env *env);
int	my_strcmpenv(char *valenv, char*str);
int	my_check_str(char val, char *str);
int     check_cmd(char *buffer, t_env *env);
int     my_setenv(char *str, t_env *env);
int	my_unsetenv(t_env *env, char *cmd);
int	my_fork(char *, t_env *env);
int     my_nncmp(char *s1, char *s2, int i);
int	my_cmp_str(char *str, char *cmp);
int     my_check_value(char value, char *str);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_printf(char *, ...);
int	my_getnbr(char *str);
char    *my_str_capitalize(char *str);
char	*my_strcpy(char	*in, char *str);
char	*my_strdupcpy(char *str);
char	**my_str_to_wordtab(char *tab);

#endif /*MY_H_*/
