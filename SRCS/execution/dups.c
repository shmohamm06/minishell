/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dups.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:44:38 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/01 14:30:35 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../built_ins/built_ins.h"
#include "execution.h"

int	duplicate_output_fd(t_rdr *rdr)
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

int	duplicate_input_fd(t_rdr *rdr)
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

int	duplicate_append_fd(t_rdr *rdr)
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

int	parse_redirections(t_rdr *trdr, t_mini *mini, t_cmd *cmd)
{
	t_rdr	*rdr;
	int		flag;

	flag = 0;
	rdr = trdr;
	if (rdr->e_rdr == OUTPUT)
		flag = duplicate_output_fd(rdr);
	else if (rdr->e_rdr == INPUT)
		flag = duplicate_input_fd(rdr);
	else if (rdr->e_rdr == APPEND)
		flag = duplicate_append_fd(rdr);
	else if (rdr->e_rdr == HEREDOC)
		flag = execute_pipe_heredoc(rdr, mini, cmd);
	return (flag);
}
