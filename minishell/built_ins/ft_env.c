/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:17:44 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/23 11:00:53 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_env(t_tools *mini)
{
	int	i;

	i = 0;
	while (mini->envp[i])
	{
		ft_putendl_fd(mini->envp[i], STDOUT_FILENO);
		i++;
	}
	return (EXIT_SUCCESS);
}
