/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyaseen <wyaseen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 23:10:10 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/22 17:40:09 by wyaseen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/built_ins.h"
# include "../includes/minishell.h"


int	(*builtin_arr(char *str))(t_tools *tools, t_simple_cmds *simple_cmd)
{
	static void	*builtins[7][2] = {{"echo", ft_echo}, {"cd", ft_cd},
	{"pwd", ft_pwd}, {"export", ft_export},
	{"unset", ft_unset}, {"env", ft_env}, {"exit", ft_exit}};
	int			i;

	i = 0;
	while (i < 7)
	{
		if (str)
		{
			if (!ft_strncmp(builtins[i][0], str, ft_strlen((builtins[i][0]))))
				return (builtins[i][1]);
		}
		i++;
	}
	return (NULL);
}
