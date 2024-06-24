/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:32:13 by mmassarw          #+#    #+#             */
/*   Updated: 2023/01/29 19:40:36 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <sys/param.h>
# include <limits.h>
# include <stdint.h>

# define DEC "0123456789"
# define HEXL "0123456789abcdef"
# define HEXU "0123456789ABCDEF"
# define BUFFER_SIZE 4095

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//		=================		//
//		is		functions		//
//		=================		//

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

//		=================		//
//		mem		functions		//
//		=================		//

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_realloc(void *ptr, size_t new_size, size_t old_size);
void	*ft_free_split(char **split);
void	*ft_free(void *ptr);

//		=================		//
//		str		functions		//
//		=================		//

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strcpy(char *dst, const char *src);
size_t	ft_strlcat(char *dst, const char *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

//		=================		//
//		to		functions		//
//		=================		//

int		ft_toupper(int c);
int		ft_tolower(int c);

//		=================		//
//		conv	functions		//
//		=================		//

int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);

//		=================		//
//		split	functions		//
//		=================		//

char	**ft_split(char const *s, char c);
void	*ft_free_split(char **split);

//		=================		//
//		put		functions		//
//		=================		//

int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//		=================		//
//		list	functions		//
//		=================		//

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//		=================		//
//		gnl		functions		//
//		=================		//

char	*get_next_line(int fd);

//		=================		//
//		printf	functions		//
//		=================		//

int		ft_printf(const char *arg, ...);

//		=================		//
//		fd_printf	functions	//
//		=================		//

int		fd_putchar(int fd, char c);
int		fd_putnbr(int fd, int nb);
int		fd_putstr(int fd, char *str);
int		fd_put_hex(int fd, unsigned int nb, char c);
int		fd_putnbr_u(int fd, unsigned int nb);
int		fd_put_address(int fd, unsigned long long nb);
int		fd_parse(int fd, va_list ptr, char c);
int		fd_printf(int fd, const char *str, ...);
char	*gl_strjoin(char *s1, char *s2);
char	*gl_strchr(const char *s, int c);
int		gl_strlen(char *str);

#endif
