/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 07:09:55 by hakaddou          #+#    #+#             */
/*   Updated: 2023/01/22 11:47:36 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*clrd_line(char *str, char *path)
{
	char	str_cpy[2056];
	char	*tmp;
	char	*s_clr;

	ft_bzero(str_cpy, sizeof(str_cpy));
	if (ft_strncmp(path, "hakaddou", 9) == 0
		|| ft_strncmp(path, "root", 5) == 0)
		s_clr = ft_strjoin(str, "~  ");
	else
		s_clr = ft_strjoin(str, path);
	tmp = s_clr;
	s_clr = ft_strjoin(s_clr, " ✗ \033[0m ");
	free (tmp);
	ft_strlcpy(str_cpy, s_clr, sizeof(str_cpy));
	free (s_clr);
	return (readline(str_cpy));
}

char	*read_line_colored2(int random, char *path)
{
	if (random == PURPLE)
		return (clrd_line("\033[1;92m➜\033[1;35m  ", path));
	else if (random == DARK_CYAN)
		return (clrd_line("\033[1;92m➜\033[1;36m  ", path));
	else
		return (clrd_line("\033[1;92m➜\033[1;94m  ", path));
}

char	*read_line_colored(int random)
{
	char	cwd[2056];
	char	*path;

	ft_bzero(cwd, sizeof(cwd));
	path = getcwd(cwd, sizeof(cwd));
	if (!path)
		return (readline("\033[1;31m➜\033[1;35m  \033[0m"));
	path = ft_strrchr(getcwd(cwd, sizeof(cwd)), '/') + 1;
	if (!path)
		return (readline("\033[1;31m➜\033[1;35m  \033[0m"));
	if (g_exit_code != SUCCESS)
		return (clrd_line("\033[1;31m➜  ", path));
	if (random == BLUE)
		return (clrd_line("\033[1;92m➜\033[1;34m  ", path));
	else if (random == WHITE)
		return (clrd_line("\033[1;92m➜\033[1;37m  ", path));
	else if (random == YELLOW)
		return (clrd_line("\033[1;92m➜\033[1;33m  ", path));
	else if (random == GREEN)
		return (clrd_line("\033[1;92m➜\033[1;32m  ", path));
	else
		return (read_line_colored2(random, path));
}
