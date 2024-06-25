/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:54:32 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/25 11:09:52 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../../minishell.h"

// execution.c
void	parse_input(t_mini *mini);

// check_exec_dir.c
int		is_directory(const char *path);
int		file_exists(const char *pathname);
int		dot_dir_check(t_cmd *cmd);

// design.c
char	*read_line_colored(int random);
char	*read_line_colored2(int random, char *path);

// dups.c
int		ft_dup2_output(t_rdr *rdr);
int		ft_dup2_input(t_rdr *rdr);
int		ft_dup2_append(t_rdr *rdr);
int		parse_dups(t_rdr *trdr, t_mini *mini, t_cmd *cmd);

// env_conv.c
void	*perror_return(char *str, void *ret);
int		return_env_size(t_env *env);
char	*join_key_val(char *key, char *value);
char	*join_key_eq(char *key, t_env *env);
char	**convert_env(t_mini *mini);

// execution_utils.c
int		is_slash_exec(t_mini *mini, t_cmd *cmd);
void	execute_in_dir(t_mini *mini, t_cmd *cmd);
void	execute_command_fork(t_mini *mini, t_cmd *cmd, char *cmd_path);
void	execute_pathed_cmd(t_mini *mini, t_cmd *cmd);

// fd_ handler.c
void	close_all_fds(t_mini *mini);
int		ft_close(int fd, int limit, t_cmd *cmd);

// get_path_srcs.c
char	*split_and_join(char *av_cmd, char *splitted);
int		word_count(char const *s, char c);
char	*get_path(char *cmd, char *env);

// here_doc.c
void	handle_heredoc(t_mini *mini);
void	take_heredoc_input(t_rdr *rdr);
int		ft_pipe_heredoc(t_rdr *rdr, t_mini *mini, t_cmd *cmd);

// process_utils.c
int		is_parent_compatible(t_cmd *cmd);
int		is_parent_exec(t_cmd *cmd);
void	execute_in_parent(t_mini *mini);
void	wait_for_children(t_mini *mini);

// redirection_srcs.c
void	ft_close_rdr_backv2(t_rdr *ordr, t_rdr *irdr);
void	close_rdr_back(t_cmd *cmd);
int	error_set_print_close(t_mini *mini, t_cmd *cmd, int error);

// redirections.c
int		parse_redirect(t_mini *mini, t_cmd *cmd);
int		file_no_exist(t_mini *mini, t_rdr *trdr);
int		ft_return_redirect_code(t_rdr *rdr);
int		check_file_rights(t_mini *mini, t_rdr *trdr);
int		ft_redirect(t_mini *mini, t_cmd *cmd);

#endif