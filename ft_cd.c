/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:41:41 by shmohamm          #+#    #+#             */
/*   Updated: 2024/03/26 22:52:21 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_path_ret(char *str, t_data *mini)
{
	int	i;

	i = 0;
	while (mini->en_var[i])
	{
		if (!ft_strncmp(mini->en_var[i], str, ft_strlen(str)))
			return (ft_substr(mini->en_var[i], ft_strlen(str),
					ft_strlen(mini->en_var[i]) - ft_strlen(str)));
		i++;
	}
	return (NULL);
}

int	specific_path(t_data *mini, char *str)
{
	char	*tmp;
	int		ret;

	tmp = find_path_ret(str, mini);
	ret = chdir(tmp);
	free(tmp);
	if (ret != 0)
	{
		str = ft_substr(str, 0, ft_strlen(str) - 1);
		ft_putstr_fd(str, STDERR_FILENO);
		free(str);
		ft_putendl_fd(" not set", STDERR_FILENO);
	}
	return (ret);
}

void	add_path_to_env(t_data *mini)
{
	int		i;
	char	*tmp;

	i = 0;
	while (mini->en_var[i])
	{
		if (!ft_strncmp(mini->en_var[i], "PWD=", 4))
		{
			tmp = ft_strjoin("PWD=", mini->pwd);
			free(mini->en_var[i]);
			mini->en_var[i] = tmp;
		}
		else if (!ft_strncmp(mini->en_var[i], "OLDPWD=", 7) && mini->old_pwd)
		{
			tmp = ft_strjoin("OLDPWD=", mini->old_pwd);
			free(mini->en_var[i]);
			mini->en_var[i] = tmp;
		}
		i++;
	}
}

int	ft_cd(t_data *mini)
{
	int	ret;

	if (!mini->en_var[1])
		ret = specific_path(mini, "HOME=");
	else if (ft_strncmp(mini->en_var[1], "-", 1) == 0)
		ret = specific_path(mini, "OLDPWD=");
	else
	{
		ret = chdir(mini->en_var[1]);
		if (ret != 0)
		{
			ft_putstr_fd("minishell: ", STDERR_FILENO);
			ft_putstr_fd(mini->en_var[1], STDERR_FILENO);
			perror(" ");
		}
	}
	if (ret != 0)
		return (EXIT_FAILURE);
	change_path(mini);
	add_path_to_env(mini);
	return (EXIT_SUCCESS);
}
