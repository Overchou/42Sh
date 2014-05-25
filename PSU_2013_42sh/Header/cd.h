/*
** cd.h for 42 in /home/auffra_a/rendu/42sh/include
** 
** Made by auffra_a
** Login   <auffra_a@epitech.net>
** 
** Started on  Fri May 23 16:48:28 2014 auffra_a
<<<<<<< HEAD
** Last update Sun May 25 15:36:48 2014 theven_d
=======
** Last update Sun May 25 16:33:37 2014 auffra_a
>>>>>>> 1b8c8a2defdba44fcd2aa4e7263e42e528312509
*/

#include "env.h"

#ifndef CD_H_
# define CD_H_

char    *cd_pwding(t_env *env);
char    *my_ncpy_lesspwd(char *s, int x1, int i);
char    *cd_lesspwd(t_env *env);

t_env   *cd_prev(t_env *env);
t_env   *cd_minus(t_env *env);
t_env   *cd_directory(t_env *env, char *directory);
t_env   *shell_cd(t_env *env, char *directory);
t_env   *cd_go_home(t_env *env);

char    *my_ncpy(char *s, int x1);
char    *my_concat_cd(char *s1, char *s2);

char    *get_home(t_env *env);
t_env   *cd_home(t_env *env, char *directory);
t_env   *cd_by_home(t_env *env, char *directory);
t_env   *cd_p(t_env *env, char *directory);

#endif
