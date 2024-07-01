/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:45:58 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/01 14:22:06 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../built_ins/built_ins.h"
#include "execution.h"

int	close_file_descriptor(int fd, int limit, t_cmd *cmd)
{
	int	ret;

	if (fd >= limit)
	{
		ret = close(fd);
		if (ret == -1)
		{
			if (cmd && cmd->arg[0])
				fd_printf(2, "error closing fd %d in %s\n", fd, cmd->arg[0]);
			else
				fd_printf(2, "error closing fd %d\n", fd);
		}
		else
			return (-2);
	}
	return (-2);
}

void	close_all_file_descriptors(t_mini *mini)
{
	t_cmd	*cmd;
	t_rdr	*rdr;

	cmd = mini->l_cmd;
	while (cmd)
	{
		rdr = cmd->rdr;
		if (rdr)
		{
			while (rdr)
			{
				rdr->dup2_fd = close_file_descriptor(rdr->dup2_fd, 3, cmd);
				rdr->fd = close_file_descriptor(rdr->fd, 3, cmd);
				rdr->fdpipe[0] = close_file_descriptor(rdr->fdpipe[0], 3, cmd);
				rdr->fdpipe[1] = close_file_descriptor(rdr->fdpipe[1], 3, cmd);
				rdr->og_fd = close_file_descriptor(rdr->og_fd, 3, cmd);
				rdr = rdr->next;
			}
		}
		cmd = cmd->next;
	}
}
