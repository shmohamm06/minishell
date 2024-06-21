/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyaseen <wyaseen@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:49:12 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/21 14:44:22 by wyaseen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_INS_H
# define BUILT_INS_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define READLINE_MSG "\033[1;36mminishell\033[34m$ \033[0m"

typedef struct s_simple_cmds
{
	char					**args;
	// Add other fields as needed
}							t_simple_cmds;

typedef struct s_global
{
	int						error_num;
	int						stop_heredoc;
	int						in_cmd;
	int						in_heredoc;
}							t_global;

t_global					g_global;

typedef enum s_tokens
{
	PIPE = 1,
	GREAT,
	GREAT_GREAT,
	LESS,
	LESS_LESS,
}							t_tokens;

typedef struct s_lexer
{
	char					*str;
	t_tokens				token;
	int						i;
	struct s_lexer			*next;
	struct s_lexer			*prev;
}							t_lexer;

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
}							t_tools;

typedef struct s_simple_cmds
{
	char					**str;
	int						num_redirections;
	int						(*builtin)(t_tools *, struct s_simple_cmds *);
	char					*hd_file_name;
	t_lexer					*redirections;
	struct s_simple_cmds	*next;
	struct s_simple_cmds	*prev;
}							t_simple_cmds;

// built-ins.c
int	(*builtin_arr(char *str))(t_tools *tools, t_simple_cmds *simple_cmd);

// built_utils.c
int							find_pwd(t_tools *mini);
void						change_path(t_tools *mini);
size_t						check_equal_sign(char *str);
char						*delete_quotes_value(char *str);
int							check_valid_identifier(char c);

// ft_cd.c
int							specific_path(char *str, t_tools *mini);
char						*find_path_ret(char *str, t_tools *mini);
void						add_path_to_env(t_tools *mini);
int							ft_cd(t_tools *mini, t_simple_cmds *cmd);

// ft_exit.c
void						free_struct(t_tools *tools);
void						determine_exit_code(char **str);
int							ft_exit(t_tools *mini, t_simple_cmds *cmd);

// ft_export.c
int							check_if_var_exists(t_tools *tools, char *str);
char						**whileloop_add_var(char **arr, char **result,
		char *str);
char						**add_variable(char **arr, char *str);
int							ft_export(t_tools *mini, t_simple_cmds *cmd);

// ft_unset.c
char						**whileloop_del_var(char **arr, char **rtn,
		char *str);
char						**del_var(char **arr, char *str);
int							ft_unset(t_tools *tools, t_simple_cmds *simple_cmd);

//ft ft_echo.c
void						print_input_string(int i, char **str, int out);
int							ft_echo(t_simple_cmds *cmd);

// ft_env.c
int							ft_env(t_tools *mini);

// ft_pwd.c
int							ft_pwd(t_tools *mini);

// loop
int							implement_tools(t_tools *tools);
int							prepare_executor(t_tools *tools);
int							minishell_loop(t_tools *tools);

#endif