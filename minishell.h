/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:50:59 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/25 11:04:22 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"

# include <stdbool.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <string.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stddef.h>

//	colors
# define BLUE_FONT	"\033[1;36m"
# define RESET_FONT	"\033[0m"
# define RED_FONT	"\033[31m"
# define RF	"\033[0m"
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
enum e_rdr
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
	char			*file;
	int				fd;
	int				og_fd;
	int				dup2_fd;
	pid_t			fork_id;
	int				ret;
	int				fdpipe[2];
	enum e_rdr		e_rdr;
	struct s_rdr	*next;
}	t_rdr;

// token enumiration
enum e_tokentype
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
}	t_token;

// command linked list
typedef struct s_cmd
{
	char			**arg;
	t_rdr			*rdr;
	int				fd_pipe[2];
	struct s_cmd	*next;
	pid_t			fork_id;
}	t_cmd;

// enviromental linked list
typedef struct s_env
{
	char			*key;
	char			*value;
	bool			initialised;
	struct s_env	*next;
}	t_env;

// struct with all the other structs in it
typedef struct s_mini
{
	t_cmd	*l_cmd;
	t_env	*l_env;
	char	*rl;
	t_token	*l_token;
	char	**token;
	int		cmd_flag;
}	t_mini;

// temporary functions, tbc if they'd be used or not

int		random_between(int min, int max);

// parsing

void	ft_tokenize(t_mini *mini);
int		ft_check_rdr(char *string);
void	ft_populate_cmd(t_mini *mini, t_cmd *cmd, char **token, int i[0]);
int		ft_count_till_pipe(char **token);
void	ft_parse_env(t_mini *mini, const char **envp);
void	ft_parse_token(t_mini *mini, char **token);
void	set_env_underscore(char *cmd, t_mini *mini);

// frees

void	ft_free_cmd(t_cmd *s_cmd);
void	ft_free_ltoken(t_token *list);
void	ft_free_env(t_env *env_list);
void	ft_free_cycle(t_mini *mini);
void	ft_free_all(t_mini *mini);

// exit shell

void	ft_exit_shell(t_mini *m, int er, char *p_er, int fd);

// utils

void	ft_print_cmd(t_cmd *s_head);
void	ft_print_split(char **split);

// global exit code

int	g_exit_code;

// void	exit_and_print(int code);
// void	exit_success(char **args, t_mini *mini);

// int		error_set_print_close(t_mini *mini, t_cmd *cmd, int error);

#endif