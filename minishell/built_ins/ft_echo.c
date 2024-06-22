/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyaseen <wyaseen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:40:21 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/22 17:40:18 by wyaseen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/built_ins.h"
# include "../includes/minishell.h"


void	print_input_string(int i, char **str, int out)
{
	while (str[i])
	{
		ft_putstr_fd(str[i++], out);
		if (str[i])
			ft_putchar_fd(' ', out);
	}
}

int	ft_echo(t_simple_cmds *cmd)
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	flag = -1;
	while (cmd->str[i] && cmd->str[i][0] == '-' && cmd->str[i][1] == 'n')
	{
		j = 1;
		while (cmd->str[i][j] == 'n')
			j++;
		if (cmd->str[i][j] == '\0')
			flag = 1;
		else
			break ;
		i++;
	}
	print_input_string(i, cmd->str, STDOUT_FILENO);
	if (flag == -1)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
