/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:46:22 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/01 14:37:08 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../execution/execution.h"
#include "built_ins.h"

int	is_valid_export_arg(char *arg)
{
	if (!arg || !arg[0] || is_valid_identifier(arg))
	{
		g_exit_code = EXPORT_FLAG;
		return (1);
	}
	return (0);
}

t_env	*find_env_variable(char *arg, t_mini *mini)
{
	t_env	*temp;
	size_t	i;

	i = 0;
	while (arg[i] != '\0' && arg[i] != '=')
		i++;
	temp = mini->l_env;
	while (temp)
	{
		if (0 == ft_strncmp(temp->key, arg, i) && ft_strlen(temp->key) == i)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

void	update_env_variable(char *arg, t_mini *mini)
{
	t_env	*temp;
	char	*new_key;
	size_t	i;

	new_key = ft_strchr(arg, '=');
	if (new_key == NULL)
		return ;
	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	temp = mini->l_env;
	while (temp)
	{
		if (0 == ft_strncmp(temp->key, arg, i) && ft_strlen(temp->key) == i)
			break ;
		temp = temp->next;
	}
	free(temp->value);
	new_key++;
	temp->initialised = true;
	temp->value = ft_strdup(new_key);
}

void	parse_new_export(char *arg, t_mini *mini)
{
	if (!find_env_variable(arg, mini))
		add_env_variable(arg, mini);
	else
		update_env_variable(arg, mini);
}

void	ft_export(char **args, t_mini *mini)
{
	int	i;

	i = -1;
	if (!mini->l_env)
	{
		fd_printf(2, "export: permission denied\n");
		return ;
	}
	if (!args[0])
	{
		print_export_list(mini);
		return ;
	}
	while (args[++i] != NULL)
	{
		if (is_valid_export_arg(args[i]))
			fd_printf(2, "minishell: export: `%s': not a valid identifier\n",
					args[i]);
		else
			parse_new_export(args[i], mini);
	}
	if (g_exit_code == EXPORT_FLAG)
		g_exit_code = EXPORT_FAIL_CODE;
	else
		g_exit_code = 0;
}
