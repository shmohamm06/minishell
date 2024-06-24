/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:29:32 by hakaddou          #+#    #+#             */
/*   Updated: 2023/01/16 22:43:24 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// prints the env in special format with
//the uninitialised values
void	print_export(t_mini *mini)
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
		if (env->initialised)
		{
			if (env->value == NULL)
				fd_printf(1, "declare -x %s=\"\"\n", env->key, env->value);
			else
				fd_printf(1, "declare -x %s=\"%s\"\n", env->key, env->value);
		}
		else
			fd_printf(1, "declare -x %s\n", env->key);
		env = env->next;
	}
	g_exit_code = SUCCESS;
}

// it sets the key of the env to whatever is before the 
// first occurance of '='
char	*set_env_key(char *arg)
{
	int		i;
	char	*new_key;

	i = 0;
	while (arg[i] != '\0' && arg[i] != '=')
		i++;
	new_key = ft_calloc(1, i + 1);
	i = 0;
	while (arg[i] != '\0' && arg[i] != '=')
	{
		new_key[i] = arg[i];
		i++;
	}
	new_key[i] = '\0';
	return (new_key);
}

// stes the value of a key to either NULL if there
// is no initialisation with '=' or else to whatever
// after the first occurance of '='
char	*set_env_value(char *arg, t_env *new)
{
	char	*value;

	value = ft_strchr(arg, '=');
	if (value == NULL)
	{
		new->initialised = false;
		return (ft_strdup(""));
	}
	else
	{
		new->initialised = true;
		value++;
		return (ft_strdup(value));
	}
}

// allocates memory for a new node, sets is's
// next to NULL since this should be the last node.
// It also sets the key and value of the
// environmental variables by calling set_value and set_key
// functions. It then itrates to the end of the linked list
// and sets the tail's next to the new node
void	add_to_env(char *arg, t_mini *mini)
{
	t_env	*temp;
	t_env	*new;

	temp = mini->l_env;
	new = ft_calloc(1, sizeof(t_env));
	new->next = NULL;
	new->value = set_env_value(arg, new);
	new->key = set_env_key(arg);
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

// check if export arguments are valid just like
// bash export takes them
// checks if there is no number or '=' then checks
// if the argument before the first = has any white spaces
// or invalid character other than '_'
int	check_valid_identifier(char *arg)
{
	int		i;
	size_t	d;

	d = 0;
	i = -1;
	if ((arg[0] && ft_isdigit(arg[0])) || arg[0] == '=')
		return (1);
	while (arg[++i] != '\0' && arg[i] != '=')
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			d++;
	if (d)
		return (1);
	else
		return (0);
}
