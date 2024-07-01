/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyaseen <wyaseen@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:50:59 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/01 20:21:08 by wyaseen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <curses.h>
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stddef.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <term.h>
# include <termios.h>



//	colors
# define BLUE_FONT "\033[1;36m"
# define RESET_FONT "\033[0m"
# define RED_FONT "\033[31m"
# define RF "\033[0m"
// eeror strings
# define ALPHA_EXIT "minishell: exit: %s: numeric argument required\n"
# define UNSET_NO_ARG "unset: not enough arguments\n"

// command flags
# define BUILTIN 68
# define PWD 923
# define VALUE 432
# define KEY 645

//builtin exit codes
# define SUCCESS 0
# define PWD_FAIL_CODE 2
# define ENV_FAIL_CODE 1
# define EXPORT_FAIL_CODE 1
# define EXPORT_FLAG 654
# define UNSET_FLAG 456
# define UNSET_FAIL_CODE 1
# define COMMAND_FAIL 127
# define EXIT_FAIL 1
# define EXIT_ALPHA_CODE 255
# define CD_FAIL 1
# define EXIST 0

// color pallete
# define BLUE 1
# define WHITE 2
# define YELLOW 3
# define GREEN 4
# define PURPLE 5
# define DARK_CYAN 6

// redirections enumiration
enum					e_rdr
{
	NONE,
	INPUT,
	OUTPUT,
	HEREDOC,
	APPEND,
};

// redirections linked list
typedef struct s_rdr
{
	char				*file;
	int					fd;
	int					og_fd;
	int					dup2_fd;
	pid_t				fork_id;
	int					ret;
	int					fdpipe[2];
	enum e_rdr			e_rdr;
	struct s_rdr		*next;
}						t_rdr;

// token enumiration
enum					e_tokentype
{
	SPACES,
	SINGLE,
	DOUBLE,
	VARIABLE,
	REDIRECTION,
	PIPE,
	WORD,
};

// token structure
typedef struct s_token
{
	char				*content;
	enum e_tokentype	type;
	struct s_token		*next;
	struct s_token		*prev;
}						t_token;

// command linked list
typedef struct s_cmd
{
	char				**arg;
	t_rdr				*rdr;
	int					fd_pipe[2];
	struct s_cmd		*next;
	pid_t				fork_id;
}						t_cmd;

// enviromental linked list
typedef struct s_env
{
	char				*key;
	char				*value;
	bool				initialised;
	struct s_env		*next;
}						t_env;

// struct with all the other structs in it
typedef struct s_mini
{
	t_cmd				*l_cmd;
	t_env				*l_env;
	char				*rl;
	t_token				*l_token;
	char				**token;
	int					cmd_flag;
}						t_mini;

typedef struct s_token_groups
{
	char				single[10000];
	char				doubleq[10000];
	char				variable[10000];
	char				redirection[10000];
	char				pipe[10000];
	char				word[10000];
}						t_token_groups;

// // signals.c
void 					heredoc_prompt(void);
void 					command_prompt(void);
void					init_signals(void);
void 					minishell_prompt(void);
void 					signal_handler_parent(int signum);
void 					handle_heredoc(void);



// parsing

void					ft_tokenize(t_mini *mini);
int						is_redirection(char *string);
void					populate_cmd(t_mini *mini, t_cmd *cmd, char **token,
							int i[0]);
int						count_till_pipe(char **token);
void					ft_parse_env(t_mini *mini, const char **envp);
void					parse_tokens(t_mini *mini, char **token);
void					set_env_var(char *cmd, t_mini *mini);
void	concatenate_token(t_token_groups *groups,
						t_token *current);
void					print_token_groups(t_token_groups *groups);

char					*ft_strjoin_free(char *s1, const char *s2);

// frees

void					free_command_list(t_cmd *s_cmd);
void					free_token_list(t_token *list);
void					free_environment_list(t_env *env_list);
void					free_mini_cycle(t_mini *mini);
void					free_mini_all(t_mini *mini);

// exit shell

void					exit_shell(t_mini *m, int er, char *p_er, int fd);

// utils

void					print_commands(t_cmd *s_head);
void					print_split(char **split);

// parse_extra.c
char					**token_list_to_array(t_token *head);
char					*add_middle_string(char *start, t_env *match, size_t i,
							t_mini *mini);
char					*expand_string(char *quote, t_mini *mini);
void					collapse_quotes(t_mini *mini);
char					**token_list_to_array(t_token *head);
void					ft_tokenize(t_mini *mini);
void					evaluate_over_character(size_t *i, const char *str,
							enum e_tokentype *type);
void					tokenize_input(t_mini *mini);
void					print_token_list_by_type(t_token *head);
bool					evaluate_tokens(t_mini *mini);
bool					evaluate_redirection(t_token *head, t_mini *mini);
void					expand_variables(t_mini *mini);

// global exit code

int						g_exit_code;

// void	exit_and_print(int code);
// void	exit_success(char **args, t_mini *mini);

// int		handle_error_set_print_close(t_mini *mini, t_cmd *cmd, int error);

#endif