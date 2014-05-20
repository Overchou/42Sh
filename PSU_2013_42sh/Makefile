##
## Makefile for 42sh in /home/theven_d/rendu/42Sh/PSU_2013_42sh
## 
## Made by theven_d
## Login   <theven_d@epitech.net>
## 
## Started on  Tue May 20 15:47:47 2014 theven_d
## Last update Tue May 20 15:57:28 2014 theven_d
##

ALIAS		= Alias/

BUILTINS	= Builtins/

ENV		= Env/

EXECUTION	= Execution/

LEXER		= Lexer/

MAIN		= Main/

PARCER		= Parcer/

REDI_PIPE	= Redi_Pipe/

NAME		=

CC		= gcc

SRCS		=

OBJS		= $(SRCS:.c=.o)

RM		= rm -f

CFLAGS		= -I ./Header -lmy -L ./Lib -Wall -Wextra

all: $(NAME)

$NAME: $(OBJS)	
	make re -C Lib/
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) 

debug: $(OBJS)
	make re -C Lib/	
	$(CC) -g -o $(NAME) $(OBJS) $(CFLAGS) 

clean:
	make clean -C Lib/
	$(RM) $(OBJS)

fclean: clean
	make fclean -C Lib/
	$(RM) $(NAME)

re: fclean all
