/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:45:13 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/01 14:07:20 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../built_ins/built_ins.h"
#include "execution.h"

void	exec_children_cmds(t_mini *mini, t_cmd *cmd)
{
	if (ft_redirect(mini, cmd) != 0)
		ft_exit_shell(mini, g_exit_code, NULL, 1);
	if (cmd->arg[0] && builtin_check(mini, cmd) == 0)
	{
		close_rdr_back(cmd);
		ft_exit_shell(mini, g_exit_code, NULL, 1);
	}
	else if (cmd->arg[0] && access(cmd->arg[0], X_OK) == 0)
		execute_in_directory(mini, cmd);
	else if (cmd->arg[0])
		execute_path_command(mini, cmd);
	close_rdr_back(cmd);
	ft_exit_shell(mini, g_exit_code, NULL, 2);
}

void	execute_in_child(t_mini *mini)
{
	t_cmd	*cmd;

	cmd = mini->l_cmd;
	while (cmd)
	{
		cmd->fork_id = fork();
		if (cmd->fork_id == 0)
			exec_children_cmds(mini, cmd);
		else
			cmd = cmd->next;
	}
	wait_for_children(mini);
}

void	parse_input(t_mini *mini)
{
	t_cmd	*cmd;

	cmd = mini->l_cmd;
	handle_heredoc(mini);
	if (is_parent_compatible(cmd))
		execute_in_parent(mini);
	else
		execute_in_child(mini);
}
