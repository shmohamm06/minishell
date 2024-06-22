/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:17:26 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/22 13:05:05 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "built_ins.h"
# include "errors_and_utils.h"
# include "executor.h"


typedef struct s_global
{
	int						error_num;
	int						stop_heredoc;
	int						in_cmd;
	int						in_heredoc;
}							t_global;

t_global					g_global;

typedef enum e_tokens
{
	PIPE = 1,
	output,
	append,
	input,
	heredoc,
}							t_tokens;

typedef struct s_parser_tools
{
	t_lexer					*lexer_list;
	t_lexer					*redirections;
	int						num_redirections;
	struct s_tools			*tools;
}							t_parser_tools;

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

#endif