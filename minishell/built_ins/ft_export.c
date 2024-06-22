/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 12:17:39 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/22 11:20:30 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/built_ins.h"

int	check_if_var_exists(t_tools *tools, char *str)
{
	int	i;

	i = 0;
	if (str[check_equal_sign(str)] == '\"')
		delete_quotes(str, '\"');
	if (str[check_equal_sign(str)] == '\'')
		delete_quotes(str, '\'');
	while (tools->envp[i])
	{
		if (ft_strncmp(tools->envp[i], str,
				check_equal_sign(tools->envp[i])) == 0)
		{
			free(tools->envp[i]);
			tools->envp[i] = ft_strdup(str);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_parameter(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[0]))
		return (export_error(str));
	if (check_equal_sign(str) == 0)
		return (EXIT_FAILURE);
	if (str[0] == '=')
		return (export_error(str));
	while (str[i] != '=')
	{
		if (check_valid_identifier(str[i]))
			return (export_error(str));
		i++;
	}
	return (EXIT_SUCCESS);
}

char	**whileloop_add_var(char **arr, char **result, char *str)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		if (arr[i + 1] == NULL)
		{
			result[i] = ft_strdup(str);
			result[i + 1] = ft_strdup(arr[i]);
		}
		else
			result[i] = ft_strdup(arr[i]);
		if (result[i] == NULL)
		{
			free_arr(result);
			return (result);
		}
		i++;
	}
	return (result);
}

char	**add_variable(char **arr, char *str)
{
	char	**rtn;
	size_t	i;

	i = 0;
	if (str[check_equal_sign(str)] == '\"')
		delete_quotes(str, '\"');
	if (str[check_equal_sign(str)] == '\'')
		delete_quotes(str, '\'');
	while (arr[i] != NULL)
		i++;
	rtn = ft_calloc(sizeof(char *), i + 2);
	if (!rtn)
		return (NULL);
	i = 0;
	whileloop_add_var(arr, rtn, str);
	return (rtn);
}

int	ft_export(t_tools *mini, t_simple_cmds *cmd)
{
	char	**tmp;
	int		i;

	i = 1;
	if (!cmd->str[1] || cmd->str[1][0] == '\0')
		mini_env(mini, cmd);
	else
	{
		while (cmd->str[i])
		{
			if (check_parameter(cmd->str[i]) == 0 && variable_exist(mini,
					cmd->str[i]) == 0)
			{
				if (cmd->str[i])
				{
					tmp = add_var(mini->envp, cmd->str[i]);
					free_arr(mini->envp);
					mini->envp = tmp;
				}
			}
			i++;
		}
	}
	return (EXIT_SUCCESS);
}
