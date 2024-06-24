/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 00:37:39 by hakaddou          #+#    #+#             */
/*   Updated: 2023/01/31 22:56:36 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	arg_count(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
		i++;
	return (i);
}

int	check_exit_alpha(char **args)
{
	int	i;
	int	d;

	i = -1;
	while (args[++i] != NULL)
	{
		d = -1;
		while (args[i][++d] != '\0')
		{
			if (true == ft_isalpha(args[i][d]))
			{
				fd_printf(2, ALPHA_EXIT, args[i]);
				return (1);
			}
		}
	}
	return (0);
}

// safe exit exits with the code passed to it
// if the code is greater than 255 it truncates it
// VERY IMPORTANT needs to be modidfed and change the freeing
// after merging with parsing as  ft_exit current frees
// the readline which should not be the case
// as parsing parses the readline

void	ft_exit(char **args, t_mini *mini)
{
	int	code;

	if (!args[1] && !mini->l_cmd->next)
		ft_exit_shell(mini, SUCCESS, "exit", 2);
	else if (!args[1])
		ft_exit_shell(mini, SUCCESS, NULL, 2);
	else if (2 < arg_count(args))
	{
		fd_printf(2, "minishell: exit: too many arguments\n");
		g_exit_code = EXIT_FAIL;
		return ;
	}
	if (check_exit_alpha(&args[1]))
		code = EXIT_ALPHA_CODE;
	else
		code = ft_atoi(args[1]) % 256;
	if (mini->l_cmd->next)
		ft_exit_shell(mini, code, NULL, 2);
	else
		ft_exit_shell(mini, code, "exit", 2);
}
