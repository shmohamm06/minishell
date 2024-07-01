/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:52:53 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/01 15:20:59 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../built_ins/built_ins.h"
#include "../execution/execution.h"

int	init_args_and_rdr(t_mini *mini, t_cmd *cmd, char **token)
{
	int	i[2];

	i[0] = 0;
	i[1] = 0;
	cmd->arg = (char **)ft_calloc(count_till_pipe(token), sizeof(char *));
	cmd->fd_pipe[0] = -2;
	cmd->fd_pipe[1] = -2;
	if (!cmd->arg)
		exit_shell(mini, 137, "malloc fail", 2);
	populate_cmd(mini, cmd, token, i);
	return (i[0]);
}

void	parse_tokens(t_mini *mini, char **token)
{
	t_cmd	*cmd_new;
	t_cmd	*cmd_tail;

	mini->l_cmd = NULL;
	while (*token)
	{
		cmd_new = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
		if (!cmd_new)
			exit_shell(mini, 137, "malloc fail", 2);
		token += init_args_and_rdr(mini, cmd_new, token);
		cmd_new->next = NULL;
		if (mini->l_cmd == NULL)
			mini->l_cmd = cmd_new;
		else
			cmd_tail->next = cmd_new;
		cmd_tail = cmd_new;
		if (*token)
			if (!ft_strncmp(*token, "|", 2))
				token++;
	}
}
