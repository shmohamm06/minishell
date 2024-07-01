/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:44:11 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/01 13:52:00 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "built_ins.h"
#include "../execution/execution.h"

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
	else if (!ft_strncmp(cmd->arg[0], "exit", 5) || cmd->arg[0][0] == 'q')
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

static void	handle_error(const char *message, int error_code)
{
	fd_printf(2, "%s\n", message);
	g_exit_code = error_code;
}

static void	print_env_variable(t_env *env)
{
	if (env->initialised)
	{
		if (env->value == NULL)
			fd_printf(1, "%s=\n", env->key);
		else
			fd_printf(1, "%s=%s\n", env->key, env->value);
	}
}

void	print_env(t_mini *mini)
{
	t_env	*env;

	env = mini->l_env;
	if (!env)
	{
		handle_error("env: permission denied", ENV_FAIL_CODE);
		return ;
	}
	while (env)
	{
		print_env_variable(env);
		env = env->next;
	}
	g_exit_code = SUCCESS;
}

void	print_pwd(void)
{
	char	cwd[PATH_MAX];

	ft_bzero(cwd, sizeof(cwd));
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		fd_printf(1, "%s\n", cwd);
		g_exit_code = 0;
	}
	else
	{
		handle_error("minishell: pwd: Unable to get current working directory",
			PWD_FAIL_CODE);
	}
}
