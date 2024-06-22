/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyaseen <wyaseen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:16:07 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/22 18:38:21 by wyaseen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "minishell.h"

// handle_cmds.c
int				find_cmd(t_simple_cmds *cmd, t_tools *mini);
void			handle_cmd(t_simple_cmds *cmd, t_tools *tools);
void			dup_cmd(t_simple_cmds *cmd, t_tools *tools, int end[2],
					int fd_in);
void			single_cmd(t_simple_cmds *cmd, t_tools *mini);

// check_redirections.c
int				check_append_outfile(t_lexer *redirections);
int				handle_infile(char *file_name);
int				handle_outfile(t_lexer *redirection);
int				check_redirections(t_simple_cmds *cmd);

// here_doc.c
int				create_heredoc(t_lexer *heredoc, bool quotes, t_tools *tools,
					char *file_name);
int				ft_heredoc(t_tools *tools, t_lexer *heredoc, char *file_name);
char			*generate_heredoc_filename(void);
int				send_heredoc(t_tools *tools, t_simple_cmds *cmd);

// expander.c
int				loop_if_dollar_sign(t_tools *tools, char *str, char **tmp,
					int j);
int				handle_digit_after_dollar(int j, char *str);
char			*detect_dollar_sign(t_tools *tools, char *str);
char			**expander(t_tools *tools, char **str);
char			*expander_str(t_tools *tools, char *str);

// executor.c
t_simple_cmds	*call_expander(t_tools *tools, t_simple_cmds *cmd);
int				pipe_wait(int *pid, int amount);
int				ft_fork(t_tools *tools, int end[2], int fd_in,
					t_simple_cmds *cmd);
int				check_fd_heredoc(t_tools *tools, int end[2],
					t_simple_cmds *cmd);
int				executor(t_tools *tools);

#endif