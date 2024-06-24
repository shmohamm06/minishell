/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:58:43 by hakaddou          #+#    #+#             */
/*   Updated: 2023/02/01 15:05:07 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// place holder for check_valid_identifer function
int	check_export_args(char *arg)
{
	if (!arg || !arg[0] || check_valid_identifier(arg))
	{
		g_exit_code = EXPORT_FLAG;
		return (1);
	}
	return (0);
}

// checks if the export key exists and if it does it returns 1
t_env	*env_already_exist(char *arg, t_mini *mini)
{
	t_env	*temp;
	size_t	i;

	i = 0;
	while (arg[i] != '\0' && arg[i] != '=')
		i++;
	temp = mini->l_env;
	while (temp)
	{
		if (0 == ft_strncmp(temp->key, arg, i)
			&& ft_strlen(temp->key) == i)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

// after validating that the env variable already exists,
// it looks for the node with the key and modifies it if
// there is '=' or else it just returns
void	ft_modify_env(char *arg, t_mini *mini)
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
		if (0 == ft_strncmp(temp->key, arg, i)
			&& ft_strlen(temp->key) == i)
			break ;
		temp = temp->next;
	}
	free (temp->value);
	new_key++;
	temp->initialised = true;
	temp->value = ft_strdup(new_key);
}

// checks if the export argument already exists as key or
// it should be added
void	parse_new_export(char *arg, t_mini *mini)
{
	if (!env_already_exist(arg, mini))
		add_to_env(arg, mini);
	else
		ft_modify_env(arg, mini);
}

// if there are no arguemnts passed then it only prints
// the env variables whether initialised or not
// and if there are arguemnts it loops to each one
// and checks for validity, if it is not valid it
// skips the argument and moves to the next one
void	ft_export(char **args, t_mini *mini)
{
	int		i;

	i = -1;
	if (!mini->l_env)
	{
		fd_printf(2, "export: permission denied\n");
		return ;
	}
	if (!args[0])
	{
		print_export(mini);
		return ;
	}
	while (args[++i] != NULL)
	{
		if (check_export_args(args[i]))
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
