/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:44:45 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/09 12:03:35 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../built_ins/built_ins.h"
#include "execution.h"

void	*print_error_return(char *str, void *ret)
{
	fd_printf(2, "%s", str);
	return (ret);
}

int	get_env_size(t_env *env)
{
	int	size;

	size = 0;
	while (env)
	{
		env = env->next;
		size++;
	}
	return (size);
}

char	*join_key_value(char *key, char *value)
{
	char	*result;
	char	*joined;

	result = ft_strjoin(key, "=");
	joined = ft_strjoin(result, value);
	free(result);
	return (joined);
}

char	*join_key_only(char *key, t_env *env)
{
	char	*str;

	str = ft_strjoin(key, "=");
	free(env->value);
	env->value = NULL;
	return (str);
}

char	**convert_env_to_array(t_mini *mini)
{
	t_env	*env;
	int		size;
	char	**env_array;
	int		index;

	env = mini->l_env;
	if (!env)
		return (NULL);
	size = get_env_size(env);
	env_array = ft_calloc(size + 1, sizeof(char *));
	index = 0;
	while (env)
	{
		if (env->initialised)
		{
			if (env->value == NULL)
				env_array[index] = join_key_only(env->key, env);
			else
				env_array[index] = join_key_value(env->key, env->value);
			index++;
		}
		env = env->next;
	}
	env_array[index] = NULL;
	return (env_array);
}
