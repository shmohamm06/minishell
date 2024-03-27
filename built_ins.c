/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 23:10:10 by shmohamm          #+#    #+#             */
/*   Updated: 2024/03/27 11:18:14 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_check(char **argv, t_data *mini)
{
	if (argv[1])
	{
		if (ft_strncmp(argv[1], "echo", 5) == 0)
			ft_echo(argv);
		else if (ft_strncmp(argv[1], "cd", 3) == 0)
			ft_cd(mini);
		else if (ft_strncmp(argv[1], "pwd", 4) == 0)
			ft_pwd(mini);
		else if (ft_strncmp(argv[1], "env", 4) == 0)
			ft_env(mini);
	}
	return (0);
}
