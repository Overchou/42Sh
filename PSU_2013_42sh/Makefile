##
## Makefile for 42sh in /home/theven_d/rendu/42Sh/PSU_2013_42sh
## 
## Made by theven_d
## Login   <theven_d@epitech.net>
## 
## Started on  Tue May 20 15:47:47 2014 theven_d
## Last update Sat May 24 17:40:06 2014 theven_d
##

SOURCES		= Sources/

ALIAS		= Alias/

BUILTINS	= Builtins/

ENV		= Env/

SETENV		= Setenv/

UNSETENV	= Unsetenv/

CD		= Cd/

EXIT		= Exit/

ECHO		= Echo/

EXECUTION	= Execution/

FREE_FCT	= Free_fct/

LEXER		= Lexer/

MAIN		= Main/

PARSER		= Parser/

REDI_PIPE	= Redi_Pipe/

NAME		= vegash

CC		= gcc -g

SRCS		= ./Lib/my_epur_str.c \
		  $(SOURCES)$(BUILTINS)$(ENV)$(ENV)env.c \
		  $(SOURCES)$(BUILTINS)$(ENV)$(ENV)aff_env.c \
		  $(SOURCES)$(BUILTINS)$(ENV)$(SETENV)setenv.c \
		  $(SOURCES)$(BUILTINS)$(ENV)$(SETENV)my_setenv_func.c \
		  $(SOURCES)$(BUILTINS)$(ENV)$(UNSETENV)unsetenv.c \
		  $(SOURCES)$(BUILTINS)$(CD)cd.c \
		  $(SOURCES)$(BUILTINS)$(CD)cd_funcs.c \
		  $(SOURCES)$(BUILTINS)$(CD)cd_lib.c \
		  $(SOURCES)$(BUILTINS)$(ECHO)echo.c \
		  $(SOURCES)$(BUILTINS)$(ECHO)echo_calc.c \
		  $(SOURCES)$(BUILTINS)$(ECHO)echo_check.c \
		  $(SOURCES)$(BUILTINS)check_builtin.c \
		  $(SOURCES)$(EXECUTION)my_exec.c \
		  $(SOURCES)$(FREE_FCT)my_free_env.c \
		  $(SOURCES)$(FREE_FCT)my_free_env_ptr.c \
		  $(SOURCES)$(MAIN)main.c \
		  $(SOURCES)$(MAIN)my_signal.c \
		  $(SOURCES)$(MAIN)get_line.c \
		  $(SOURCES)$(MAIN)prompt.c

OBJS		= $(SRCS:.c=.o)

RM		= rm -f

CFLAGS		= -I ./Header -lmy -L ./Lib -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)	
#	make re -C Lib/
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) 

clean:
#	make clean -C Lib/
	$(RM) $(OBJS)

fclean: clean
#	make fclean -C Lib/
	$(RM) $(NAME)

re: fclean all
