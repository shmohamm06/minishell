/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:07:39 by shmohamm          #+#    #+#             */
/*   Updated: 2024/03/21 12:25:23 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];

	if (argc == 5 || argc == 6)
	{
		if (argc == 6)
		{
			if (ft_strncmp(argv[1], "here_doc", 9) == 0)
			{
				fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND,
						0777);
				here_doc(argv);
			}
		}
		else
			child_and_parent(fd, argv, envp);
	}
	else
	{
		ft_putstr_fd("Error: Incoorect arguments\n", 2);
		ft_putstr_fd("Usage: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	return (0);
}
