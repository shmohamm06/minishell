/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyaseen <wyaseen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:36:09 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/22 17:40:26 by wyaseen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/built_ins.h"
# include "../includes/minishell.h"


int	ft_pwd(t_tools *mini)
{
	ft_putendl_fd(mini->pwd, STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
