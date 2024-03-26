/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:07:39 by shmohamm          #+#    #+#             */
/*   Updated: 2024/03/26 23:14:10 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		fd[2];
	t_data	*mini;

	i = 0;
	while (i < 7)
	{
		if (argv[1])
		{
			if (!ft_strncmp(builtins[i][0], argv[1], ft_strlen(builtins[i][0])))
			{
				(builtin_func)(t_data, struct s_simple_cmds) = builtins[i][1];
				return (builtin_func(mini, simple_cmds));
			}
		}
		i++;
	}
	if (argc == 5 || argc == 6)
	{
		mini->en_var = ft_arrdup(envp);
		if (argc == 6)
		{
			if (ft_strncmp(argv[1], "<<", 9) == 0 && ft_strncmp(argv[argc - 1],
					">>", 9))
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
