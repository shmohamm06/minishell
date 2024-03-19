/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:07:39 by shmohamm          #+#    #+#             */
/*   Updated: 2024/03/19 14:00:28 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_process(int *fd, char *in_file, char **cmd, char **envpath)
{
	int	temp_file;

	temp_file = open(in_file, O_RDONLY, 0777);
	if (temp_file == -1)
		ft_error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(temp_file, STDIN_FILENO);
	close(fd[0]);
	execute(cmd, envpath);
	ft_free(cmd);
}

void	parent_process(int *fd, char *out_file, char **cmd, char **envpath)
{
	int	temp_file;

	temp_file = open(out_file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (temp_file == -1)
		ft_error();
	dup2(fd[0], STDIN_FILENO);
	dup2(temp_file, STDOUT_FILENO);
	close(fd[1]);
	execute(cmd, envpath);
	ft_free(cmd);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error();
		pid = fork();
		if (pid == -1)
			ft_error();
		if (pid == 0)
			child_process(fd, argv[1], ft_split(argv[2], ' '), envp);
		else
			waitpid(pid, NULL, 0);
		parent_process(fd, argv[4], ft_split(argv[3], ' '), envp);
	}
	else
	{
		ft_putstr_fd("Error: Incoorect arguments\n", 2);
		ft_putstr_fd("Usage: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	return (0);
}
