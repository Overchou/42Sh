/*
** echo.h for 42 in /home/auffra_a/rendu/42sh/include
** 
** Made by auffra_a
** Login   <auffra_a@epitech.net>
** 
** Started on  Sat May 24 15:48:01 2014 auffra_a
** Last update Sat May 24 16:06:47 2014 auffra_a
*/

#ifndef ECHO_H_
# define ECHO_H_

int     echo_x_nb(char x);
void    echo_x(char x1, char x2);
int     echo_o_nb(char x);
void    echo_o(char x1, char x2, char x3);
int     check_nb_octal(char *s, int i1, int i2);
int     check_nb_hexa(char *s, int i1, int i2);
int     echo_if(char *s, int i);
int     echo_if2(char *s, int i);
int     echo_if_base(char *s, int i);
int     echo_e(char *s, int i);
int     echo_print(char **echo, int i, int e);
void    echo_wheel(char **echo, int n, int e, char *s);
void    builtin_echo(char *s);

#endif /* ECHO_H_ */
