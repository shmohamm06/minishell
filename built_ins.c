/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 23:10:10 by shmohamm          #+#    #+#             */
/*   Updated: 2024/03/26 23:12:03 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	(*builtin_arr(char *str))(t_data *mini)
{
	static void	*builtins[7][2] = {{"echo", ft_echo}, {"cd", ft_cd}, {"pwd",
		ft_pwd}, {"env", ft_env}};
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
