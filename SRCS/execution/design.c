/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:44:31 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/01 14:00:29 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../built_ins/built_ins.h"
#include "execution.h"

char	*clrd_line(char *str, char *path)
{
	char	str_cpy[2056];
	char	*tmp;
	char	*s_clr;

	ft_bzero(str_cpy, sizeof(str_cpy));
	if (ft_strncmp(path, "shmohamm", 9) == 0 || ft_strncmp(path, "root",
			5) == 0)
		s_clr = ft_strjoin(str, "~  ");
	else
		s_clr = ft_strjoin(str, path);
	tmp = s_clr;
	s_clr = ft_strjoin(s_clr, "\033[0m ");
	free(tmp);
	ft_strlcpy(str_cpy, s_clr, sizeof(str_cpy));
	free(s_clr);
	return (readline(str_cpy));
}

char	*read_line_colored(void)
{
	char	cwd[2056];
	char	*path;

	ft_bzero(cwd, sizeof(cwd));
	path = getcwd(cwd, sizeof(cwd));
	if (!path)
		return (readline("\033[1;92m  \033[0m"));
	path = ft_strrchr(getcwd(cwd, sizeof(cwd)), '/') + 1;
	if (!path)
		return (readline("\033[1;92m  \033[0m"));
	if (g_exit_code != SUCCESS)
		return (clrd_line("\033[1;92m  ", path));
	return (clrd_line("\033[1;92m  ", path));
}
