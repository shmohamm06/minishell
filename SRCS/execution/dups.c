/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dups.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:23:29 by hakaddou          #+#    #+#             */
/*   Updated: 2023/01/29 15:16:56 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_dup2_output(t_rdr *rdr)
{
	rdr->og_fd = dup(STDOUT_FILENO);
	rdr->fd = open(rdr->file, O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (rdr->fd == -1 || rdr->og_fd == -1)
	{
		fd_printf(2, "minishell: %s: %s\n", rdr->file, strerror(errno));
		return (1);
	}
	rdr->dup2_fd = dup2(rdr->fd, STDOUT_FILENO);
	return (0);
}

int	ft_dup2_input(t_rdr *rdr)
{
	rdr->og_fd = dup(STDIN_FILENO);
	rdr->fd = open(rdr->file, O_RDONLY);
	if (rdr->fd == -1 || rdr->og_fd == -1)
	{
		fd_printf(2, "minishell: %s\n", rdr->file, strerror(errno));
		return (1);
	}
	rdr->dup2_fd = dup2(rdr->fd, STDIN_FILENO);
	return (0);
}

int	ft_dup2_append(t_rdr *rdr)
{
	rdr->og_fd = dup(STDOUT_FILENO);
	rdr->fd = open(rdr->file, O_RDWR | O_APPEND, 0644);
	if (rdr->fd == -1 || rdr->og_fd == -1)
	{
		fd_printf(2, "minishell: %s: %s\n", rdr->file, strerror(errno));
		return (1);
	}
	rdr->dup2_fd = dup2(rdr->fd, STDOUT_FILENO);
	return (0);
}

int	parse_dups(t_rdr *trdr, t_mini *mini, t_cmd *cmd)
{
	t_rdr	*rdr;
	int		flag;

	flag = 0;
	rdr = trdr;
	if (rdr->e_rdr == OUTPUT)
		flag = ft_dup2_output(rdr);
	else if (rdr->e_rdr == INPUT)
		flag = ft_dup2_input(rdr);
	else if (rdr->e_rdr == APPEND)
		flag = ft_dup2_append(rdr);
	else if (rdr->e_rdr == HEREDOC)
		flag = ft_pipe_heredoc(rdr, mini, cmd);
	return (flag);
}
