/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:46:07 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/01 13:55:20 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../execution/execution.h"
#include "built_ins.h"

void	change_to_home_directory(t_mini *mini, char *old_pwd)
{
	char	*path;
	int		i;

	i = 42;
	path = get_env_value_or_key("HOME", mini, VALUE);
	if (!path)
	{
		fd_printf(2, "minishell: cd: HOME not set\n");
		g_exit_code = CD_FAIL;
		return ;
	}
	i = chdir(path);
	if (i)
	{
		fd_printf(2, "minishell: cd: %s: %s\n", strerror(errno));
		g_exit_code = CD_FAIL;
		return ;
	}
	handle_cd_success(mini, old_pwd);
}

void	change_to_old_directory(t_mini *mini, char *old_pwd)
{
	int	i;

	i = 42;
	if (get_env_value_or_key("OLDPWD", mini, KEY) == NULL)
	{
		fd_printf(2, "OLDPWD not set\n");
		g_exit_code = CD_FAIL;
		return ;
	}
	i = chdir(get_env_value_or_key("OLDPWD", mini, VALUE));
	if (i)
	{
		fd_printf(2, "minishell: cd: %s: %s\n", get_env_value_or_key("OLDPWD",
					mini, VALUE), strerror(errno));
		g_exit_code = CD_FAIL;
		return ;
	}
	fd_printf(1, "%s\n", get_env_value_or_key("OLDPWD", mini, VALUE));
	handle_cd_success(mini, old_pwd);
}

// ft_cd takes you to the path of the directory passed to cd command
// cd .. and cd . are handeled by chdir
// cd with no args is not handeled by chdir so change_to_home_directory function
// handles it by looking for HOME in the env
// cd - takes you to old directory by using a function
// from ft_export called parse_new_export
void	ft_cd(char **args, t_mini *mini)
{
	int		i;
	char	*old_pwd;
	char	cwd[2056];

	i = 42;
	old_pwd = getcwd(cwd, sizeof(cwd));
	if (!args[0])
	{
		change_to_home_directory(mini, old_pwd);
		return ;
	}
	if (ft_strncmp(args[0], "-", 2) == 0)
	{
		change_to_old_directory(mini, old_pwd);
		return ;
	}
	i = chdir(args[0]);
	if (i)
	{
		fd_printf(2, "minishell: cd: %s: %s\n", args[0], strerror(errno));
		g_exit_code = CD_FAIL;
		return ;
	}
	handle_cd_success(mini, old_pwd);
}
