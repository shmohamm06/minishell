/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:14:23 by shmohamm          #+#    #+#             */
/*   Updated: 2024/04/15 13:28:09 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins.h"

int	find_pwd(t_tools *mini)
{
	int	i;

	i = 0;
	while (mini->envp[i])
	{
		if (!ft_strncmp(mini->envp[i], "PWD=", 4))
			mini->pwd = ft_substr(mini->envp[i], 4, ft_strlen(mini->envp[i])
					- 4);
		if (!ft_strncmp(mini->envp[i], "OLDPWD=", 7))
			mini->old_pwd = ft_substr(mini->envp[i], 7, ft_strlen(mini->envp[i])
					- 7);
		i++;
	}
	return (1);
}

void	change_path(t_tools *mini)
{
	char	*tmp;

	find_pwd(mini);
	tmp = ft_strdup(mini->pwd);
	free(mini->old_pwd);
	mini->old_pwd = tmp;
	free(mini->pwd);
	mini->pwd = getcwd(NULL, sizeof(NULL));
}

size_t	check_equal_sign(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*delete_quotes_value(char *str)
{
	char	**split_quotes;

	split_quotes = ft_split(str, '"');
	if (!split_quotes[1])
	{
		free_arr(split_quotes);
		split_quotes = ft_split(str, '\'');
	}
	free(str);
	str = ft_strjoin(split_quotes[0], split_quotes[1]);
	free_arr(split_quotes);
	return (str);
}

int	check_valid_identifier(char c)
{
	return (c == '|' || c == '<' || c == '>' || c == '[' || c == ']'
		|| c == '\'' || c == '\"' || c == ' ' || c == ',' || c == '.'
		|| c == ':' || c == '/' || c == '{' || c == '}' || c == '+' || c == '^'
		|| c == '%' || c == '#' || c == '@' || c == '!' || c == '~' || c == '='
		|| c == '-' || c == '?' || c == '&' || c == '*');
}
