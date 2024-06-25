/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:46:12 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/25 10:51:07 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "built_ins.h"

void	print_echo(char **args, int flag)
{
	int	i;

	i = 0;
	if (!args[0])
		return ;
	while (args[i + 1] != NULL)
	{
		fd_printf(1, "%s ", args[i]);
		i++;
	}
	fd_printf(1, "%s", args[i]);
	if (flag == 0)
		fd_printf(1, "\n");
}

int	check_n_options(char *arg, int *flag)
{
	int		i;
	size_t	counter;

	counter = 0;
	i = 1;
	if (arg[0] == '-' && arg[1])
	{
		while (arg[i] != '\0')
		{
			if (arg[i] == 'n')
				counter++;
			i++;
		}
		if (counter == ft_strlen(arg + 1))
		{
			*flag += 1;
			return (1);
		}
	}
	return (0);
}

char	**trim_echo_args(char **args, int *flag)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		if (check_n_options(args[i], flag))
			i++;
		else
			return (&args[i]);
	}
	*flag = 0;
	return (&args[i]);
}

//	ft_echo receives the command args and not the command itself
//	ex: echo -n hello world -> receives "-n" "hello" "world"
void	ft_echo(char **args)
{
	int	flag;

	flag = 0;
	if (!args[0])
	{
		fd_printf(1, "\n");
		return ;
	}
	if (0 == ft_strncmp(args[0], "$?", 3))
	{
		printf("exit code is %d\n", g_exit_code);
		g_exit_code = SUCCESS;
		return ;
	}
	args = trim_echo_args(args, &flag);
	print_echo(args, flag);
	g_exit_code = SUCCESS;
}
