/*
** read_tree.c for read_tree in /home/besnie_b/42Sh/Parser
** 
** Made by besnie_b
** Login   <besnie_b@epitech.net>
** 
** Started on  Sat May 24 16:28:19 2014 besnie_b
** Last update Sun May 25 00:22:57 2014 besnie_b
*/

/*
** WARNING ! CODE DANGEREUX ! RECURSIF ABONDANT. IL EST DECONSEILLE DE TROP S'Y EXPOSER
*/

int	check_and_exec_nx_one(t_node *node, t_env *env)
{
  
}

int	destruct_tree(t_node *node, t_env *env)
{
  if (my_strcmp_strict(node->data, "&&") == 0)
  else if (my_strcmp_strict(node->data, "||") == 0)
  else if (my_strcmp_strict(node->data, ";") == 0)
    down_nx_one(node->p_nx1, env);
  down_nx_two(node->p_nx2, env);
  return (0);
}

int	read_tree_rec(t_node *node, t_env *env)
{
  while (node->prev != NULL)
    node = node->prev;
  while (verif_prio(node->p_nx1) != 0)
    node = node->p_nx1;
  while ((verif_prio(node->p_nx2) != 0) && (node->p_prev != NULL))
    node = node->p_prev;
  if (node->p_prev == NULL)
    return (0);
  destruct_tree(node, env);
  read_tree_rec(node, env);
}
