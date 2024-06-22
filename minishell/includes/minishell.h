/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyaseen <wyaseen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:17:26 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/22 18:44:15 by wyaseen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "../parsing/lexer.h"
# include "built_ins.h"
# include "errors_and_utils.h"
# include "executor.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define HEREDOC_MSG	"\033[1;34m> \033[0m"

typedef struct s_global
{
	int		error_num;
	int		stop_heredoc;
	int		in_cmd;
	int		in_heredoc;
}			t_global;

t_global	g_global;

int			find_matching_quote(char *line, int i, int *num_del, int del);
int			count_quotes(char *line);

// typedef enum e_tokens
// {
// 	PIPE = 1,
// 	output,
// 	append,
// 	input,
// 	heredoc,
// }	t_tokens;

// typedef struct s_parser_tools
// {
// 	struct s_lexer	*lexer_list;
// 	struct s_lexer	*redirections;
// 	int		num_redirections;
// 	struct s_tools	*tools;
// }	t_parser_tools;

// typedef struct s_lexer
// {
// 	char		*str;
// 	t_tokens	token;
// 	int		i;
// 	struct s_lexer	*next;
// 	struct s_lexer	*prev;
// }	t_lexer;

// typedef struct s_tools
// {
// 	char		*args;
// 	char		**paths;
// 	char		**envp;
// 	struct s_simple_cmds *simple_cmds;
// 	struct s_lexer	*lexer_list;
// 	char		*pwd;
// 	char		*old_pwd;
// 	int		pipes;
// 	int		*pid;
// 	bool		heredoc;
// 	bool		reset;
// }	t_tools;

// typedef struct s_simple_cmds
// {
// 	char		**str;
// 	int		num_redirections;
// 	int		(*builtin)(struct s_tools *, struct s_simple_cmds *);
// 	char		*hd_file_name;
// 	struct s_lexer	*redirections;
// 	struct s_simple_cmds *next;
// 	struct s_simple_cmds *prev;
// }	t_simple_cmds;

#endif // MINISHELL_H
