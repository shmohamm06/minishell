/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:14:23 by shmohamm          #+#    #+#             */
/*   Updated: 2024/03/27 11:12:54 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_arrdup(char **arr)
{
	char	**rtn;
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	rtn = ft_calloc(sizeof(char *), i + 1);
	if (!rtn)
		return (NULL);
	i = 0;
	while (arr[i] != NULL)
	{
		rtn[i] = ft_strdup(arr[i]);
		if (rtn[i] == NULL)
		{
			ft_free(rtn);
			return (rtn);
		}
		i++;
	}
	return (rtn);
}

int	find_pwd(t_data *mini)
{
	int	i;

	i = 0;
	while (mini->en_var[i])
	{
		if (!ft_strncmp(mini->en_var[i], "PWD=", 4))
			mini->pwd = ft_substr(mini->en_var[i], 4, ft_strlen(mini->en_var[i])
					- 4);
		if (!ft_strncmp(mini->en_var[i], "OLDPWD=", 7))
			mini->old_pwd = ft_substr(mini->en_var[i], 7,
					ft_strlen(mini->en_var[i]) - 7);
		i++;
	}
	return (1);
}

void	change_path(t_data *mini)
{
	char	*tmp;

	find_pwd(mini);
	tmp = ft_strdup(mini->pwd);
	free(mini->old_pwd);
	mini->old_pwd = tmp;
	free(mini->pwd);
	mini->pwd = getcwd(NULL, sizeof(NULL));
}
