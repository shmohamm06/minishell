/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:56:42 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/23 11:17:28 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	implement_tools(t_tools *tools)
{
	tools->simple_cmds = NULL;
	tools->lexer_list = NULL;
	tools->reset = false;
	tools->pid = NULL;
	tools->heredoc = false;
	g_global.stop_heredoc = 0;
	g_global.in_cmd = 0;
	g_global.in_heredoc = 0;
	parse_envp(tools);
	return (1);
}
// init_signals();

int	reset_tools(t_tools *tools)
{
	ft_simple_cmdsclear(&tools->simple_cmds);
	free(tools->args);
	tools->args = NULL;
	if (tools->pid)
	{
		free(tools->pid);
		tools->pid = NULL;
	}
	free_arr(tools->paths);
	if (tools->lexer_list)
	{
		ft_lexerclear(&tools->lexer_list);
		tools->lexer_list = NULL;
	}
	implement_tools(tools);
	tools->reset = true;
	minishell_loop(tools);
	return (1);
}

// signal(SIGQUIT, sigquit_handler);
int	prepare_executor(t_tools *tools)
{
	g_global.in_cmd = 1;
	if (tools->pipes == 0)
		single_cmd(tools->simple_cmds, tools);
	else
	{
		tools->pid = ft_calloc(sizeof(int), tools->pipes + 2);
		if (!tools->pid)
			return (ft_error(1, tools));
		executor(tools);
	}
	g_global.in_cmd = 0;
	return (EXIT_SUCCESS);
}

int	minishell_loop(t_tools *tools)
{
	char	*tmp;

	tools->args = readline(READLINE_MSG);
	tmp = ft_strtrim(tools->args, " ");
	free(tools->args);
	tools->args = tmp;
	if (!tools->args)
	{
		ft_putendl_fd("exit", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	if (tools->args[0] == '\0')
		return (reset_tools(tools));
	add_history(tools->args);
	if (!count_quotes(tools->args))
		return (ft_error(2, tools));
	if (!token_reader(tools))
		return (ft_error(1, tools));
	parser(tools);
	prepare_executor(tools);
	reset_tools(tools);
	return (1);
}
