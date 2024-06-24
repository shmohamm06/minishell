/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:32:26 by hakaddou          #+#    #+#             */
/*   Updated: 2023/01/20 23:59:53 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// prints the error message to STD ERROR
// passed and returns ret (mainly ret is NULL)
void	*perror_return(char *str, void *ret)
{
	fd_printf(2, "%s", str);
	return (ret);
}

// returns size of linked list
int	return_env_size(t_env *env)
{
	int	i;

	i = 0;
	while (env)
	{
		env = env->next;
		i++;
	}
	return (i);
}

// joins the key in t_env with =
// and then joins it with the value
// needs memory freeing management
char	*join_key_val(char *key, char *value)
{
	char	*str;
	char	*tmp;

	str = ft_strjoin(key, "=");
	tmp = str;
	str = ft_strjoin(str, value);
	free(tmp);
	return (str);
}

// joins key with equals and does
// nothing more, it's only called
// if t_env->value is NULL
char	*join_key_eq(char *key, t_env *env)
{
	char	*str;

	str = ft_strjoin(key, "=");
	free(env->value);
	env->value = NULL;
	return (str);
}

char	**convert_env(t_mini *mini)
{
	t_env	*env;
	char	**s_env;
	int		i;

	env = mini->l_env;
	if (!env)
		return (NULL);
	i = return_env_size(env);
	s_env = ft_calloc(sizeof(char *), i + 1);
	i = 0;
	while (env != NULL)
	{
		if (env->initialised == true)
		{
			if (env->value == NULL)
				s_env[i] = join_key_eq(env->key, env);
			else
				s_env[i] = join_key_val(env->key, env->value);
			i++;
		}
		env = env->next;
	}
	s_env[i] = NULL;
	return (s_env);
}
