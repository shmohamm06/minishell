/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:36:09 by shmohamm          #+#    #+#             */
/*   Updated: 2024/03/31 11:20:12 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins.h"

int	ft_pwd(t_tools *mini)
{
	ft_putendl_fd(mini->pwd, STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
