##
## Makefile for Makefile in /home/guenol_v/rendu/Piscine-C-lib/my
##
## Made by guenol_v
## Login   <guenol_v@epitech.net>
##
## Started on  Mon Oct 21 10:53:22 2013 guenol_v
## Last update Tue Apr 22 18:57:05 2014 guenol_v
##

SRC	=	my_put_nbr.c \
		my_strlen.c \
		my_putstr.c \
		my_putchar.c \
		my_strcmp.c \
		my_str_to_wordtab.c \
		my_strcmp.c \
		my_nisnum.c \
		my_nncmp.c \
		my_strcmp.c \
		my_printf_funkz2.c \
                my_printf_funkz.c \
                my_printf.c \

RM	=	rm -f

NAME	=	libmy.a

OBJ	=	$(SRC:.c=.o)

CC	=	cc

CFLAGS	=	-Wall -Wextra

all:	$(NAME)

$(NAME):
	$(CC) -c $(SRC)
	ar rc $(NAME) $(OBJ)

make:
	@echo nothing to be done.

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all
