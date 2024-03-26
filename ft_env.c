/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:17:44 by shmohamm          #+#    #+#             */
/*   Updated: 2024/03/26 22:35:09 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_data *mini)
{
	int	i;

	i = 0;
	while (mini->en_var[i])
	{
		ft_putendl_fd(mini->en_var[i], STDOUT_FILENO);
		i++;
	}
	return (EXIT_SUCCESS);
}
