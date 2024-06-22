RESET = \033[0m
GREEN = \033[32m
YELLOW = \033[33m

NAME = minishell
CC = cc
LIB_DIR = libft
CFLAGS =  -Wall -Wextra -Werror -I/Users/$(USER)/.brew/opt/readline/include

# Source files from both parts, considering the directory structure
SRCS =  main.c \
        minishell_loop.c \
        parsing/t_simple_cmds_utils.c \
        parsing/t_lexer_clear_utils.c \
        parsing/lexer/token_handling.c \
        parsing/lexer/lexer.c \
        parsing/lexer/parsing_utils.c \
        parsing/lexer/handle_redirections.c \
        parsing/lexer/error_handling.c \
        parsing/lexer/parser.c \
        parsing/lexer/parsing_extra_utilites.c \
        executor/expander.c \
        executor/check_redirections.c  \
        executor/executor.c \
        executor/handle_cmds.c \
        executor/here_doc.c \
        built_ins/built_ins.c  \
        built_ins/built_utils.c \
        built_ins/ft_cd.c \
        built_ins/ft_echo.c  \
        built_ins/ft_env.c  \
        built_ins/ft_exit.c  \
        built_ins/ft_export.c  \
        built_ins/ft_pwd.c \
        built_ins/ft_unset.c \
        errors_and_utils/pasre_env.c\
        errors_and_utils/executor_utils.c \
        errors_and_utils/expander_utils.c \
        errors_and_utils/utils_and_errors.c \

# Object files corresponding to source files
OBJS = $(SRCS:.c=.o)

# Compilation rules
$(NAME): $(LIB_DIR)/libft.a $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_DIR)/libft.a -o  -lreadline -L/Users/$(USER)/.brew/opt/readline/lib -o $(NAME)
	@echo "$(GREEN)Created: $(words $(OBJS)) object file(s) for minishell"
	@echo "Created: $(NAME)$(RESET)"

$(LIB_DIR)/libft.a:
	@$(MAKE) -C $(LIB_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIB_DIR) clean
	@echo "$(YELLOW)Removed: $(words $(OBJS)) object file(s) for minishell"
	@echo "Removed: $(NAME)$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIB_DIR)/libft.a

re: fclean all

.PHONY: all clean fclean re
