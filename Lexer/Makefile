##
## Makefile for makefile in /home/theven_d/rendu/Piscine-C-lib/my
##
## Made by theven_d
## Login   <theven_d@epitech.net>
##
## Started on  Mon Oct 21 22:12:01 2013 theven_d
## Last update Tue May 20 16:14:18 2014 guenol_v
##

NAME	=	42sh

SRC	=	sources/main.c \
		sources/liste_tri_c.c \
		sources/liste_tri_c2.c \
		sources/str_to_tri.c \
		sources/my_prio.c \
		sources/verif_syntax.c \
		sources/check_syntax.c \
		sources/lexeme_in_list.c \
		sources/my_tri_functions.c \
		sources/my_start_tree.c \

OBJ	=	$(SRC:.c=.o)

CC	=	cc

RM	=	rm -f

LIB	=	-lmy -L lib/

CFLAGS	+=	-Wall -Wextra -I ./include

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/
	$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
