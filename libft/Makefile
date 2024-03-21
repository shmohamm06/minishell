RESET		= \033[0m
GREEN		= \033[32m
YELLOW		= \033[33m

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

INC_DIR = include

MANDATORY = ft_strlcpy.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memmove.c \
			ft_memcmp.c ft_memcpy.c ft_memset.c ft_strdup.c ft_strchr.c get_next_line.c\
			ft_strlcat.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c \
			ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c \
			ft_striteri.c ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstlast.c ft_lstiter.c ft_lstclear.c ft_lstmap.c

OBJ_FILES_MANDATORY = $(MANDATORY:.c=.o)
OBJ_FILES_BONUS = $(BONUS:.c=.o)

%.o: %.c
	@cc -c -w $(CFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJ_FILES_MANDATORY) $(OBJ_FILES_BONUS)
	@$(AR) $(NAME) $(OBJ_FILES_MANDATORY) $(OBJ_FILES_BONUS)
	@ranlib $(NAME)
	@echo ""
	@echo "$(GREEN) ██▓     ██▓ ▄▄▄▄     █████▒▄▄▄█████▓"
	@echo "▓██▒    ▓██▒▓█████▄ ▓██   ▒ ▓  ██▒ ▓▒"
	@echo "▒██░    ▒██▒▒██▒ ▄██▒████ ░ ▒ ▓██░ ▒░"
	@echo "▒██░    ░██░▒██░█▀  ░▓█▒  ░ ░ ▓██▓ ░ "
	@echo "░██████▒░██░░▓█  ▀█▓░▒█░      ▒██▒ ░ "
	@echo "░ ▒░▓  ░░▓  ░▒▓███▀▒ ▒ ░      ▒ ░░   "
	@echo "░ ░ ▒  ░ ▒ ░▒░▒   ░  ░          ░    "
	@echo "  ░ ░    ▒ ░ ░    ░  ░ ░      ░      "
	@echo "    ░  ░ ░   ░                       "
	@echo "                  ░                  "
	@echo "Created: $(words $(OBJ_FILES_MANDATORY) $(OBJ_FILES_BONUS)) object file(s) for Libft"
	@echo "Created: $(NAME)$(RESET)"
	
bonus: $(OBJ_FILES_BONUS)
	$(AR) $(NAME) $^

clean: clean
	@rm -f $(NAME) $(OBJ_FILES_MANDATORY) $(OBJ_FILES_BONUS) *~
	@echo ""
	@echo "$(YELLOW) ██▓     ██▓ ▄▄▄▄     █████▒▄▄▄█████▓"
	@echo "▓██▒    ▓██▒▓█████▄ ▓██   ▒ ▓  ██▒ ▓▒"
	@echo "▒██░    ▒██▒▒██▒ ▄██▒████ ░ ▒ ▓██░ ▒░"
	@echo "▒██░    ░██░▒██░█▀  ░▓█▒  ░ ░ ▓██▓ ░ "
	@echo "░██████▒░██░░▓█  ▀█▓░▒█░      ▒██▒ ░ "
	@echo "░ ▒░▓  ░░▓  ░▒▓███▀▒ ▒ ░      ▒ ░░   "
	@echo "░ ░ ▒  ░ ▒ ░▒░▒   ░  ░          ░    "
	@echo "  ░ ░    ▒ ░ ░    ░  ░ ░      ░      "
	@echo "    ░  ░ ░   ░                       "
	@echo "                  ░                  "
	@echo "Removed: $(words $(OBJ_FILES_MANDATORY) $(OBJ_FILES_BONUS)) object file(s) from Libft"
	@echo "Removed: $(NAME)$(RESET)"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus