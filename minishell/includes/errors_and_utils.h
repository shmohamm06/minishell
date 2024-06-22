/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:02:48 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/22 11:20:52 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_AND_UTILS_H
# define ERRORS_AND_UTILS_H

# include "minishell.h"

// utils_and_errors.c
int				cmd_not_found(char *str);
char			*delete_quotes(char *str, char c);
int	            unset_error(t_simple_cmds *simple_cmd);
int				export_error(char *c);
int				ft_error(int error, t_tools *tools);

// executor_utils.c
char			*join_splitted_str(char **split_str);
char			**resplit_str(char **str);

// expander_utils.c
int				after_dol_lenght(char *str, int j);
size_t			quotes_lenght(char *str);
size_t			dollar_sign(char *str);
char			*char_to_str(char c);
int				question_mark(char **tmp);

// parse_env.c
char			*find_path(char **envp);
int				parse_envp(t_tools *tools);

#endif