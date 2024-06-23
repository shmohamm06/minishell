/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:29:22 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/23 11:16:18 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	find_matching_quote(char *line, int i, int *num_del, int del)
{
	int	j;

	j = i + 1;
	*num_del += 1;
	while (line[j] && line[j] != del)
		j++;
	if (line[j] == del)
		*num_del += 1;
	return (j - i);
}

int	count_quotes(char *line)
{
	int	i;
	int	s;
	int	d;

	s = 0;
	d = 0;
	i = -1;
	while (line[++i])
	{
		if (line[i] == 34)
			i += find_matching_quote(line, i, &d, 34);
		if (line[i] == 39)
			i += find_matching_quote(line, i, &s, 39);
	}
	if ((d > 0 && d % 2 != 0) || (s > 0 && s % 2 != 0))
		return (0);
	return (1);
}

char	*join_splitted_str(char **split_str)
{
	char	*temp;
	char	*add_space;
	int		i;

	temp = ft_strdup(split_str[0]);
	i = 1;
	while (split_str[i])
	{
		add_space = ft_strjoin(temp, " ");
		free(temp);
		temp = ft_strjoin(add_space, split_str[i]);
		free(add_space);
		i++;
	}
	return (temp);
}

char	**resplit_str(char **str)
{
	char	**new_str;
	char	*joined_str;

	joined_str = join_splitted_str(str);
	new_str = ft_split(joined_str, ' ');
	free(joined_str);
	return (new_str);
}
