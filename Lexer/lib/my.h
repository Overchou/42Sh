/*
** my.h for my in /home/guenol_v/rendu/Piscine-C-lib/my
**
** Made by guenol_v
** Login   <guenol_v@epitech.net>
**
** Started on  Mon Oct 21 11:35:48 2013 guenol_v
** Last update Sun Apr 13 21:22:37 2014 guenol_v
*/

#ifndef MY_
# define MY_

void	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	my_strlcat(char *dest, char *src, int size);
int	my_put_nbr_base(int, int);
int	my_put_nbr_unsi(unsigned int);
char	**my_str_to_wordtab(char *);
void    my_print_char(va_list ap);
void    my_print_str(va_list ap);
void    my_print_number(va_list ap);
int     my_printf(const char *format, ...);

#endif
