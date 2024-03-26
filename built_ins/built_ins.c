/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:34:59 by shmohamm          #+#    #+#             */
/*   Updated: 2024/03/26 09:49:13 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	built_ins_call(char *str)
{
	static void	*builtins[7][2] = {{"echo", ft_echo}, {"cd", ft_cd}, {"pwd",
			ft_pwd}, {"export", ft_export}, {"unset", ft_unset}, {"env",
			ft_env}, {"exit", ft_exit}};
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
