/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:46:48 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/01 14:50:34 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../built_ins/built_ins.h"
#include "execution.h"

int	parse_redirect(t_mini *mini, t_cmd *cmd)
{
	t_rdr	*rdr;
	t_rdr	*output_rdr;
	t_rdr	*input_rdr;

	output_rdr = NULL;
	input_rdr = NULL;
	rdr = cmd->rdr;
	while (rdr)
	{
		rdr->fd = close_file_descriptor(rdr->fd, 3, cmd);
		if (rdr->e_rdr == OUTPUT || rdr->e_rdr == APPEND)
			output_rdr = rdr;
		if (rdr->e_rdr == INPUT || rdr->e_rdr == HEREDOC)
			input_rdr = rdr;
		rdr = rdr->next;
	}
	if (output_rdr && parse_redirections(output_rdr, mini, cmd) != 0)
		return (1);
	if (input_rdr && parse_redirections(input_rdr, mini, cmd) != 0)
		return (1);
	mini++;
	return (0);
}

int	handle_nonexistent_file(t_mini *mini, t_rdr *trdr)
{
	t_rdr	*rdr;

	rdr = trdr;
	if (rdr->e_rdr == OUTPUT)
	{
		rdr->fd = open(rdr->file, O_RDWR | O_TRUNC | O_CREAT, 0644);
		if (rdr->fd == -1)
			exit_shell(mini, errno, strerror(errno), 2);
		close(rdr->fd);
		rdr->fd = -1;
	}
	else if (rdr->e_rdr == APPEND)
	{
		rdr->fd = open(rdr->file, O_RDWR | O_APPEND | O_CREAT, 0644);
		if (rdr->fd == -1)
			exit_shell(mini, errno, strerror(errno), 2);
		close(rdr->fd);
		rdr->fd = -1;
	}
	else if (rdr->e_rdr == INPUT)
		return (1);
	return (0);
}

int	return_redirect_error_code(t_rdr *rdr)
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

int	check_file_permissions(t_mini *mini, t_rdr *trdr)
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
				exit_shell(mini, errno, strerror(errno), 2);
			rdr->fd = close(rdr->fd);
			if (rdr->fd == -1)
				exit_shell(mini, errno, strerror(errno), 2);
			rdr->fd = -2;
		}
	}
	else
		return (return_redirect_error_code(rdr));
	return (0);
}

int	handle_redirect(t_mini *mini, t_cmd *cmd)
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
			flag = handle_nonexistent_file(mini, rdr);
		else if (rdr->e_rdr != HEREDOC && check_file_permissions(mini, rdr))
			flag = 1;
		rdr = rdr->next;
	}
	if (flag != 0)
		g_exit_code = handle_error_set_print_close(mini, cmd, 1);
	else
		g_exit_code = parse_redirect(mini, cmd);
	return (g_exit_code);
}
