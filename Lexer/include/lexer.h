/*
** lexer.h for lexer in /home/besnie_b/My_42sh
**
** Made by besnie_b
** Login   <besnie_b@epitech.net>
**
** Started on  Thu Apr 17 19:07:26 2014 besnie_b
** Last update Thu May 22 18:41:10 2014 guenol_v
** Last update Tue May 20 15:40:24 2014 besnie_b
*/

#ifndef LEXER_H__
# define LEXER_H__

typedef struct node
{
  char	*data;
  int	type;
  int	exec;
  struct node *p_prev;
  struct node *p_nx1;
  struct node *p_nx2;
} t_node;

typedef struct tlist
{
  unsigned int length;
  t_node *p_start;
  t_node *p_end;
} t_list;

/*
** liste_tri_c.c
*/
t_list   *tlist_new(void);
t_list   *tlist_append(t_list *p_list, char *data, int type);
t_list   *tlist_append2(t_list *p_list, t_node *p_new);
void    tlist_display(t_list *p_list);

/*
** liste_tri_c2.c
*/
t_list   *node_delete1(t_list *p_list, int pos);
void    node_delete2(t_list *p_list, t_node *p_tmp);
t_node  *tnode_dup(t_node *p_node);

/*
** str_to_tri.c
*/
int     my_strlen(char *str);
char    *my_epur_str(char *str);
t_list  *my_str_to_list(char *str, t_list *list);

/*
** lexeme_in_list.c
*/
int     my_stop_char(char *str, int i, t_list *list);
int     my_redir_char(char *str, int i, t_list *list);
int     my_exclu_char(char *str, int i, t_list *list);
int     my_sec_word_in_list(char *str, int i, t_list *list);
int     my_op_word_in_list(char *str, int i, t_list *list);

/*
** verif_syntax.c
*/
int     my_verif_syntax(t_list *list);

/*
** check_syntax.c
*/
int     check_op(char *str);
int     check_redir(char *str);
int     check_exclu(char *str);
int     check_stop(char *str);
int     my_strcmp_strict(char *str, char *comp);

/*
** my_prio.c
*/
t_node  *my_prio(t_node *);
int	verif_prio(t_node *);
int	my_db_verif(t_node *plist);
t_node	*my_other_prio(t_node *plist, t_node *next);

/*
** my_tri_functions.c
*/
t_node  *my_exec_prio(t_node *plist, t_node *tree);

/*
** my_start_tree.c
*/
t_node  *my_construct(t_node *tree, t_node *plist);

/*
** my_road_tree.c
*/
int	my_parse_tree(t_node *tree);

#endif /* LEXER_H__ */
