/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:17:56 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/01 13:58:17 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_INS_H
# define BUILT_INS_H

# include "../../minishell.h"

// built_ins.c
void	print_pwd(void);
void	print_env(t_mini *mini);
int		builtin_check(t_mini *mini, t_cmd *cmd);

// cd_utils.c
void	update_pwd_env(t_mini *mini);
void	update_oldpwd_env(t_mini *mini, char *old_pwd);
void	handle_cd_success(t_mini *mini, char *old_pwd);
char	*get_env_value_or_key(char *arg, t_mini *mini, int flag);

// ft_cd.c
void	ft_cd(char **args, t_mini *mini);
void	change_to_home_directory(t_mini *mini, char *old_pwd);
void	change_to_old_directory(t_mini *mini, char *old_pwd);

// ft_echo.c
void	ft_echo(char **args);

// ft_exit.c
void	ft_exit(char **args, t_mini *mini);
int		count_arguments(char **args);
int		contains_alpha(char **args);

// ft_export.c
void	ft_export(char **args, t_mini *mini);
void	parse_new_export(char *arg, t_mini *mini);
void	update_env_variable(char *arg, t_mini *mini);
t_env	*find_env_variable(char *arg, t_mini *mini);
int		is_valid_export_arg(char *arg);

// ft_unset.c
void	ft_unset(char **args, t_mini *mini);
int		is_valid_identifier_export(char *arg);
int		should_unset_arg(char *arg);
void	free_env_node(t_env *node);
void	delete_env_list(char *arg, t_mini *mini);

// export_utils.c
int		is_valid_identifier(char *arg);
void	add_env_variable(char *arg, t_mini *mini);
char	*extract_env_value(char *arg, t_env *new);
char	*extract_env_key(char *arg);
void	print_export_list(t_mini *mini);

#endif