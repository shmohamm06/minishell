/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_srcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:46:43 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/01 14:50:34 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../built_ins/built_ins.h"
#include "execution.h"

void	close_redirector_files(t_mini *mini, t_cmd *cmd)
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
				exit_shell(mini, errno, strerror(errno), 2);
			else
				rdr->fd = -2;
		}
		rdr = rdr->next;
	}
}

int	handle_error_set_print_close(t_mini *mini, t_cmd *cmd, int error)
{
	g_exit_code = error;
	fd_printf(2, "minishell: %s\n", strerror(errno));
	close_redirector_files(mini, cmd);
	return (1);
}

void	close_file_descriptor_rdr_backv2(t_rdr *ordr, t_rdr *irdr)
{
	if (ordr)
	{
		ordr->dup2_fd = close_file_descriptor(ordr->dup2_fd, 3, NULL);
		dup2(ordr->og_fd, STDOUT_FILENO);
		ordr->og_fd = close_file_descriptor(ordr->og_fd, 3, NULL);
		ordr->fd = close_file_descriptor(ordr->fd, 3, NULL);
	}
	if (irdr)
	{
		if (irdr->e_rdr == HEREDOC)
		{
			irdr->dup2_fd = close_file_descriptor(irdr->dup2_fd, 3, NULL);
			irdr->fdpipe[0] = close_file_descriptor(irdr->fdpipe[0], 3, NULL);
			dup2(irdr->og_fd, STDIN_FILENO);
			irdr->og_fd = close_file_descriptor(irdr->og_fd, 3, NULL);
		}
		else
		{
			irdr->dup2_fd = close_file_descriptor(irdr->dup2_fd, 3, NULL);
			dup2(irdr->og_fd, STDIN_FILENO);
			irdr->og_fd = close_file_descriptor(irdr->og_fd, 3, NULL);
			irdr->fd = close_file_descriptor(irdr->fd, 3, NULL);
		}
	}
}

void	close_redirector_back(t_cmd *cmd)
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
	close_file_descriptor_rdr_backv2(ordr, irdr);
}
