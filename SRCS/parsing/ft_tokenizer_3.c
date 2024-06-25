/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:05:37 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/25 13:07:54 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../built_ins/built_ins.h"
#include "../execution/execution.h"

bool	ft_evalops(t_token *head, t_mini *mini)
{
	t_token	*current;

	current = head;
	if (current->type == PIPE)
	{
		current = head->next;
		if (!current)
			return (false);
		if (current->type == SPACES)
			current = current->next;
		if (!current || current->type == PIPE)
			return (false);
		return (true);
	}
	else
		return (ft_evalrdr(current, mini));
}

bool	ft_evaltokens(t_mini *mini)
{
	t_token	*current;

	current = mini->l_token;
	while (current)
	{
		if (current->type == PIPE || current->type == REDIRECTION)
		{
			if (!ft_evalops(current, mini))
			{
				fd_printf(2, "minishell: syntax error \
near unexpected token\n");
				g_exit_code = 258;
				return (false);
			}
		}
		if (current->type == SINGLE || current->type == DOUBLE)
		{
			if (!ft_strchr(current->content + 1, *current->content))
			{
				fd_printf(2, "minishell: syntax error \
from open quotes\n");
				g_exit_code = 258;
				return (false);
			}
		}
		current = current->next;
	}
	return (true);
}

void	ft_expandvar(t_mini *mini)
{
	t_token	*current;
	t_env	*l_env;

	current = mini->l_token;
	while (current)
	{
		if (current->type == VARIABLE)
		{
			l_env = env_already_exist(current->content + 1, mini);
			current->content[0] = '\0';
			if ((l_env && l_env->initialised) || *(current->content + 1) == '?')
			{
				current->content = (char *)ft_free(current->content);
				if (l_env)
					current->content = ft_strdup(l_env->value);
				else
					current->content = ft_itoa(g_exit_code);
			}
			current->type = WORD;
		}
		current = current->next;
	}
}
