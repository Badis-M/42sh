##
## Makefile for 42sh in /home/maucha_a/Tekpi/PSU/PSU_2015_42sh
##
## Made by maucha_a
## Login   <maucha_a@epitech.net>
##
## Started on  Mon May 30 15:14:49 2016 maucha_a
## Last update Sat Jun  4 22:38:49 2016 Alexis Moisson
##

CC	=	cc

CFLAGS	+=	-Wno-padded -g
CFLAGS	+=	-W -Wall -Werror -Wextra
CFLAGS	+=	-I./include

RM	=	rm -f

NAME	= 	42sh

SRCS	= srcs/main_process/main.c \
	srcs/main_process/prompt.c \
	srcs/main_process/get_env.c \
	lib/display_success.c \
	lib/str_to_wordtab.c \
	lib/str_manip.c \
	lib/display_error.c \
	lib/my_getline.c \
	srcs/syscall/exec.c \
	srcs/builtins/cd.c \
	srcs/builtins/echo.c \
	srcs/manage_env/manage_pwd.c \
	srcs/builtins/exit.c \
	srcs/builtins/setenv.c \
	srcs/builtins/unsetenv.c \
	srcs/separators/redir_str.c \
	srcs/parsing/main_parsing.c \
	srcs/parsing/cmds_parsing.c \
	srcs/parsing/get_file.c \
	lib/split_wordtab.c \
	srcs/main_process/main_process.c

OBJS	= 	$(SRCS:.c=.o)

all: 		$(NAME)

$(NAME): 	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
