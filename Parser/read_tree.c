/*
** read_tree.c for read_tree in /home/besnie_b/42Sh/Parser
** 
** Made by besnie_b
** Login   <besnie_b@epitech.net>
** 
** Started on  Sat May 24 16:28:19 2014 besnie_b
** Last update Sun May 25 17:59:59 2014 besnie_b
*/

/*
** WARNING ! CODE DANGEREUX ! RECURSIF ABONDANT. IL EST DECONSEILLE DE TROP S'Y EXPOSER
*/

int	distrib_func(t_node *node, t_env *env)
{
  if (my_strcmp_strict(node->data, "|") == 0)
    mpipes_func(node, env);
  else if (my_strcmp_strict(node->data, ">") == 0)
    redir_right(node, env);
  else if (my_strcmp_strict(node->data, ">>") == 0)
    double_redir_right(node, env);
  else if (my_strcmp_strict(node->data, "<") == 0)
    redir_left(node, env);
  else if (my_strcmp_strict(node->data, "<<") == 0)
    double_redir_left(node, env);
  if (verif_prio(node->data) > 1)
    
  else
    return (-?);
  return (0);
}

int	buldo_rec(t_node *node)
{
  t_node *tmp;
  t_node *help;

  tmp = node;
  while (tmp->p_nx1 != NULL)
    tmp = tmp->p_nx1;
  tmp = tmp->p_prev;
  while (tmp != node)
    {
      help = tmp;
      help = help->p_nx1;
      help->p_prev = NULL;
      tmp->p_nx1 = NULL;
      free(*help);
      help = tmp;
      help = help->p_nx2;
      if (verif_prio(help) != 0)
	buldo_rec(help);
      help->p_prev = NULL;
      tmp->p_nx2 = NULL;
      free(*help);
    }
  return (0);
}

int	fallen_down_nx(t_node *node, t_env *env) // C'est la FIN
{
  distrib_func(node, env); // Après la chute, 
  buldo_rec(node); // S'en suit l'atterissage
  return (0);
}

int	destruct_tree(t_node *node, t_env *env)
{
  if (my_strcmp_strict(node->data, "&&") == 0)
    my_op_and_func(node, env); // Appelle à la fonction gérant le cas &&
  else if (my_strcmp_strict(node->data, "||") == 0)
    my_op_or_func(node, env); // Appelle à la fonction gérant le cas ||
  else if (my_strcmp_strict(node->data, ";") == 0)
    my_op_pv_func(node, env); // Appelle à la fonction gérant le cas ;
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
  destruct_tree(node, env); // Fonction qui execute et detruit les nodes
  read_tree_rec(node, env);
}
