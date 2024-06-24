/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:20:52 by hakaddou          #+#    #+#             */
/*   Updated: 2023/01/29 18:47:50 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	parse_redirect(t_mini *mini, t_cmd *cmd)
{
	t_rdr	*rdr;
	t_rdr	*ordr;
	t_rdr	*irdr;

	ordr = NULL;
	irdr = NULL;
	rdr = cmd->rdr;
	while (rdr)
	{
		rdr->fd = ft_close(rdr->fd, 3, cmd);
		if (rdr->e_rdr == OUTPUT || rdr->e_rdr == APPEND)
			ordr = rdr;
		if (rdr->e_rdr == INPUT || rdr->e_rdr == HEREDOC)
			irdr = rdr;
		rdr = rdr->next;
	}
	if (ordr)
		if (parse_dups(ordr, mini, cmd) != 0)
			return (1);
	if (irdr)
		if (parse_dups(irdr, mini, cmd) != 0)
			return (1);
	mini++;
	return (0);
}

int	file_no_exist(t_mini *mini, t_rdr *trdr)
{
	t_rdr	*rdr;

	rdr = trdr;
	if (rdr->e_rdr == OUTPUT)
	{
		rdr->fd = open(rdr->file, O_RDWR | O_TRUNC | O_CREAT, 0644);
		if (rdr->fd == -1)
			ft_exit_shell(mini, errno, strerror(errno), 2);
		close (rdr->fd);
		rdr->fd = -1;
	}
	else if (rdr->e_rdr == APPEND)
	{
		rdr->fd = open(rdr->file, O_RDWR | O_APPEND | O_CREAT, 0644);
		if (rdr->fd == -1)
			ft_exit_shell(mini, errno, strerror(errno), 2);
		close (rdr->fd);
		rdr->fd = -1;
	}
	else if (rdr->e_rdr == INPUT)
		return (1);
	return (0);
}

int	ft_return_redirect_code(t_rdr *rdr)
{
	if (rdr->e_rdr == INPUT)
	{
		if (access(rdr->file, R_OK) != 0)
			return (1);
	}
	else if (rdr->e_rdr == APPEND)
	{
		if (access(rdr->file, W_OK) != 0)
			return (1);
	}
	return (0);
}

int	check_file_rights(t_mini *mini, t_rdr *trdr)
{
	t_rdr	*rdr;

	rdr = trdr;
	if (rdr->e_rdr == OUTPUT)
	{
		if (access(rdr->file, W_OK) != 0)
			return (1);
		else
		{
			rdr->fd = open(rdr->file, O_RDWR | O_TRUNC, 0644);
			if (rdr->fd == -1)
				ft_exit_shell(mini, errno, strerror(errno), 2);
			rdr->fd = close (rdr->fd);
			if (rdr->fd == -1)
				ft_exit_shell(mini, errno, strerror(errno), 2);
			rdr->fd = -2;
		}
	}
	else
		return (ft_return_redirect_code(rdr));
	return (0);
}

int	ft_redirect(t_mini *mini, t_cmd *cmd)
{
	t_rdr	*rdr;
	int		flag;

	flag = 0;
	rdr = cmd->rdr;
	if (rdr == NULL)
		return (0);
	while (rdr != NULL && flag == 0)
	{
		if (rdr->e_rdr != HEREDOC && access(rdr->file, F_OK) != EXIST)
			flag = file_no_exist(mini, rdr);
		else if (rdr->e_rdr != HEREDOC && check_file_rights(mini, rdr))
			flag = 1;
		rdr = rdr->next;
	}
	if (flag != 0)
		g_exit_code = error_set_print_close(mini, cmd, 1);
	else
		g_exit_code = parse_redirect(mini, cmd);
	return (g_exit_code);
}
