##
## Makefile for makefile in /home/theven_d/rendu/Piscine-C-lib/my
## 
## Made by theven_d
## Login   <theven_d@epitech.net>
## 
## Started on  Mon Oct 21 22:12:01 2013 theven_d
## Last update Fri May 16 17:57:10 2014 theven_d
##

NAME	= mysh

SRCS	= sources/main.c \
	  sources/my_strcmpenv.c \
	  sources/my_signal.c \
	  sources/check_builtin.c \
	  sources/my_fork.c \
	  sources/env.c \
	  sources/setenv.c \
	  sources/unsetenv.c

CC	= gcc -g

OBJS	= $(SRCS:.c=.o)

RM	= rm -f

CFLAGS	+= -Wall -Wextra
CFLAGS	+= -I ./header
CFLAGS	+= -L ./lib -lmy

all: $(NAME)

$(NAME): $(OBJS)
#	make re -C lib/
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
#	make clean -C lib/
	$(RM) $(OBJS)

fclean: clean
#	make fclean -C lib/
	$(RM) $(NAME)

re: fclean all
