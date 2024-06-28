/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyaseen <wyaseen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:45:43 by wyaseen           #+#    #+#             */
/*   Updated: 2024/06/28 14:59:28 by wyaseen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>

void	sigint_handler(int sig)
{
	(void)sig; // To avoid unused parameter warning
	g_exit_code = SIGINT_CODE;
}

void	sigquit_handler(int sig)
{
	(void)sig; // To avoid unused parameter warning
	g_exit_code = SIGQUIT_CODE;
}

void	event(void)
{
	if (g_exit_code == SIGINT_CODE)
	{
		ft_putstr_fd("\n", STDERR_FILENO);
		ft_strdup("");
		rl_redisplay();
		rl_on_new_line();
		g_exit_code = 0;
	}
	else if (g_exit_code == SIGQUIT_CODE)
	{
		// Do nothing for SIGQUIT
		g_exit_code = 0;
	}
}

void	init_signals(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
}
