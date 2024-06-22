/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyaseen <wyaseen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:52:40 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/22 17:39:59 by wyaseen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/errors_and_utils.h"
# include "../includes/minishell.h"


size_t	dollar_sign(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*char_to_str(char c)
{
	char	*str;

	str = ft_calloc(sizeof(char), 2);
	str[0] = c;
	return (str);
}

int	after_dol_lenght(char *str, int j)
{
	int	i;

	i = j + 1;
	while (str[i] != '\0' && str[i] != '$' && str[i] != ' ' && str[i] != '\"'
		&& str[i] != '\'' && str[i] != '=' && str[i] != '-' && str[i] != ':')
		i++;
	return (i);
}

size_t	quotes_lenght(char *str)
{
	int		i;
	size_t	ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			ret++;
		}
		i++;
	}
	return (ret);
}

int	question_mark(char **tmp)
{
	free(*tmp);
	*tmp = ft_itoa(g_global.error_num);
	return (ft_strlen(*tmp) + 1);
}
