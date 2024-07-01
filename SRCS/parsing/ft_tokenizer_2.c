/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:03:58 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/01 15:28:32 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../built_ins/built_ins.h"
#include "../execution/execution.h"

void	concatenate_token(t_token_groups *groups, t_token *current)
{
	char	*group_ptrs[7];

	group_ptrs[0] = NULL;
	group_ptrs[1] = groups->single;
	group_ptrs[2] = groups->doubleq;
	group_ptrs[3] = groups->variable;
	group_ptrs[4] = groups->redirection;
	group_ptrs[5] = groups->pipe;
	group_ptrs[6] = groups->word;
	if (current->type >= SINGLE && current->type <= WORD)
	{
		strcat(group_ptrs[current->type], current->content);
		strcat(group_ptrs[current->type], " ");
	}
}

void	remove_middle_node(t_token **list, t_token *node)
{
	if (*list == NULL || node == NULL)
		return ;
	if (node->prev != NULL)
		node->prev->next = node->next;
	if (node->next != NULL)
		node->next->prev = node->prev;
	if (*list == node)
		*list = node->next;
	node->prev = NULL;
	node->next = NULL;
	free_token_list(node);
}

bool	evaluate_variable(char *name, t_mini *mini)
{
	char	**split;
	size_t	count_words;
	t_env	*env;

	count_words = 0;
	env = find_env_variable(name, mini);
	if (!env || !env->initialised)
		return (false);
	if (env && env->initialised)
	{
		split = ft_split(env->value, ' ');
		while (split[count_words])
			count_words++;
		ft_free_split(split);
	}
	if (count_words != 1)
		return (false);
	else
		return (true);
}

bool	evaluate_redirection(t_token *head, t_mini *mini)
{
	t_token	*current;

	current = head->next;
	if (!current)
		return (false);
	if (current->type == SPACES)
		current = current->next;
	if (!current || current->type == PIPE || current->type == REDIRECTION)
		return (false);
	while (current && current->type != SPACES && current->type != PIPE
		&& current->type != REDIRECTION)
	{
		if (current->type == VARIABLE)
			if (!evaluate_variable(current->content, mini))
				return (false);
		current = current->next;
	}
	return (true);
}
