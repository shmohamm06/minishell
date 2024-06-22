/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:36:09 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/22 11:20:30 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/built_ins.h"

int	ft_pwd(t_tools *mini)
{
	ft_putendl_fd(mini->pwd, STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
