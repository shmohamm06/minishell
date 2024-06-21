/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:29:22 by shmohamm          #+#    #+#             */
/*   Updated: 2024/04/02 11:14:23 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors_and_utils.h"

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

	joined_str = join_split_str(str);
	new_str = ft_split(joined_str, ' ');
	free(joined_str);
	return (new_str);
}
