/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyaseen <wyaseen@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:45:43 by wyaseen           #+#    #+#             */
/*   Updated: 2024/07/01 20:21:16 by wyaseen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>

int g_exit_code = 0; // Use g_exit_code as the global variable to manage state

void heredoc_prompt(void)
{
    write(STDERR_FILENO, "\n", 1); // Print a newline to move to the next line
    g_exit_code = 130; // Set the signal variable to indicate heredoc interruption
    rl_on_new_line();
    rl_replace_line("", 0); // Clear the current input line
    rl_redisplay(); // Redraw the prompt
}

void command_prompt(void)
{
    g_exit_code = -2;
}

void minishell_prompt(void)
{
    write(STDERR_FILENO, "\n", 1); // Print a newline to move to the next line
    g_exit_code = -1;
    rl_on_new_line();
    rl_replace_line("", 0); // Clear the current input line
    rl_redisplay(); // Redraw the prompt
}

void signal_handler_parent(int signum)
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
    if (signum == SIGQUIT && (g_exit_code == -1 || g_exit_code == 1))
    {
        g_exit_code = -1;
    }
    if (signum == SIGQUIT && g_exit_code == -2)
    {
        ft_putstr_fd("Quit:", STDERR_FILENO);
        ft_putstr_fd("\n", STDERR_FILENO);
        g_exit_code = -4;
    }
}

void init_signals(void)
{
    signal(SIGINT, signal_handler_parent);
    signal(SIGQUIT, signal_handler_parent);
}
