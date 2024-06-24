/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 23:10:26 by hakaddou          #+#    #+#             */
/*   Updated: 2023/01/30 01:45:49 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	builtin_check(t_mini *mini, t_cmd *cmd)
{
	if (!cmd->arg[0][0])
	{
		fd_printf(2, "minishell: : command not found\n");
		g_exit_code = COMMAND_FAIL;
		return (0);
	}
	else if (!ft_strncmp(cmd->arg[0], "pwd", 4))
		print_pwd();
	else if (!ft_strncmp(cmd->arg[0], "cd", 3))
		ft_cd(&cmd->arg[1], mini);
	else if (!ft_strncmp(cmd->arg[0], "exit", 5)
		|| cmd->arg[0][0] == 'q')
		ft_exit(cmd->arg, mini);
	else if (!ft_strncmp(cmd->arg[0], "env", 4))
		print_env(mini);
	else if (!ft_strncmp(cmd->arg[0], "echo", 5))
		ft_echo(&cmd->arg[1]);
	else if (!ft_strncmp(cmd->arg[0], "export", 7))
		ft_export(&cmd->arg[1], mini);
	else if (!ft_strncmp(cmd->arg[0], "unset", 6))
		ft_unset(&cmd->arg[1], mini);
	else
		return (1);
	return (0);
}

void	print_env(t_mini *mini)
{
	t_env	*env;

	env = mini->l_env;
	if (!env)
	{
		fd_printf(2, "env: permission denied\n");
		g_exit_code = ENV_FAIL_CODE;
		return ;
	}
	while (env)
	{
		if (env->initialised == true)
		{
			if (env->value == NULL)
				fd_printf (1, "%s=\n", env->key);
			else
				fd_printf(1, "%s=%s\n", env->key, env->value);
		}
		env = env->next;
	}
	g_exit_code = SUCCESS;
}

// prints the present working directory
// print_pwd does not take any arguments and in case
// of failure it sets the exit code to PWD_FAIL_CODE
void	print_pwd(void)
{
	char	cwd[2056];

	ft_bzero(cwd, sizeof(cwd));
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		fd_printf(1, "%s\n", cwd);
		g_exit_code = 0;
	}
	else
	{
		fd_printf (2, "minishell: pwd: %s\n", strerror(errno));
		g_exit_code = PWD_FAIL_CODE;
	}
}
