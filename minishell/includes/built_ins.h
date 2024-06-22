/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyaseen <wyaseen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:49:12 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/22 17:05:33 by wyaseen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_INS_H
# define BUILT_INS_H

# include "minishell.h"

# define READLINE_MSG "\033[1;36mminishell\033[34m$ \033[0m"

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