/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:16:07 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/22 11:24:32 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "minishell.h"

# define HEREDOC_MSG	"\033[1;34m> \033[0m"

// handle_cmds.c
int		find_cmd(t_simple_cmds *cmd, t_tools *mini);
void	handle_cmd(t_simple_cmds *cmd, t_tools *tools);
void	dup_cmd(t_simple_cmds *cmd, t_tools *tools, int end[2], int fd_in);
void	single_cmd(t_simple_cmds *cmd, t_tools *mini);

// check_redirections.c
int		check_append_outfile(t_lexer *redirections);
int		handle_infile(char *file_name);
int		handle_outfile(t_lexer *redirection);
int		check_redirections(t_simple_cmds *cmd);

// here_doc.c
int		create_heredoc(t_lexer *heredoc, bool quotes, t_tools *tools,
			char *file_name);
int		ft_heredoc(t_tools *tools, t_lexer *heredoc, char *file_name);
char	*generate_heredoc_filename(void);
int		send_heredoc(t_tools *tools, t_simple_cmds *cmd);

// executor.c
int		loop_if_dollar_sign(t_tools *tools, char *str, char **tmp, int j);
int		handle_digit_after_dollar(int j, char *str);
char	*detect_dollar_sign(t_tools *tools, char *str);
char	**expander(t_tools *tools, char **str);
char	*expander_str(t_tools *tools, char *str);

#endif