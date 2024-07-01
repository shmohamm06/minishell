/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:54:32 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/01 14:07:38 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../../minishell.h"

// execution.c
void	parse_input(t_mini *mini);

// check_exec_dir.c
int		is_path_directory(const char *path);
int		does_file_exist(const char *pathname);
int		handle_dot_command_check(t_cmd *cmd);

// design.c
char	*read_line_colored(void);

// dups.c
int		duplicate_output_fd(t_rdr *rdr);
int		duplicate_input_fd(t_rdr *rdr);
int		duplicate_append_fd(t_rdr *rdr);
int		parse_redirections(t_rdr *trdr, t_mini *mini, t_cmd *cmd);

// env_conv.c
void	*print_error_return(char *str, void *ret);
int		get_env_size(t_env *env);
char	*join_key_value(char *key, char *value);
char	*join_key_only(char *key, t_env *env);
char	**convert_env_to_array(t_mini *mini);

// execution_utils.c
int		check_executable_slash(t_mini *mini, t_cmd *cmd);
void	execute_in_directory(t_mini *mini, t_cmd *cmd);
void	execute_command_with_forking(t_mini *mini, t_cmd *cmd, char *cmd_path);
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
int		error_set_print_close(t_mini *mini, t_cmd *cmd, int error);

// redirections.c
int		parse_redirect(t_mini *mini, t_cmd *cmd);
int		file_no_exist(t_mini *mini, t_rdr *trdr);
int		ft_return_redirect_code(t_rdr *rdr);
int		check_file_rights(t_mini *mini, t_rdr *trdr);
int		ft_redirect(t_mini *mini, t_cmd *cmd);

#endif