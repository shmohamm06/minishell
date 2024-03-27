/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:47:03 by shmohamm          #+#    #+#             */
/*   Updated: 2024/03/27 11:02:49 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute(char **cmd, char **envp)
{
	char	*path;

	path = find_path(cmd[0], envp);
	if (!path)
		ft_error();
	if (execve(path, cmd, envp) == -1)
		ft_error();
}

char	*join_paths(char *dir, char *arg)
{
	char	*complete_path;
	char	*result;

	complete_path = ft_strjoin(dir, "/");
	result = ft_strjoin(complete_path, arg);
	free(complete_path);
	return (result);
}

char	*find_path(char *arg, char **envp)
{
	char	*result;
	char	**paths;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		result = join_paths(paths[i], arg);
		if (access(result, F_OK) == 0)
		{
			free(paths);
			return (result);
		}
		free(result);
		i++;
	}
	ft_free(paths);
	return (NULL);
}

void	ft_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	ft_free(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}
