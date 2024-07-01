/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:46:16 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/01 15:36:04 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../execution/execution.h"
#include "built_ins.h"

int	count_arguments(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
		i++;
	return (i);
}

int	contains_alpha(char **args)
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

void	ft_exit(char **args, t_mini *mini)
{
	int	code;

	if (!args[1] && !mini->l_cmd->next)
		exit_shell(mini, SUCCESS, "exit", 2);
	else if (!args[1])
		exit_shell(mini, SUCCESS, NULL, 2);
	else if (2 < count_arguments(args))
	{
		fd_printf(2, "minishell: exit: too many arguments\n");
		g_exit_code = EXIT_FAIL;
		return ;
	}
	if (contains_alpha(&args[1]))
		code = EXIT_ALPHA_CODE;
	else
		code = ft_atoi(args[1]) % 256;
	if (mini->l_cmd->next)
		exit_shell(mini, code, NULL, 2);
	else
		exit_shell(mini, code, "exit", 2);
}
