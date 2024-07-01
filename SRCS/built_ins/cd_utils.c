/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:44:18 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/01 13:53:23 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../execution/execution.h"
#include "built_ins.h"

char	*get_env_value_or_key(char *arg, t_mini *mini, int flag)
{
	t_env	*temp;

	if (!mini->l_env || !arg)
		return (NULL);
	temp = mini->l_env;
	while (temp != NULL && ft_strncmp(arg, temp->key, ft_strlen(arg) + 1))
		temp = temp->next;
	if (!temp)
		return (NULL);
	if (flag == VALUE)
		return (temp->value);
	else if (flag == KEY)
		return (temp->key);
	return (NULL);
}

void	update_pwd_env(t_mini *mini)
{
	char	cwd[PATH_MAX];
	char	*pwd;

	pwd = ft_strjoin("PWD=", getcwd(cwd, sizeof(cwd)));
	if (!pwd)
	{
		fd_printf(2, "minishell: error in update_pwd_env\n");
		return ;
	}
	parse_new_export(pwd, mini);
	free(pwd);
}

void	update_oldpwd_env(t_mini *mini, char *old_pwd)
{
	char	*old;

	old = ft_strjoin("OLDPWD=", old_pwd);
	if (!old)
	{
		fd_printf(2, "minishell: error in update_oldpwd_env\n");
		return ;
	}
	parse_new_export(old, mini);
	free(old);
}

void	handle_cd_success(t_mini *mini, char *old_pwd)
{
	g_exit_code = SUCCESS;
	update_pwd_env(mini);
	update_oldpwd_env(mini, old_pwd);
}
