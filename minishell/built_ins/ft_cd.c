/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:41:41 by shmohamm          #+#    #+#             */
/*   Updated: 2024/03/31 11:30:24 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins.h"

char	*find_path_ret(char *str, t_tools *mini)
{
	int	i;

	i = 0;
	while (mini->envp[i])
	{
		if (!ft_strncmp(mini->envp[i], str, ft_strlen(str)))
			return (ft_substr(mini->envp[i], ft_strlen(str),
					ft_strlen(mini->envp[i]) - ft_strlen(str)));
		i++;
	}
	return (NULL);
}

int	specific_path(char *str, t_tools *mini)
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

void	add_path_to_env(t_tools *mini)
{
	int		i;
	char	*tmp;

	i = 0;
	while (mini->envp[i])
	{
		if (!ft_strncmp(mini->envp[i], "PWD=", 4))
		{
			tmp = ft_strjoin("PWD=", mini->pwd);
			free(mini->envp[i]);
			mini->envp[i] = tmp;
		}
		else if (!ft_strncmp(mini->envp[i], "OLDPWD=", 7) && mini->old_pwd)
		{
			tmp = ft_strjoin("OLDPWD=", mini->old_pwd);
			free(mini->envp[i]);
			mini->envp[i] = tmp;
		}
		i++;
	}
}

int	ft_cd(t_tools *mini, t_simple_cmds *cmd)
{
	int	ret;

	if (!cmd->str[1])
		ret = specific_path(mini, "HOME=");
	else if (ft_strncmp(cmd->str[1], "-", 1) == 0)
		ret = specific_path(mini, "OLDPWD=");
	else
	{
		ret = chdir(cmd->str[1]);
		if (ret != 0)
		{
			ft_putstr_fd("minishell: ", STDERR_FILENO);
			ft_putstr_fd(cmd->str[1], STDERR_FILENO);
			perror(" ");
		}
	}
	if (ret != 0)
		return (EXIT_FAILURE);
	change_path(mini);
	add_path_to_env(mini);
	return (EXIT_SUCCESS);
}
