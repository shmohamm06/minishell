#ifndef LEXER_H
# define LEXER_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h> // For size_t and dynamic memory allocation functions
# include <string.h> // For strdup (if you decide to copy the string)
#include <unistd.h>

// Enumeration for different types of tokens recognized by the lexer
typedef enum e_tokens
{
	PIPE = 1,
	output,
	append,
	input,
	heredoc,
}							t_tokens;

// Structure for a lexer token node
typedef struct s_lexer
{
	char					*str;
	t_tokens				token;
	int i;
	struct s_lexer			*next;
	struct s_lexer			*prev;
}							t_lexer;

typedef struct s_parser_tools
{
	t_lexer			*lexer_list;
	t_lexer			*redirections;
	int				num_redirections;
	struct s_tools	*tools;
}	t_parser_tools;


// General structure for command execution tools, environment variables, etc.
typedef struct s_tools
{
	char					*args;
	char					**paths;
	char					**envp;
	struct s_simple_cmds	*simple_cmds;
	t_lexer					*lexer_list;
	char					*pwd;
	char					*old_pwd;
	int						pipes;
	int						*pid;
	bool					heredoc;
	bool					reset;
}	t_tools;

typedef struct s_simple_cmds
{
	char					**str;
	int						(*builtin)(t_tools *, struct s_simple_cmds *);
	int						num_redirections;
	char					*hd_file_name;
	t_lexer					*redirections;
	struct s_simple_cmds	*next;
	struct s_simple_cmds	*prev;
}	t_simple_cmds;






// lexer.c
int							add_node(char *str, t_tokens token,
								t_lexer **lexer_list);
t_lexer						*ft_lexernew(char *str, int token);
void						ft_lexeradd_back(t_lexer **lst, t_lexer *new);

// token_handling.c
t_tokens					check_token(int c);
int							handle_token(char *str, int i,
								t_lexer **lexer_list);
int							read_words(int i, char *str, t_lexer **lexer_list);
int							token_reader(t_tools *tools);
t_tokens					get_token_type(char *str, int i, int *advance);

// string_utils.c
size_t						ft_strlen(const char *str);
char						*ft_strdup(const char *s1);
char						*ft_substr(char const *s, unsigned int start,
								size_t len);

// parsing_utils.c
int							skip_quoted_segment(const char *input,
								unsigned int start_index, char quote_char);
int							skip_spaces(char *str, int i);
int							is_whitespace(char c);



char	*ft_strjoin(char const *s1, char const *s2);
t_lexer	*ft_lexerclear_one(t_lexer **lst);
void	ft_lexerdel_first(t_lexer **lst);
void	ft_lexerdelone(t_lexer **lst, int key);
void	ft_lexerclear(t_lexer **lst);
char	*join_heredoc(char *str1, char *str2);
int	add_new_redirection(t_lexer *tmp, t_parser_tools *parser_tools);
void	rm_redirections(t_parser_tools *parser_tools);


void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
int	parser_double_token_error(t_tools *tools, t_lexer *lexer_list,
	t_tokens token);
int	ft_error(int error);
void	parser_error(t_tools *tools, t_lexer *lexer_list);



t_simple_cmds	*ft_simple_cmdsnew(char **str,
	int num_redirections, t_lexer *redirections);

void	ft_simple_cmdsadd_back(t_simple_cmds **lst, t_simple_cmds *new);

void	ft_simple_cmds_rm_first(t_simple_cmds **lst);

void	ft_simple_cmdsclear(t_simple_cmds **lst);

t_simple_cmds	*ft_simple_cmdsfirst(t_simple_cmds *map);

void reset_tools(t_tools *tools);
int	export_error(char *c);
void	lexer_error(t_tools *tools);
int	(*builtin_arr(char *str))(t_tools *tools, t_simple_cmds *simple_cmd);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	free_arr(char **split_arr);

t_simple_cmds	*initialize_cmd(t_parser_tools *parser_tools);
int	handle_pipe_errors(t_tools *tools, t_tokens token);
int	parser(t_tools *tools);
t_parser_tools	init_parser_tools(t_lexer *lexer_list, t_tools *tools);
void	count_pipes(t_lexer *lexer_list, t_tools *tools);
int	count_args(t_lexer *lexer_list);
t_lexer	*find_next_cmd(t_lexer *lexer_lst);
void	*ft_calloc(size_t count, size_t size);
void	*ft_bzero(void *str, size_t n);



void		mini_echo(t_tools *tools, t_simple_cmds *simple_cmd);

void		mini_cd(t_tools *tools, t_simple_cmds *simple_cmd);

void		mini_pwd(t_tools *tools, t_simple_cmds *simple_cmd);

void		mini_export(t_tools *tools, t_simple_cmds *simple_cmd);

void		mini_unset(t_tools *tools, t_simple_cmds *simple_cmd);

void		mini_env(t_tools *tools, t_simple_cmds *simple_cmd);

void		mini_exit(t_tools *tools, t_simple_cmds *simple_cmd);

void		mini_continue(t_tools *tools, t_simple_cmds *simple_cmd);



#endif /* LEXER_H */