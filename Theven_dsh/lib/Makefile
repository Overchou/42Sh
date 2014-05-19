##
## Makefile for makefile in /home/theven_d/rendu/Piscine-C-lib/my
## 
## Made by theven_d
## Login   <theven_d@epitech.net>
## 
## Started on  Mon Oct 21 22:12:01 2013 theven_d
## Last update Fri May 16 18:37:09 2014 theven_d
##

NAME	= libmy.a

INCLUDE	= my.h

SRCS	= my_putchar.c \
	  my_epur_str.c \
	  my_str_to_wordtab.c \
	  my_check_str.c \
	  my_nncmp.c \
	  my_strdupcpy.c \
	  my_free_tab.c \
	  my_put_nbr.c \
	  my_putstr.c \
	  my_strlen.c \
	  my_getnbr.c \
	  my_strdup.c \
	  my_printf.c \
	  my_put_nbr_bus.c \
	  my_put_nbr_base.c \
	  my_putstr_octal.c \
	  put_all_nbr.c \
	  put_char_nbr.c

OBJS	= $(SRCS:.c=.o)

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar rc  $(NAME) $(OBJS) $(INLCUDE)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
