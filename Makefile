RESET		= \033[0m
GREEN		= \033[32m
YELLOW		= \033[33m

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB_DIR = libft

SRCS = pipex.c pipex_utils.c here_doc_and_process.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(LIB_DIR)/libft.a $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_DIR)/libft.a -o $(NAME)
	@touch infile
	@touch outfile
	@echo ""
	@echo "$(GREEN) ███▄ ▄███▓ ██▓ ███▄    █  ██▓  ██████  ██░ ██ ▓█████  ██▓     ██▓    "
	@echo "▓██▒▀█▀ ██▒▓██▒ ██ ▀█   █ ▓██▒▒██    ▒ ▓██░ ██▒▓█   ▀ ▓██▒    ▓██▒    "
	@echo "▓██    ▓██░▒██▒▓██  ▀█ ██▒▒██▒░ ▓██▄   ▒██▀▀██░▒███   ▒██░    ▒██░    "
	@echo "▒██    ▒██ ░██░▓██▒  ▐▌██▒░██░  ▒   ██▒░▓█ ░██ ▒▓█  ▄ ▒██░    ▒██░    "
	@echo "▒██▒   ░██▒░██░▒██░   ▓██░░██░▒██████▒▒░▓█▒░██▓░▒████▒░██████▒░██████▒"
	@echo "░ ▒░   ░  ░░▓  ░ ▒░   ▒ ▒ ░▓  ▒ ▒▓▒ ▒ ░ ▒ ░░▒░▒░░ ▒░ ░░ ▒░▓  ░░ ▒░▓  ░"
	@echo "░  ░      ░ ▒ ░░ ░░   ░ ▒░ ▒ ░░ ░▒  ░ ░ ▒ ░▒░ ░ ░ ░  ░░ ░ ▒  ░░ ░ ▒  ░"
	@echo "░      ░    ▒ ░   ░   ░ ░  ▒ ░░  ░  ░   ░  ░░ ░   ░     ░ ░     ░ ░   "
	@echo "       ░    ░           ░  ░        ░   ░  ░  ░   ░  ░    ░  ░    ░  ░"
	@echo "                                                                      "
	@echo "Created: $(words $(OBJS) + 2) programme file(s) for minishell"
	@echo "Created: $(NAME)$(RESET)"

$(LIB_DIR)/libft.a:
	@$(MAKE) -C $(LIB_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -f infile outfile
	@$(MAKE) -C $(LIB_DIR) clean
	@echo ""
	@echo "$(YELLOW) ███▄ ▄███▓ ██▓ ███▄    █  ██▓  ██████  ██░ ██ ▓█████  ██▓     ██▓    "
	@echo "▓██▒▀█▀ ██▒▓██▒ ██ ▀█   █ ▓██▒▒██    ▒ ▓██░ ██▒▓█   ▀ ▓██▒    ▓██▒    "
	@echo "▓██    ▓██░▒██▒▓██  ▀█ ██▒▒██▒░ ▓██▄   ▒██▀▀██░▒███   ▒██░    ▒██░    "
	@echo "▒██    ▒██ ░██░▓██▒  ▐▌██▒░██░  ▒   ██▒░▓█ ░██ ▒▓█  ▄ ▒██░    ▒██░    "
	@echo "▒██▒   ░██▒░██░▒██░   ▓██░░██░▒██████▒▒░▓█▒░██▓░▒████▒░██████▒░██████▒"
	@echo "░ ▒░   ░  ░░▓  ░ ▒░   ▒ ▒ ░▓  ▒ ▒▓▒ ▒ ░ ▒ ░░▒░▒░░ ▒░ ░░ ▒░▓  ░░ ▒░▓  ░"
	@echo "░  ░      ░ ▒ ░░ ░░   ░ ▒░ ▒ ░░ ░▒  ░ ░ ▒ ░▒░ ░ ░ ░  ░░ ░ ▒  ░░ ░ ▒  ░"
	@echo "░      ░    ▒ ░   ░   ░ ░  ▒ ░░  ░  ░   ░  ░░ ░   ░     ░ ░     ░ ░   "
	@echo "       ░    ░           ░  ░        ░   ░  ░  ░   ░  ░    ░  ░    ░  ░"
	@echo "                                                                      "
	@echo "Removed: $(words $(OBJS) + 2) programme file(s) for minishell"
	@echo "Removed: $(NAME)$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIB_DIR)/libft.a
	@rm -f infile outfile

re: fclean all

.PHONY: all clean fclean re
