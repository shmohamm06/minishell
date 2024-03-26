/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_and_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:15:32 by shmohamm          #+#    #+#             */
/*   Updated: 2024/03/26 22:09:43 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_and_parent(int *fd, char **argv, char **envp)
{
	pid_t	pid;

	if (pipe(fd) == -1)
		ft_error();
	pid = fork();
	if (pid == -1)
		ft_error();
	if (pid == 0)
		child_process(fd, argv[1], ft_split(argv[2], ' '), envp);
	else
		parent_process(fd, argv[4], ft_split(argv[3], ' '), envp);
	// waitpid(pid, NULL, 0);
}

void	input_here_doc(char **argv, int *fd)
{
	char	*temp;

	close(fd[0]);
	while (1)
	{
		temp = get_next_line(0);
		// temp = read_line(">");
		if (ft_strncmp(temp, argv[2], ft_strlen(argv[2])) == 0)
		{
			free(temp);
			exit(0);
		}
		ft_putstr_fd(temp, fd[1]);
		free(temp);
	}
}

void	here_doc(char **argv)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		ft_error();
	pid = fork();
	if (pid == -1)
		ft_error();
	if (!pid)
		input_here_doc(argv, fd);
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

void	child_process(int *fd, char *in_file, char **cmd1, char **envpath)
{
	int	temp_file;

	temp_file = open(in_file, O_RDONLY, 0777);
	if (temp_file == -1)
		ft_error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(temp_file, STDIN_FILENO);
	close(fd[0]);
	execute(cmd1, envpath);
	ft_free(cmd1);
}

void	parent_process(int *fd, char *out_file, char **cmd2, char **envpath)
{
	int	temp_file;

	temp_file = open(out_file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (temp_file == -1)
		ft_error();
	dup2(fd[0], STDIN_FILENO);
	dup2(temp_file, STDOUT_FILENO);
	close(fd[1]);
	execute(cmd2, envpath);
	ft_free(cmd2);
}
