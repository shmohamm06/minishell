/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:46:26 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/01 13:58:17 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "built_ins.h"
#include "../execution/execution.h"

int	is_valid_identifier_export(char *arg)
{
	int		i;
	size_t	d;

	d = 0;
	i = -1;
	if ((arg[0] && ft_isdigit(arg[0])))
		return (1);
	while (arg[++i] != '\0' && arg[i])
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			d++;
	if (d)
		return (1);
	else
		return (0);
}

int	should_unset_arg(char *arg)
{
	if (!arg || !arg[0] || is_valid_identifier_export(arg))
	{
		g_exit_code = UNSET_FLAG;
		return (1);
	}
	return (0);
}

void	free_env_node(t_env *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

void	delete_env_list(char *arg, t_mini *mini)
{
	t_env	*temp;
	t_env	*prev;

	if (!mini->l_env)
		return ;
	temp = mini->l_env;
	if (temp != NULL && ft_strncmp(temp->key, arg, ft_strlen(arg) + 1) == 0)
	{
		mini->l_env = temp->next;
		free_env_node(temp);
		return ;
	}
	while (temp != NULL && ft_strncmp(arg, temp->key, ft_strlen(arg) + 1))
	{
		prev = temp;
		temp = temp->next;
	}
	if (!temp)
	{
		printf("%s not found\n", arg);
		return ;
	}
	printf("%s found and deleted\n", arg);
	prev->next = temp->next;
	free_env_node(temp);
}

void	ft_unset(char **args, t_mini *mini)
{
	int		i;

	i = 0;
	if (!args[0])
	{
		g_exit_code = SUCCESS;
		return ;
	}
	while (args[i] != NULL)
	{
		if (should_unset_arg(args[i]))
			fd_printf(2, "minishell: unset: `%s': not a valid identifier\n",
				args[i]);
		else
			delete_env_list(args[i], mini);
		i++;
	}
	if (g_exit_code == UNSET_FLAG)
		g_exit_code = UNSET_FAIL_CODE;
	else
		g_exit_code = SUCCESS;
}
