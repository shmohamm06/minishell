# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 19:58:12 by mmassarw          #+#    #+#              #
#    Updated: 2023/02/01 15:52:56 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC		=	@gcc
CFLAGS	=	-Wall -Wextra -Werror

RM		=	@rm -f

ECHO	=	@echo

SRCS	=	ft_atoi.c \
			ft_calloc.c \
			ft_bzero.c \
			ft_free_split.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_printf.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_realloc.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			get_next_line.c \
			ft_free.c \
			fd_parse.c \
			fd_printf.c \
			fd_put_address.c \
			fd_put_hex.c \
			fd_putchar.c \
			fd_putnbr_u.c \
			fd_putnbr.c \
			fd_putstr.c \
			gl_strchr.c \
			gl_strlen.c \
			gl_strjoin.c
			
			

OBJS	=	$(SRCS:.c=.o)

$(NAME):	$(OBJS)
			$(ECHO) "Compiling libft .........."
			@ar -rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(ECHO) "Removing obj files ......."
			$(RM) $(OBJS)

fclean:		clean
			$(ECHO) "Removing libft.a files ..."
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re