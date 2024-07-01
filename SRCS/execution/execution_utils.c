/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:45:01 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/01 14:50:34 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../built_ins/built_ins.h"
#include "execution.h"


int	check_executable_slash(t_mini *mini, t_cmd *cmd)
{
	if (access(cmd->arg[0], X_OK) == 0 && ft_strlen(cmd->arg[0]) > 2
		&& ft_strchr(cmd->arg[0], '.') && ft_strchr(cmd->arg[0], '/'))
		return (0);
	else if (access(cmd->arg[0], X_OK) == 0 && ft_strlen(cmd->arg[0]) > 2
		&& !ft_strchr(cmd->arg[0], '.') && !ft_strchr(cmd->arg[0], '/'))
	{
		execute_path_command(mini, cmd);
		return (1);
	}
	return (0);
}

void	execute_in_directory(t_mini *mini, t_cmd *cmd)
{
	char	**env_array;

	if (handle_dot_command_check(cmd) || check_executable_slash(mini, cmd))
		return ;
	env_array = convert_env_to_array(mini);
	if (execve(cmd->arg[0], cmd->arg, env_array) == -1)
	{
		ft_free_split(env_array);
		exit_shell(mini, errno, strerror(errno), 2);
	}
}

static void	report_command_failure(t_cmd *cmd, int code)
{
	g_exit_code = code;
	fd_printf(2, "minishell: %s: command not found\n", cmd->arg[0]);
}

void	execute_command_with_forking(t_mini *mini, t_cmd *cmd, char *cmd_path)
{
	char	**env_array;

	env_array = convert_env_to_array(mini);
	if (execve(cmd_path, cmd->arg, env_array) == -1)
	{
		ft_free_split(env_array);
		exit_shell(mini, errno, strerror(errno), 2);
	}
	free(cmd_path);
}

void	execute_path_command(t_mini *mini, t_cmd *cmd)
{
	char	*cmd_path;

	if ((ft_strchr(cmd->arg[0], '.') && ft_strchr(cmd->arg[0], '/'))
		|| (ft_strchr(cmd->arg[0], '/')))
	{
		if (access(cmd->arg[0], F_OK) != 0)
		{
			fd_printf(2, "minishell: %s: No such file or directory\n",
				cmd->arg[0]);
			g_exit_code = COMMAND_FAIL;
			return ;
		}
	}
	if (get_env_value_or_key("PATH", mini, KEY) == NULL)
		return (report_command_failure(cmd, COMMAND_FAIL));
	cmd_path = get_path(cmd->arg[0], get_env_value_or_key("PATH", mini, VALUE));
	if (cmd_path)
		execute_command_with_forking(mini, cmd, cmd_path);
	else
		report_command_failure(cmd, COMMAND_FAIL);
}
