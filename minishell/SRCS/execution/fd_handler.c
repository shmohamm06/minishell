/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:30:42 by hakaddou          #+#    #+#             */
/*   Updated: 2023/01/29 19:31:43 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_close(int fd, int limit, t_cmd *cmd)
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

void	close_all_fds(t_mini *mini)
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
				rdr->dup2_fd = ft_close (rdr->dup2_fd, 3, cmd);
				rdr->fd = ft_close (rdr->fd, 3, cmd);
				rdr->fdpipe[0] = ft_close (rdr->fdpipe[0], 3, cmd);
				rdr->fdpipe[1] = ft_close (rdr->fdpipe[1], 3, cmd);
				rdr->og_fd = ft_close (rdr->og_fd, 3, cmd);
				rdr = rdr->next;
			}
		}
		cmd = cmd->next;
	}
}
