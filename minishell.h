/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:49:12 by shmohamm          #+#    #+#             */
/*   Updated: 2024/03/19 13:20:11 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>

//pipex & pipex_utils
void	ft_error(void);
void	ft_free(char **argv);
char	*join_paths(char *dir, char *arg);
char	*find_path(char *arg, char **envp);
void	execute(char **arg, char **envp);
void	cleanup(char **args, char *path, char **paths);
void	child_process(int *fd, char *in_file, char **cmd, char **envpath);
void	parent_process(int *fd, char *out_file, char **cmd, char **envpath);

#endif