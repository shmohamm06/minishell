/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_srcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:11:24 by hakaddou          #+#    #+#             */
/*   Updated: 2023/01/20 19:12:15 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// pipex functions
char	*split_and_join(char *av_cmd, char *splitted)
{
	char	*str;
	char	*path;

	str = ft_strjoin("/", av_cmd);
	path = ft_strjoin(splitted, str);
	free(str);
	return (path);
}

int	word_count(char const *s, char c)
{
	int	i;
	int	cnt;
	int	done;

	i = 0;
	cnt = 0;
	done = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c && !done)
			done = 1;
		else if (s[i] != c && done)
		{
			++cnt;
			done = 0;
		}
		++i;
	}
	return (cnt);
}

char	*get_path(char *cmd, char *env)
{
	int		i;
	char	*str;
	char	**splitted;

	splitted = ft_split(env, ':');
	i = -1;
	while (++i < word_count(env, ':'))
	{
		str = split_and_join(cmd, splitted[i]);
		if (access(str, X_OK) == 0)
			break ;
		free(splitted[i]);
		splitted[i] = NULL;
		free(str);
		str = NULL;
	}
	while (splitted[i] != NULL)
	{
		free(splitted[i]);
		splitted[i++] = NULL;
	}
	free(splitted);
		splitted = NULL;
	return (str);
}
