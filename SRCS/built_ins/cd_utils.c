/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:44:18 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/25 10:51:15 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "built_ins.h"

char	*find_str_env(char *arg, t_mini *mini, int flag)
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

void	set_env_pwd(t_mini *mini)
{
	char	cwd[2056];
	char	*pwd;

	pwd = ft_strjoin("PWD=", getcwd(cwd, sizeof(cwd)));
	if (!pwd)
	{
		fd_printf(2, "minishell: error in set_env_pwd\n");
		return ;
	}
	parse_new_export(pwd, mini);
	free(pwd);
}

void	set_old_pwd(t_mini *mini, char *old_pwd)
{
	char	*old;

	old = ft_strjoin("OLDPWD=", old_pwd);
	if (!old)
	{
		fd_printf(2, "minishell: error in set_old_pwd\n");
		return ;
	}
	parse_new_export(old, mini);
	free(old);
}

void	cd_return_success(t_mini *mini, char *old_pwd)
{
	g_exit_code = SUCCESS;
	set_env_pwd(mini);
	set_old_pwd(mini, old_pwd);
}
