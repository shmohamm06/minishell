/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:40:21 by shmohamm          #+#    #+#             */
/*   Updated: 2024/03/26 22:10:23 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_lines(int i, char **str, int out)
{
	while (str[i])
	{
		ft_putstr_fd(str[i++], out);
		if (str[i])
			ft_putchar_fd(' ', out);
	}
}

int	ft_echo(char **argv)
{
	int	i;
	int	j;
	int	n_option;

	i = 1;
	n_option = -1;
	while (argv[i] && argv[i][0] == '-' && argv[i][1] == 'n')
	{
		j = 1;
		while (argv[i][j] == 'n')
			j++;
		if (argv[i][j] == '\0')
			n_option = 1;
		else
			break ;
		i++;
	}
	print_lines(i, argv, STDOUT_FILENO);
	if (n_option == -1)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
