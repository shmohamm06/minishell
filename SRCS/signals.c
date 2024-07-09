/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:22:20 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/09 13:35:07 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>

int		g_exit_code = 0;

void	command_prompt(void)
{
	g_exit_code = -2;
}

void	heredoc_prompt(void)
{
	rl_on_new_line();
	ft_putstr_fd(" \b\b\n", 2);
	g_exit_code = 1;
	close(0);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_exit_code = 130;
}

void	minishell_prompt(void)
{
	write(STDERR_FILENO, "\n", 1);
	g_exit_code = -1;
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	signal_handler_parent(int signum)
{
	if (signum == SIGINT)
	{
		if (g_exit_code == -1 || g_exit_code == 1)
			minishell_prompt();
		else if (g_exit_code == 2)
			command_prompt();
		else
			heredoc_prompt();
	}
	else if (signum == SIGQUIT)
	{
		if (g_exit_code == -1 || g_exit_code == 1)
			g_exit_code = -1;
		else if (g_exit_code == -2)
		{
			ft_putstr_fd("Quit: ", STDERR_FILENO);
			ft_putstr_fd("\n", STDERR_FILENO);
			g_exit_code = -4;
		}
	}
}

void	init_signals(void)
{
	signal(SIGINT, signal_handler_parent);
	signal(SIGQUIT, SIG_IGN);
}
