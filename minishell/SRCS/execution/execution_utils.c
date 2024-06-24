/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:39:56 by hakaddou          #+#    #+#             */
/*   Updated: 2023/02/01 01:40:57 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_slash_exec(t_mini *mini, t_cmd *cmd)
{
	if (access (cmd->arg[0], X_OK) == 0
		&& ft_strlen(cmd->arg[0]) > 2
		&& ft_strchr(cmd->arg[0], '.')
		&& ft_strchr(cmd->arg[0], '/'))
		return (0);
	else if (access (cmd->arg[0], X_OK) == 0
		&& ft_strlen(cmd->arg[0]) > 2
		&& !ft_strchr(cmd->arg[0], '.')
		&& !ft_strchr(cmd->arg[0], '/'))
	{
		execute_pathed_cmd(mini, cmd);
		return (1);
	}
	return (0);
}

void	execute_in_dir(t_mini *mini, t_cmd *cmd)
{
	char	**envc;

	if (dot_dir_check(cmd) || is_slash_exec(mini, cmd))
		return ;
	envc = convert_env(mini);
	if (execve(cmd->arg[0], cmd->arg, envc) == -1)
	{
		ft_free_split(envc);
		ft_exit_shell(mini, errno, strerror(errno), 2);
	}
}

void	command_failed_message(t_cmd *cmd, int code)
{
	g_exit_code = code;
	fd_printf(2, "minishell: %s: command not found\n", cmd->arg[0]);
}

void	execute_command_fork(t_mini *mini, t_cmd *cmd, char *cmd_path)
{
	char	**envc;

	envc = convert_env(mini);
	if (execve(cmd_path, cmd->arg, envc) == -1)
	{
		ft_free_split(envc);
		ft_exit_shell(mini, errno, strerror(errno), 2);
	}
	free (cmd_path);
}

void	execute_pathed_cmd(t_mini *mini, t_cmd *cmd)
{
	char	*cmd_path;

	if ((ft_strchr(cmd->arg[0], '.') && ft_strchr(cmd->arg[0], '/'))
		|| (ft_strchr(cmd->arg[0], '/')))
	{
		if (!file_exists(cmd->arg[0]))
		{
			fd_printf(2, "minishell: %s: No such file or directory\n",
				cmd->arg[0]);
			g_exit_code = COMMAND_FAIL;
			return ;
		}
	}
	if (find_str_env("PATH", mini, KEY) == NULL)
		return (command_failed_message(cmd, COMMAND_FAIL));
	cmd_path = get_path(cmd->arg[0], find_str_env("PATH", mini, VALUE));
	if (cmd_path)
		execute_command_fork(mini, cmd, cmd_path);
	else
		command_failed_message(cmd, COMMAND_FAIL);
}
