CC = cc
# CFLAGS = -Wall -Werror -Wextra
NAME = minishell_lexer
SRC = 	main.c \
		builtin.c \
		string_utils.c \
		t_simple_cmds_utils.c \
		t_lexer_clear_utils.c \
		lexer/token_handling.c \
		lexer/lexer.c \
		lexer/parsing_utils.c \
		lexer/handle_redirections.c \
		lexer/error_handling.c \
		lexer/parser.c \
		lexer/parsing_extra_utilites.c

OBJ = $(SRC:.c=.o)

# Color codes
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[1;33m
NC = \033[0m # No Color

all: $(NAME)

$(NAME): $(OBJ)
	@echo "${GREEN}Compiling $(NAME)...${NC}"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) > /dev/null

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ > /dev/null

clean:
	@rm -f $(OBJ)

fclean: clean
	@echo "${RED}Full clean, removing $(NAME)...${NC}"
	@rm -f $(NAME)

re:
	@echo "${YELLOW}Recompiling $(NAME)...${NC}"
	@$(MAKE) fclean
	@$(MAKE) all
