NAME	=	minishell

CC		=	@gcc
CFLAGS	=	-g3 -Wall -Wextra -Werror# -fsanitize=address
RLFLAGS =	-L/usr/local/lib -I/usr/local/include -lreadline

RM		=	@rm -f
ECHO	=	@echo

MAKELIB	=	@make -C libft
LIBFT	=	libft/libft.a
CLNLIB	=	@make clean -C libft
FCLNLIB	=	@make fclean -C libft


SRCS	=	SRCS/main.c \
			SRCS/signals.c \
			SRCS/execution/execution.c \
			SRCS/parsing/ft_parse_env.c \
			SRCS/parsing/ft_parse_token.c \
			SRCS/parsing/ft_parse_token_utils.c \
			SRCS/parsing/ft_parse_extra_2.c \
			SRCS/parsing/ft_parse_extra.c \
			SRCS/parsing/ft_tokenizer_1.c \
			SRCS/parsing/ft_tokenizer_2.c \
			SRCS/parsing/ft_tokenizer_3.c \
			SRCS/utils/ft_free_list.c \
			SRCS/utils/ft_print_list.c \
			SRCS/utils/temp_funs.c \
			SRCS/execution/env_conv.c \
			SRCS/execution/get_path_srcs.c \
			SRCS/execution/design.c \
			SRCS/execution/redirections.c \
			SRCS/execution/dups.c \
			SRCS/execution/redirections_srcs.c \
			SRCS/execution/check_exec_dir.c \
			SRCS/execution/execution_utils.c \
			SRCS/execution/heredoc.c \
			SRCS/execution/fd_handler.c \
			SRCS/execution/process_utils.c \
			SRCS/built_ins/ft_unset.c \
			SRCS/built_ins/ft_exit.c \
			SRCS/built_ins/builtins.c \
			SRCS/built_ins/ft_echo.c \
			SRCS/built_ins/ft_export.c \
			SRCS/built_ins/export_utils.c \
			SRCS/built_ins/ft_cd.c \
			SRCS/built_ins/cd_utils.c \

OBJS	=	$(SRCS:.c=.o)

$(NAME):	$(OBJS)
			$(MAKELIB)
			$(ECHO) "Compiling minishell ......"
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(RLFLAGS) 

all:		$(NAME)

clean:
			$(CLNLIB)
			$(RM) $(OBJS)

fclean:		
			$(FCLNLIB)
			$(ECHO) "Removing minishell ......."
			$(RM) $(NAME) $(OBJS)

re:			fclean all clean

exec:		all
			@./$(NAME)

rexec:		re
			@./$(NAME)

leaks:
			make re && make clean \
			&& clear \
			&& valgrind --leak-check=full \
			--suppressions=.rl.supp \
			--track-origins=yes \
			--show-leak-kinds=all -s \
			--track-fds=yes \
			./minishell

.PHONY: all clean fclean re