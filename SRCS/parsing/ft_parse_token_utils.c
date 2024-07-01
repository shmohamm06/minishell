/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:52:49 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/01 15:19:49 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../built_ins/built_ins.h"
#include "../execution/execution.h"

int	is_redirection(char *string)
{
	if (!ft_strncmp(string, "<", 2))
		return (INPUT);
	else if (!ft_strncmp(string, ">", 2))
		return (OUTPUT);
	else if (!ft_strncmp(string, "<<", 3))
		return (HEREDOC);
	else if (!ft_strncmp(string, ">>", 3))
		return (APPEND);
	else
		return (NONE);
}

t_rdr	*get_rdr_tail(t_rdr *rdr_head)
{
	t_rdr	*rdr_tail;

	rdr_tail = rdr_head;
	while (rdr_tail && rdr_tail->next)
		rdr_tail = rdr_tail->next;
	return (rdr_tail);
}

int	count_till_pipe(char **token)
{
	int	flag;
	int	count;

	count = 0;
	flag = false;
	while (*token && ft_strncmp(*token, "|", 2))
	{
		if (!is_redirection(*token))
		{
			if (flag == false)
				count++;
			flag = false;
		}
		else
			flag = true;
		token++;
		if (token == NULL)
			break ;
	}
	count++;
	return (count);
}

t_rdr	*add_to_rdr_list(t_rdr *rdr_head, char **token, int *i, t_mini *mini)
{
	t_rdr	*rdr_new;
	t_rdr	*rdr_tail;

	rdr_tail = get_rdr_tail(rdr_head);
	rdr_new = (t_rdr *) ft_calloc(1, sizeof(t_rdr));
	rdr_new->fd = -2;
	rdr_new->og_fd = -2;
	rdr_new->dup2_fd = -2;
	rdr_new->fdpipe[0] = -2;
	rdr_new->fdpipe[1] = -2;
	if (!rdr_new)
		exit_shell(mini, 137, "Allocation failure\n", 2);
	rdr_new->e_rdr = is_redirection(token[(i[0])++]);
	rdr_new->file = ft_strdup(token[i[0]]);
	if (!rdr_new->file)
		exit_shell(mini, 137, "Allocation failure\n", 2);
	rdr_new->next = NULL;
	if (rdr_head == NULL)
		rdr_head = rdr_new;
	else
		rdr_tail->next = rdr_new;
	return (rdr_head);
}

void	populate_cmd(t_mini *mini, t_cmd *cmd, char **token, int i[0])
{
	cmd->rdr = NULL;
	while (token[i[0]] && ft_strncmp(token[i[0]], "|", 2))
	{
		if (is_redirection(token[i[0]]))
			cmd->rdr = add_to_rdr_list(cmd->rdr, token, i, mini);
		else
		{
			cmd->arg[i[1]] = ft_strdup(token[i[0]]);
			if (!cmd->arg[i[1]])
				exit_shell(mini, 137, "Allocation failure\n", 2);
			(i[1])++;
		}
		(i[0])++;
	}
}
