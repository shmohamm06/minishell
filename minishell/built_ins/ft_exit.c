/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:43:18 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/23 11:01:26 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_struct(t_tools *mini)
{
	free_arr(mini->paths);
	free_arr(mini->envp);
	free(mini->args);
	ft_simple_cmdsclear(&mini->simple_cmds);
	free(mini->pwd);
	free(mini->old_pwd);
	if (mini->pipes)
		free(mini->pid);
}

void	determine_exit_code(char **str)
{
	int	exit_code;

	if (!str[1])
		exit_code = 0;
	else if (is_str_digit(str[1]))
		exit_code = ft_atoi(str[1]);
	else
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(str[1], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		exit_code = 255;
	}
	free_arr(str);
	exit(exit_code);
}

int	ft_exit(t_tools *mini, t_simple_cmds *cmd)
{
	char	**str;

	ft_putendl_fd("exit", STDERR_FILENO);
	if (cmd->str[1] && cmd->str[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	str = ft_arrdup(cmd->str);
	free_struct(mini);
	determine_exit_code(str);
	return (EXIT_SUCCESS);
}
