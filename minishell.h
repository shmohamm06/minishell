/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:49:12 by shmohamm          #+#    #+#             */
/*   Updated: 2024/03/27 12:12:56 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_data
{
	char	**en_var;
	char	*args;
	char	*pwd;
	char	*old_pwd;
}			t_data;

// utils
void		ft_error(void);
void		ft_free(char **argv);
char		*join_paths(char *dir, char *arg);
char		*find_path(char *arg, char **envp);
void		execute(char **arg, char **envp);

// utils2
char		**ft_arrdup(char **arr);
int			find_pwd(t_data *mini);
void		change_path(t_data *mini);

// here_doc & process
void		here_doc(char **argv);
void		input_here_doc(char **argv, int *fd);
void		child_and_parent(int *fd, char **argv, char **envp);
void		child_process(int *fd, char *in_file, char **cmd1, char **envpath);
void		parent_process(int *fd, char *out_file, char **cmd2,
				char **envpath);

// built-ins
int			builtin_check(char **argv, t_data *mini);
// ft_echo
int			ft_echo(char **argv);
void		print_lines(int i, char **str, int out);

// ft_env
int			ft_env(t_data *mini);

// ft_pwd
int			ft_pwd(t_data *mini);

// ft_cd
int			ft_cd(t_data *mini);
int			specific_path(t_data *mini, char *str);
void		add_path_to_env(t_data *mini);
char		*find_path_ret(char *str, t_data *mini);

#endif