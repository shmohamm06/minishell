/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 07:53:21 by hakaddou          #+#    #+#             */
/*   Updated: 2023/02/01 02:11:35 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_parent_compatible(t_cmd *cmd)
{
	if (cmd && !cmd->next && is_parent_exec(cmd))
		return (1);
	return (0);
}

int	is_parent_exec(t_cmd *cmd)
{
	if (!cmd->arg[0])
		return (1);
	if (!ft_strncmp(cmd->arg[0], "cd", 3)
		|| !ft_strncmp(cmd->arg[0], "exit", 5)
		|| cmd->arg[0][0] == 'q'
		|| !ft_strncmp(cmd->arg[0], "export", 7)
		|| !ft_strncmp(cmd->arg[0], "unset", 6))
		return (1);
	return (0);
}

void	execute_in_parent(t_mini *mini)
{
	t_cmd	*cmd;

	cmd = mini->l_cmd;
	if (ft_redirect(mini, cmd) != 0)
		return ;
	if (cmd->arg[0] && builtin_check(mini, cmd) == 0)
	{
		close_rdr_back(cmd);
		set_env_underscore(mini->l_cmd->arg[0], mini);
		return ;
	}
	close_rdr_back(cmd);
}

void	wait_for_children(t_mini *mini)
{
	int		status;
	t_cmd	*cmd;

	status = 0;
	cmd = mini->l_cmd;
	while (cmd)
	{
		if (cmd->fork_id != 0)
		{
			waitpid(cmd->fork_id, &status, 0);
			if (WIFEXITED(status))
			{
				g_exit_code = WEXITSTATUS(status);
				fd_printf(2, "Child exited with status %d\n", g_exit_code);
			}
		}
		cmd = cmd->next;
	}
	if (mini->l_cmd && mini->l_cmd->fork_id != 0 && mini->l_cmd->arg
		&& mini->l_cmd->arg[0] && !mini->l_cmd->next)
		set_env_underscore(mini->l_cmd->arg[0], mini);
}
