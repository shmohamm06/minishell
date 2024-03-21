/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:49:12 by shmohamm          #+#    #+#             */
/*   Updated: 2024/03/21 12:24:55 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>

// pipex & pipex_utils
void	ft_error(void);
void	ft_free(char **argv);
char	*join_paths(char *dir, char *arg);
char	*find_path(char *arg, char **envp);
void	execute(char **arg, char **envp);
void	here_doc(char **argv);
void	input_here_doc(char **argv, int *fd);
void	child_and_parent(int *fd, char **argv, char **envp);
void	child_process(int *fd, char *in_file, char **cmd1, char **envpath);
void	parent_process(int *fd, char *out_file, char **cmd2, char **envpath);

#endif