/*
** my.h for my in /home/theven_d/rendu/MUL_2013_fdf/header
** 
** Made by theven_d
** Login   <theven_d@epitech.net>
** 
** Started on  Fri Dec  6 22:47:59 2013 theven_d
** Last update Fri May 16 18:43:33 2014 theven_d
*/

#ifndef MY_H_
# define MY_H_

#include <stdarg.h>

void	my_putchar(char c);
void	my_free_tab(char **tab);
int	my_cmp_str(char *str, char *cmp);
int	my_put_nbr(int nb);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
int     my_printf(const char *format, ...);
int     my_put_nbr_signed(va_list);
int     my_put_char(va_list);
int     my_put_str(va_list);
int     my_put_str_octal(va_list );
int	my_putstr_octal(char *);
int     my_put_modulo(va_list);
int     my_put_nbr_binaire(va_list);
int     my_put_nbr_octal(va_list);
int     my_put_nbr_deci(va_list);
int     my_put_nbr_hexamin(va_list);
int     my_put_nbr_hexamaj(va_list);
int     my_put_nbr_bus(unsigned int, char *);
int	my_put_nbr_base(int, char *);
char    *my_strdupcpy(char *str);
char	*my_strdup(char *src);
char	**my_str_to_wordtab(char *tab);

#endif /*MY_H_*/
