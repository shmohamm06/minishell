NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB_DIR = libft

SRCS = pipex.c pipex_utils.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(LIB_DIR)/libft.a $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_DIR)/libft.a -o $(NAME)
	@touch infile
	@touch outfile

$(LIB_DIR)/libft.a:
	@$(MAKE) -C $(LIB_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -f infile outfile
	@$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIB_DIR)/libft.a
	@rm -f infile outfile

re: fclean all

.PHONY: all clean fclean re
