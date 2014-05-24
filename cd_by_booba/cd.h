/*
** cd.h for 42 in /home/auffra_a/rendu/42sh/include
** 
** Made by auffra_a
** Login   <auffra_a@epitech.net>
** 
** Started on  Fri May 23 16:48:28 2014 auffra_a
** Last update Sun May 25 00:23:07 2014 auffra_a
*/

char    *cd_pwding(t_env *env);
char    *my_ncpy_lesspwd(char *s, int x1, int i);
char    *cd_lesspwd(t_env *env);

t_env   *cd_prev(t_env *env);
t_env   *cd_minus(t_env *env);
t_env   *cd_directory(t_env *env, char *directory);
t_env   *shell_cd(t_env *env, char *directory);
t_env   *cd_go_home(t_env *env);

char    *my_ncpy(char *s, int x1);
char    *my_concat(char *s1, char *s2);
