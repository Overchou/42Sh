/*
** op_and_func.c for parser in /home/besnie_b/42Sh/Parser
** 
** Made by besnie_b
** Login   <besnie_b@epitech.net>
** 
** Started on  Sun May 18 14:13:38 2014 besnie_b
** Last update Sun May 18 14:53:50 2014 besnie_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
** Fonctions nécessaires pour fonctionner :
** my_check_access / concat_path / my_get_path / my_nncmp / my_strdupcpy
** my_str_to_wordtab / my_fork /
** **************************************
*/

int	my_op_and_func(char *cmd1, char *cmd2, t_env *p_env)
{
  char **path;

  path = my_get_path(p_env);
  if (my_check_access(cmd1, path) != NULL 
      && my_check_access(cmd2, path) != NULL)
    {
      my_fork(cmd1, p_env);
      my_fork(cmd2, p_env);
      return (1);
    }
  else
    return (0);
}

int	my_op_or_func(char *cmd1, char *cmd2, t_env *p_env)
{
  char	**path;

  if (my_check_access(cmd1, path) != NULL)
    {
      my_fork(cmd1, p_env);
      return (1);
    }
  else if (my_check_access(cmd2, path) != NULL)
    {
      my_fork(cmd2, p_env);
      return (2);
    }
  return (0);
}
