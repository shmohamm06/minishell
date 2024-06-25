/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:17:56 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/25 10:47:09 by shmohamm         ###   ########.fr       */
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
void	set_env_pwd(t_mini *mini);
void	set_old_pwd(t_mini *mini, char *old_pwd);
void	cd_return_success(t_mini *mini, char *old_pwd);
char	*find_str_env(char *arg, t_mini *mini, int flag);

// ft_cd.c
void	ft_cd(char **args, t_mini *mini);
void	go_to_home(t_mini *mini, char *old_pwd);
void	go_to_old_pwd(t_mini *mini, char *old_pwd);

// ft_echo.c
void	ft_echo(char **args);

// ft_exit.c
void	ft_exit(char **args, t_mini *mini);
int		arg_count(char **args);
int		check_exit_alpha(char **args);

// ft_export.c
void	ft_export(char **args, t_mini *mini);
void	parse_new_export(char *arg, t_mini *mini);
void	ft_modify_env(char *arg, t_mini *mini);
t_env	*env_already_exist(char *arg, t_mini *mini);
int		check_export_args(char *arg);

// ft_unset.c
void	ft_unset(char **args, t_mini *mini);
int		check_valid_identifier_export(char *arg);
int		check_unset_args(char *arg);
void	free_single_env(t_env *node);
void	delete_env_list(char *arg, t_mini *mini);

// export_utils.c
int		check_valid_identifier(char *arg);
void	add_to_env(char *arg, t_mini *mini);
char	*set_env_value(char *arg, t_env *new);
char	*set_env_key(char *arg);
void	print_export(t_mini *mini);

#endif