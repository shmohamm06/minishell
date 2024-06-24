/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_srcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:20:47 by hakaddou          #+#    #+#             */
/*   Updated: 2023/01/29 19:03:26 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	close_rdr_files(t_mini *mini, t_cmd *cmd)
{
	t_rdr	*rdr;
	int		fd;

	rdr = cmd->rdr;
	while (rdr)
	{
		if (rdr->fd > 2)
		{
			fd = close(rdr->fd);
			if (fd != 0)
				ft_exit_shell(mini, errno, strerror(errno), 2);
			else
				rdr->fd = -2;
		}
		rdr = rdr->next;
	}
}

int	error_set_print_close(t_mini *mini, t_cmd *cmd, int error)
{
	g_exit_code = error;
	fd_printf (2, "minishell: %s\n", strerror(errno));
	close_rdr_files(mini, cmd);
	return (1);
}

void	ft_close_rdr_backv2(t_rdr *ordr, t_rdr *irdr)
{
	if (ordr)
	{
		ordr->dup2_fd = ft_close(ordr->dup2_fd, 3, NULL);
		dup2(ordr->og_fd, STDOUT_FILENO);
		ordr->og_fd = ft_close(ordr->og_fd, 3, NULL);
		ordr->fd = ft_close(ordr->fd, 3, NULL);
	}
	if (irdr)
	{
		if (irdr->e_rdr == HEREDOC)
		{
			irdr->dup2_fd = ft_close (irdr->dup2_fd, 3, NULL);
			irdr->fdpipe[0] = ft_close (irdr->fdpipe[0], 3, NULL);
			dup2(irdr->og_fd, STDIN_FILENO);
			irdr->og_fd = ft_close (irdr->og_fd, 3, NULL);
		}
		else
		{
			irdr->dup2_fd = ft_close(irdr->dup2_fd, 3, NULL);
			dup2(irdr->og_fd, STDIN_FILENO);
			irdr->og_fd = ft_close(irdr->og_fd, 3, NULL);
			irdr->fd = ft_close(irdr->fd, 3, NULL);
		}
	}
}

void	close_rdr_back(t_cmd *cmd)
{
	t_rdr	*rdr;
	t_rdr	*ordr;
	t_rdr	*irdr;

	rdr = cmd->rdr;
	ordr = NULL;
	irdr = NULL;
	if (!cmd || !cmd->rdr)
		return ;
	while (rdr)
	{
		if (rdr->e_rdr == OUTPUT || rdr->e_rdr == APPEND)
			ordr = rdr;
		if (rdr->e_rdr == INPUT || rdr->e_rdr == HEREDOC)
			irdr = rdr;
		rdr = rdr->next;
	}
	ft_close_rdr_backv2(ordr, irdr);
}
